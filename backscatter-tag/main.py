import backscatter_tag
import time, machine
from machine import Pin

delay_sleep = 5000
Pin_LED = 26

backscatter_tag.setup_BT()
LED = Pin(Pin_LED, Pin.OUT)
LED.value(0)

message = "Hello Je backscatte, tout va bien et toi ça va?"
print("Payload size :",len(message))

while (1):
    backscatter_tag.send_BT(message)
    print(message)
    LED.value(1)
    time.sleep_ms(50)
    LED.value(0)
    machine.lightsleep(int(delay_sleep) - 50)
