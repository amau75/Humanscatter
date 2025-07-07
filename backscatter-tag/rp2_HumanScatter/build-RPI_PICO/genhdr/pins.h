
#define pin_GPIO0 (&machine_pin_obj_table[0])
#define pin_GP0 pin_GPIO0

#define pin_GPIO1 (&machine_pin_obj_table[1])
#define pin_GP1 pin_GPIO1

#define pin_GPIO2 (&machine_pin_obj_table[2])
#define pin_GP2 pin_GPIO2

#define pin_GPIO3 (&machine_pin_obj_table[3])
#define pin_GP3 pin_GPIO3

#define pin_GPIO4 (&machine_pin_obj_table[4])
#define pin_GP4 pin_GPIO4

#define pin_GPIO5 (&machine_pin_obj_table[5])
#define pin_GP5 pin_GPIO5

#define pin_GPIO6 (&machine_pin_obj_table[6])
#define pin_GP6 pin_GPIO6

#define pin_GPIO7 (&machine_pin_obj_table[7])
#define pin_GP7 pin_GPIO7

#define pin_GPIO8 (&machine_pin_obj_table[8])
#define pin_GP8 pin_GPIO8

#define pin_GPIO9 (&machine_pin_obj_table[9])
#define pin_GP9 pin_GPIO9

#define pin_GPIO10 (&machine_pin_obj_table[10])
#define pin_GP10 pin_GPIO10

#define pin_GPIO11 (&machine_pin_obj_table[11])
#define pin_GP11 pin_GPIO11

#define pin_GPIO12 (&machine_pin_obj_table[12])
#define pin_GP12 pin_GPIO12

#define pin_GPIO13 (&machine_pin_obj_table[13])
#define pin_GP13 pin_GPIO13

#define pin_GPIO14 (&machine_pin_obj_table[14])
#define pin_GP14 pin_GPIO14

#define pin_GPIO15 (&machine_pin_obj_table[15])
#define pin_GP15 pin_GPIO15

#define pin_GPIO16 (&machine_pin_obj_table[16])
#define pin_GP16 pin_GPIO16

#define pin_GPIO17 (&machine_pin_obj_table[17])
#define pin_GP17 pin_GPIO17

#define pin_GPIO18 (&machine_pin_obj_table[18])
#define pin_GP18 pin_GPIO18

#define pin_GPIO19 (&machine_pin_obj_table[19])
#define pin_GP19 pin_GPIO19

#define pin_GPIO20 (&machine_pin_obj_table[20])
#define pin_GP20 pin_GPIO20

#define pin_GPIO21 (&machine_pin_obj_table[21])
#define pin_GP21 pin_GPIO21

#define pin_GPIO22 (&machine_pin_obj_table[22])
#define pin_GP22 pin_GPIO22

#define pin_GPIO23 (&machine_pin_obj_table[23])

#define pin_GPIO24 (&machine_pin_obj_table[24])

#define pin_GPIO25 (&machine_pin_obj_table[25])
#define pin_GP25 pin_GPIO25
#define pin_LED pin_GPIO25

#define pin_GPIO26 (&machine_pin_obj_table[26])
#define pin_GP26 pin_GPIO26

#define pin_GPIO27 (&machine_pin_obj_table[27])
#define pin_GP27 pin_GPIO27

#define pin_GPIO28 (&machine_pin_obj_table[28])
#define pin_GP28 pin_GPIO28

#define pin_GPIO29 (&machine_pin_obj_table[29])

#if (MICROPY_HW_PIN_EXT_COUNT > 0)
#define pin_EXT_GPIO0 (&pin_EXT_GPIO0_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 1)
#define pin_EXT_GPIO1 (&pin_EXT_GPIO1_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 2)
#define pin_EXT_GPIO2 (&pin_EXT_GPIO2_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 3)
#define pin_EXT_GPIO3 (&pin_EXT_GPIO3_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 4)
#define pin_EXT_GPIO4 (&pin_EXT_GPIO4_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 5)
#define pin_EXT_GPIO5 (&pin_EXT_GPIO5_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 6)
#define pin_EXT_GPIO6 (&pin_EXT_GPIO6_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 7)
#define pin_EXT_GPIO7 (&pin_EXT_GPIO7_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 8)
#define pin_EXT_GPIO8 (&pin_EXT_GPIO8_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 9)
#define pin_EXT_GPIO9 (&pin_EXT_GPIO9_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 10)
#define pin_EXT_GPIO10 (&pin_EXT_GPIO10_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 11)
#define pin_EXT_GPIO11 (&pin_EXT_GPIO11_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 12)
#define pin_EXT_GPIO12 (&pin_EXT_GPIO12_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 13)
#define pin_EXT_GPIO13 (&pin_EXT_GPIO13_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 14)
#define pin_EXT_GPIO14 (&pin_EXT_GPIO14_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 15)
#define pin_EXT_GPIO15 (&pin_EXT_GPIO15_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 16)
#define pin_EXT_GPIO16 (&pin_EXT_GPIO16_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 17)
#define pin_EXT_GPIO17 (&pin_EXT_GPIO17_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 18)
#define pin_EXT_GPIO18 (&pin_EXT_GPIO18_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 19)
#define pin_EXT_GPIO19 (&pin_EXT_GPIO19_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 20)
#define pin_EXT_GPIO20 (&pin_EXT_GPIO20_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 21)
#define pin_EXT_GPIO21 (&pin_EXT_GPIO21_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 22)
#define pin_EXT_GPIO22 (&pin_EXT_GPIO22_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 23)
#define pin_EXT_GPIO23 (&pin_EXT_GPIO23_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 24)
#define pin_EXT_GPIO24 (&pin_EXT_GPIO24_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 25)
#define pin_EXT_GPIO25 (&pin_EXT_GPIO25_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 26)
#define pin_EXT_GPIO26 (&pin_EXT_GPIO26_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 27)
#define pin_EXT_GPIO27 (&pin_EXT_GPIO27_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 28)
#define pin_EXT_GPIO28 (&pin_EXT_GPIO28_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 29)
#define pin_EXT_GPIO29 (&pin_EXT_GPIO29_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 30)
#define pin_EXT_GPIO30 (&pin_EXT_GPIO30_obj)
#endif

#if (MICROPY_HW_PIN_EXT_COUNT > 31)
#define pin_EXT_GPIO31 (&pin_EXT_GPIO31_obj)
#endif
