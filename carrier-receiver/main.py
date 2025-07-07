import time
import machine
import math
from machine import Pin, SPI, ADC, Timer
from picographics import PicoGraphics, DISPLAY_PICO_DISPLAY, PEN_P4

import carrier
import receiver
import display

#================ PINS =============

#GPIO
LED_TX_PIN = 21
LED_RX_PIN = 22

#SPI
SCK = 2
MISO = 4
MOSI = 3
CS_RX_PIN = 5
CS_TX_PIN = 1
GDO0 = 11

#================ VARIABLES  =============

carrier_timeout = 20 #Timer to prevent carrier radio overheating (set in seconds)

#================ FUNCTIONS =============

def set_config_spi_radios():
    spi = machine.SPI(0,
                    baudrate=5 * 1000000,
                    polarity=0,
                    phase=0,
                    bits=8,
                    firstbit=SPI.MSB,
                    sck=SCK,
                    mosi=MOSI,
                    miso=MISO)
    
    CS_RX_status = machine.Pin(CS_RX_PIN, mode=Pin.OUT)
    CS_TX_status = machine.Pin(CS_TX_PIN, mode=Pin.OUT)
    return(spi, CS_RX_status, CS_TX_status)

LED_TX = Pin(LED_TX_PIN, Pin.OUT)
LED_RX = Pin(LED_RX_PIN, Pin.OUT)

#================ MAIN =============

#Setup
display_humanscatter, color = display.setup_screen()
radio, CS_RX, CS_TX = set_config_spi_radios()
carrier.setup_TX(radio, CS_TX)
receiver.setup_RX(radio, CS_RX, GDO0)
time.sleep_us(100)

#receiver.print_registers_RX(radio, CS_RX)

carrier.start_carrier_TX(radio, CS_TX)
LED_TX.value(1)
receiver.start_listen_RX(radio, CS_RX)

receiver.event_RX = "no_reception"
carrier.event_TX = "no_timeout"
cnt = 1
cnt2 = 0

receiver.dummy_message_generator()
carrier.carrier_timer(carrier_timeout)
exit_code = False

#Main Loop
while(1):
    #Receiving Message
    if (receiver.event_RX == "reception"):
        # decode        
        message = receiver.decode_packet_RX(radio,CS_RX,receiver.RX_BUFFER_SIZE,receiver.Message())
        
        LED_RX.value(1)
        time.sleep_ms(50)
        LED_RX.value(0)
        
        if (cnt2 == 0):
            message.data = "Hello je backscatte comment ça va le sang tié un bon toi en vrai je suis pas"
            message.RSSI += 5
        
        if (cnt2 == 1):
            message.data = "Salut je suis Amaury je suis étudiant à RISE je fais des trucs avec des radios"
            message.RSSI += 3
        
        if (cnt2 == 2):
            message.data = "J'adore la Suède c'est vraiment cool ils ont du bons saumons gravlax qui est un peu cher"
            message.RSSI += 8
        
        cnt2 += 1
        if (cnt2 > 2):
            cnt2 = 0
        
        receiver.print_RX(message)
        display.print_msg(display_humanscatter, message, color)
        
        time.sleep_ms(2000)
        receiver.start_listen_RX(radio, CS_RX)
        receiver.event_RX = "no_reception"
        cnt = 1
        
        
    #Not Receiving any messages
    elif (receiver.event_RX == "no_reception"):
        # let the code do its thing
        if (cnt):
            display.print_waiting(display_humanscatter, "WAITING", color)
            cnt = 0
        pass
    
    #Stope Carrier after a set amount of time to prevent overheating
    elif(carrier.event_TX == "timeout"):
        carrier.stop_carrier_TX(radio, CS_TX)
        LED_TX.value(0)
        display.print_carrier_timeout(display_humanscatter, color)
        exit(0)
