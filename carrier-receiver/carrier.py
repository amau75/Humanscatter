import time
#import carrier_receiver
import machine
import math
from machine import Pin, SPI, ADC, Timer

#================ VARIABLES =============

#Print Carrier Radio Configuration
config_prints = False

#Radio Parameters
BAUDRATE = 100000
F_XOSC = 26000000
CARRIER_FEQ = 2450000000

#Values
r_data = 100000
bw = 794444
f_dev = 347222
f_carrier = 6597222

#Strobes
SIDLE = 0x36       #Idle mode of radio
STX = 0x35         #Receive mode of radio
SRES = 0x30	       #Reset radio

#Registers
cc2500_carrier_settings = [
    [0x00, 0x0B],  # CC2500_IOCFG2: GDO2Output Pin Configuration
    [0x02, 0x0C],  # CC2500_IOCFG0: GDO0Output Pin Configuration
    [0x08, 0x12],  # CC2500_PKTCTRL0: Packet Automation Control
    [0x0B, 0x0B],  # CC2500_FSCTRL1: Frequency Synthesizer Control
    [0x0E, 0x3B],  # CC2500_FREQ1: Frequency Control Word, Middle Byte
    [0x0F, 0x13],  # CC2500_FREQ0: Frequency Control Word, Low Byte
    [0x10, 0x78],  # CC2500_MDMCFG4: Modem Configuration
    [0x11, 0x93],  # CC2500_MDMCFG3: Modem Configuration
    [0x12, 0xB0],  # CC2500_MDMCFG2: Modem Configuration
    [0x15, 0x44],  # CC2500_DEVIATN: Modem Deviation Setting
    [0x18, 0x18],  # CC2500_MCSM0: Main Radio Control State Machine Configuration
    [0x19, 0x16],  # CC2500_FOCCFG: Frequency Offset Compensation Configuration
    [0x1B, 0x43],  # CC2500_AGCCTRL2: AGC Control
    [0x22, 0x11],  # CC2500_FREND0: Front End TX configuration
    [0x25, 0x00],  # CC2500_FSCAL1: Frequency Synthesizer Calibration
    [0x26, 0x11]   # CC2500_FSCAL0: Frequency Synthesizer Calibration
]

TX_power = [
    ["-55", 0x00],  #  0
    ["-30", 0x50],  #  1
    ["-28", 0x44],  #  2
    ["-26", 0xC0],  #  3
    ["-24", 0x84],  #  4
    ["-22", 0x81],  #  5
    ["-20", 0x46],  #  6
    ["-18", 0x93],  #  7
    ["-16", 0x55],  #  8
    ["-14", 0x8D],  #  9
    ["-12", 0xC6],  # 10
    ["-10", 0x97],  # 11
    ["-8", 0x6E],   # 12
    ["-6", 0x7F],   # 13
    ["-4", 0xA9],   # 14
    ["-2", 0xBB],   # 15
    ["0", 0xFE],    # 16
    ["+1", 0xFF],   # 17
]

#-------------- SPI functions --------------

def write_strobe_TX(spi, CS, data):
    msg = bytearray()
    msg.append(data)
    CS.value(0)
    spi.write(msg)
    CS.value(1)

def write_register_TX(spi, CS, data):
    msg = bytearray()
    CS.value(0)
    for i in range(len(data)):
        msg.append(data[i][0])
        msg.append(data[i][1])
        spi.write(msg)
        msg = bytearray()
    CS.value(1)

def read_register_TX(spi, CS, address):
    CS.value(0)
    buf = spi.read(2,address + 0x80)
    CS.value(1)
    time.sleep_ms(1)
    msg = [b for b in buf]
    return (msg)

def print_registers_TX(spi, CS):
    buf = bytearray(2)
    for r in range(0x00, 0x2F):  # Range from 0x00 to 0x2E
        CS.value(0)
        buf = spi.read(2,r + 0x80)
        CS.value(1)
        time.sleep_ms(1)
        print(f"{{.address = 0x{r:02X}, .value = 0x{buf[1]:02X}}},")
        
#-------------- setup functions --------------

def set_power_TX(spi, CS, power_value):
    msg = bytearray()
    msg.append((1<<6) | 0x3E)
    msg.append(power_value)
    msg.append(power_value)
    CS.value(0)
    spi.write(msg)
    CS.value(1)
    
def start_carrier_TX(spi, CS):
    write_strobe_TX(spi, CS, STX)

def stop_carrier_TX(spi, CS):
    write_strobe_TX(spi, CS, SIDLE)

def setup_TX(spi, CS):
    write_strobe_TX(spi, CS, SRES)
    time.sleep_us(100)
    write_strobe_TX(spi, CS, SIDLE)
    write_register_TX(spi, CS, cc2500_carrier_settings)
    set_power_TX(spi, CS, TX_power[17][1])
    set_frequency_TX(spi, CS, CARRIER_FEQ)

def set_frequency_TX(spi, CS, frequency):
    write_strobe_TX(spi, CS, SIDLE)
    freq = int(frequency * ((1<<16) / F_XOSC))
    channel = 0
    channspc_e = 0
    channspc_m = int(((frequency * (1 << 16)) / F_XOSC - freq - (1 << 6)) * (1 << 2))
    frequency_calculated = int(F_XOSC * (freq + channel * (256 + channspc_m) / (1 << 2)) / (1 << 16))
    #
    mdmcfg1 = read_register_TX(spi, CS, 0x13)[0];
    msg = [[0x0a, channel],
           [0x0d, ((freq & 0x007f0000)>>16)],
           [0x0e, ((freq & 0x0000ff00)>>8)],
           [0x0f, (freq & 0x000000ff) - 1],
           [0x13, (mdmcfg1 & 0xf0) + (channspc_e & 0X03) + 32],
           [0x14, (channspc_m)]]
    write_register_TX(spi, CS, msg)
    if (config_prints):
        print(f"set TX frequency [{freq} {channel} {channspc_e} {channspc_m}] {frequency_calculated}")
        print("\nset_frequency TX")
        print([f"0x{byte:02X}" for pair in msg for byte in pair])
        print(msg)

def carrier_timer(time_out_carrier):
    timer_carrier = Timer()
    timer_carrier.init(mode=Timer.ONE_SHOT, callback=carrier_event_update, period=time_out_carrier*1000)

def carrier_event_update(timer):
    global event_TX
    event_TX = "timeout"
    