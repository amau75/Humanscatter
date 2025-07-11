// This file was automatically generated by make-pins.py
//
// --af-csv /home/amaury/Pico/micropython/ports/rp2_HumanScatter/boards/rp2_af.csv
// --board-csv /home/amaury/Pico/micropython/ports/rp2_HumanScatter/boards/RPI_PICO/pins.csv
// --prefix /home/amaury/Pico/micropython/ports/rp2_HumanScatter/boards/rp2_prefix.c

#include <stdint.h>
#include "py/obj.h"
#include "py/mphal.h"
#include "extmod/modmachine.h"
#include "machine_pin.h"

#define AF(af_idx, af_fn, af_unit)                      \
    {                                                   \
        .base = { &machine_pin_af_type },               \
        .name = MP_QSTR_##af_fn,                        \
        .idx = (af_idx),                                \
        .fn = GPIO_FUNC_##af_fn,                        \
        .unit = (af_unit),                              \
    }

#if MICROPY_HW_PIN_EXT_COUNT
#define PIN(_id, _name, _is_ext, _af_num, _af_list)     \
    {                                                   \
        .base = { &machine_pin_type },                  \
        .name = MP_QSTR_##_name,                        \
        .id = (uint8_t)(_id),                           \
        .is_ext = (_is_ext),                            \
        .is_output = false,                             \
        .last_output_value = 0,                         \
        .af_num = (_af_num),                            \
        .af = (_af_list),                               \
    }
#else
#define PIN(_id, _name, _is_ext, _af_num, _af_list)     \
    {                                                   \
        .base = { &machine_pin_type },                  \
        .name = MP_QSTR_##_name,                        \
        .id = (uint8_t)(_id),                           \
        .af_num = (_af_num),                            \
        .af = (_af_list),                               \
    }
#endif
const machine_pin_af_obj_t pin_GPIO0_af[] = {
    AF(1, SPI , 0), // SPI0_RX
    AF(2, UART, 0), // UART0_TX
    AF(3, I2C , 0), // I2C0_SDA
    AF(4, PWM , 0), // PWM0_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO1_af[] = {
    AF(1, SPI , 0), // SPI0_CS
    AF(2, UART, 0), // UART0_RX
    AF(3, I2C , 0), // I2C0_SCL
    AF(4, PWM , 0), // PWM0_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO2_af[] = {
    AF(1, SPI , 0), // SPI0_SCK
    AF(2, UART, 0), // UART0_CTS
    AF(3, I2C , 1), // I2C1_SDA
    AF(4, PWM , 1), // PWM1_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO3_af[] = {
    AF(1, SPI , 0), // SPI0_TX
    AF(2, UART, 0), // UART0_RTS
    AF(3, I2C , 1), // I2C1_SCL
    AF(4, PWM , 1), // PWM1_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO4_af[] = {
    AF(1, SPI , 0), // SPI0_RX
    AF(2, UART, 1), // UART1_TX
    AF(3, I2C , 0), // I2C0_SDA
    AF(4, PWM , 2), // PWM2_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO5_af[] = {
    AF(1, SPI , 0), // SPI0_CS
    AF(2, UART, 1), // UART1_RX
    AF(3, I2C , 0), // I2C0_SCL
    AF(4, PWM , 2), // PWM2_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO6_af[] = {
    AF(1, SPI , 0), // SPI0_SCK
    AF(2, UART, 1), // UART1_CTS
    AF(3, I2C , 1), // I2C1_SDA
    AF(4, PWM , 3), // PWM3_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO7_af[] = {
    AF(1, SPI , 0), // SPI0_TX
    AF(2, UART, 1), // UART1_RTS
    AF(3, I2C , 1), // I2C1_SCL
    AF(4, PWM , 3), // PWM3_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO8_af[] = {
    AF(1, SPI , 1), // SPI1_RX
    AF(2, UART, 1), // UART1_TX
    AF(3, I2C , 0), // I2C0_SDA
    AF(4, PWM , 4), // PWM4_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO9_af[] = {
    AF(1, SPI , 1), // SPI1_CS
    AF(2, UART, 1), // UART1_RX
    AF(3, I2C , 0), // I2C0_SCL
    AF(4, PWM , 4), // PWM4_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO10_af[] = {
    AF(1, SPI , 1), // SPI1_SCK
    AF(2, UART, 1), // UART1_CTS
    AF(3, I2C , 1), // I2C1_SDA
    AF(4, PWM , 5), // PWM5_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO11_af[] = {
    AF(1, SPI , 1), // SPI1_TX
    AF(2, UART, 1), // UART1_RTS
    AF(3, I2C , 1), // I2C1_SCL
    AF(4, PWM , 5), // PWM5_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO12_af[] = {
    AF(1, SPI , 1), // SPI1_RX
    AF(2, UART, 0), // UART0_TX
    AF(3, I2C , 0), // I2C0_SDA
    AF(4, PWM , 6), // PWM6_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO13_af[] = {
    AF(1, SPI , 1), // SPI1_CS
    AF(2, UART, 0), // UART0_RX
    AF(3, I2C , 0), // I2C0_SCL
    AF(4, PWM , 6), // PWM6_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO14_af[] = {
    AF(1, SPI , 1), // SPI1_SCK
    AF(2, UART, 0), // UART0_CTS
    AF(3, I2C , 1), // I2C1_SDA
    AF(4, PWM , 7), // PWM7_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO15_af[] = {
    AF(1, SPI , 1), // SPI1_TX
    AF(2, UART, 0), // UART0_RTS
    AF(3, I2C , 1), // I2C1_SCL
    AF(4, PWM , 7), // PWM7_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO16_af[] = {
    AF(1, SPI , 0), // SPI0_RX
    AF(2, UART, 0), // UART0_TX
    AF(3, I2C , 0), // I2C0_SDA
    AF(4, PWM , 0), // PWM0_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO17_af[] = {
    AF(1, SPI , 0), // SPI0_CS
    AF(2, UART, 0), // UART0_RX
    AF(3, I2C , 0), // I2C0_SCL
    AF(4, PWM , 0), // PWM0_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO18_af[] = {
    AF(1, SPI , 0), // SPI0_SCK
    AF(2, UART, 0), // UART0_CTS
    AF(3, I2C , 1), // I2C1_SDA
    AF(4, PWM , 1), // PWM1_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO19_af[] = {
    AF(1, SPI , 0), // SPI0_TX
    AF(2, UART, 0), // UART0_RTS
    AF(3, I2C , 1), // I2C1_SCL
    AF(4, PWM , 1), // PWM1_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO20_af[] = {
    AF(1, SPI , 0), // SPI0_RX
    AF(2, UART, 1), // UART1_TX
    AF(3, I2C , 0), // I2C0_SDA
    AF(4, PWM , 2), // PWM2_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(8, GPCK, 0), // GPCK_GPIN0
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO21_af[] = {
    AF(1, SPI , 0), // SPI0_CS
    AF(2, UART, 1), // UART1_RX
    AF(3, I2C , 0), // I2C0_SCL
    AF(4, PWM , 2), // PWM2_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(8, GPCK, 0), // GPCK_GPOUT0
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO22_af[] = {
    AF(1, SPI , 0), // SPI0_SCK
    AF(2, UART, 1), // UART1_CTS
    AF(3, I2C , 1), // I2C1_SDA
    AF(4, PWM , 3), // PWM3_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(8, GPCK, 0), // GPCK_GPIN1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO23_af[] = {
    AF(1, SPI , 0), // SPI0_TX
    AF(2, UART, 1), // UART1_RTS
    AF(3, I2C , 1), // I2C1_SCL
    AF(4, PWM , 3), // PWM3_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(8, GPCK, 0), // GPCK_GPOUT1
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO24_af[] = {
    AF(1, SPI , 1), // SPI1_RX
    AF(2, UART, 1), // UART1_TX
    AF(3, I2C , 0), // I2C0_SDA
    AF(4, PWM , 4), // PWM4_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(8, GPCK, 0), // GPCK_GPOUT2
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO25_af[] = {
    AF(1, SPI , 1), // SPI1_CS
    AF(2, UART, 1), // UART1_RX
    AF(3, I2C , 0), // I2C0_SCL
    AF(4, PWM , 4), // PWM4_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(8, GPCK, 0), // GPCK_GPOUT3
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO26_af[] = {
    AF(1, SPI , 1), // SPI1_SCK
    AF(2, UART, 1), // UART1_CTS
    AF(3, I2C , 1), // I2C1_SDA
    AF(4, PWM , 5), // PWM5_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_EN
};

const machine_pin_af_obj_t pin_GPIO27_af[] = {
    AF(1, SPI , 1), // SPI1_TX
    AF(2, UART, 1), // UART1_RTS
    AF(3, I2C , 1), // I2C1_SCL
    AF(4, PWM , 5), // PWM5_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_OVCUR_DET
};

const machine_pin_af_obj_t pin_GPIO28_af[] = {
    AF(1, SPI , 1), // SPI1_RX
    AF(2, UART, 0), // UART0_TX
    AF(3, I2C , 0), // I2C0_SDA
    AF(4, PWM , 6), // PWM6_A
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_DET
};

const machine_pin_af_obj_t pin_GPIO29_af[] = {
    AF(1, SPI , 1), // SPI1_CS
    AF(2, UART, 0), // UART0_RX
    AF(3, I2C , 0), // I2C0_SCL
    AF(4, PWM , 6), // PWM6_B
    AF(5, SIO , 0), // SIO
    AF(6, PIO0, 0), // PIO0
    AF(7, PIO1, 1), // PIO1
    AF(9, USB , 0), // USB_VBUS_EN
};


const machine_pin_obj_t machine_pin_obj_table[NUM_BANK0_GPIOS] = {
    [0] = PIN(0, GPIO0, 0, 8, pin_GPIO0_af),
    [1] = PIN(1, GPIO1, 0, 8, pin_GPIO1_af),
    [2] = PIN(2, GPIO2, 0, 8, pin_GPIO2_af),
    [3] = PIN(3, GPIO3, 0, 8, pin_GPIO3_af),
    [4] = PIN(4, GPIO4, 0, 8, pin_GPIO4_af),
    [5] = PIN(5, GPIO5, 0, 8, pin_GPIO5_af),
    [6] = PIN(6, GPIO6, 0, 8, pin_GPIO6_af),
    [7] = PIN(7, GPIO7, 0, 8, pin_GPIO7_af),
    [8] = PIN(8, GPIO8, 0, 8, pin_GPIO8_af),
    [9] = PIN(9, GPIO9, 0, 8, pin_GPIO9_af),
    [10] = PIN(10, GPIO10, 0, 8, pin_GPIO10_af),
    [11] = PIN(11, GPIO11, 0, 8, pin_GPIO11_af),
    [12] = PIN(12, GPIO12, 0, 8, pin_GPIO12_af),
    [13] = PIN(13, GPIO13, 0, 8, pin_GPIO13_af),
    [14] = PIN(14, GPIO14, 0, 8, pin_GPIO14_af),
    [15] = PIN(15, GPIO15, 0, 8, pin_GPIO15_af),
    [16] = PIN(16, GPIO16, 0, 8, pin_GPIO16_af),
    [17] = PIN(17, GPIO17, 0, 8, pin_GPIO17_af),
    [18] = PIN(18, GPIO18, 0, 8, pin_GPIO18_af),
    [19] = PIN(19, GPIO19, 0, 8, pin_GPIO19_af),
    [20] = PIN(20, GPIO20, 0, 9, pin_GPIO20_af),
    [21] = PIN(21, GPIO21, 0, 9, pin_GPIO21_af),
    [22] = PIN(22, GPIO22, 0, 9, pin_GPIO22_af),
    [23] = PIN(23, GPIO23, 0, 9, pin_GPIO23_af),
    [24] = PIN(24, GPIO24, 0, 9, pin_GPIO24_af),
    [25] = PIN(25, GPIO25, 0, 9, pin_GPIO25_af),
    [26] = PIN(26, GPIO26, 0, 8, pin_GPIO26_af),
    [27] = PIN(27, GPIO27, 0, 8, pin_GPIO27_af),
    [28] = PIN(28, GPIO28, 0, 8, pin_GPIO28_af),
    [29] = PIN(29, GPIO29, 0, 8, pin_GPIO29_af),
};

#if (MICROPY_HW_PIN_EXT_COUNT > 0)
machine_pin_obj_t pin_EXT_GPIO0_obj = PIN(0, EXT_GPIO0, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 1)
machine_pin_obj_t pin_EXT_GPIO1_obj = PIN(1, EXT_GPIO1, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 2)
machine_pin_obj_t pin_EXT_GPIO2_obj = PIN(2, EXT_GPIO2, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 3)
machine_pin_obj_t pin_EXT_GPIO3_obj = PIN(3, EXT_GPIO3, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 4)
machine_pin_obj_t pin_EXT_GPIO4_obj = PIN(4, EXT_GPIO4, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 5)
machine_pin_obj_t pin_EXT_GPIO5_obj = PIN(5, EXT_GPIO5, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 6)
machine_pin_obj_t pin_EXT_GPIO6_obj = PIN(6, EXT_GPIO6, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 7)
machine_pin_obj_t pin_EXT_GPIO7_obj = PIN(7, EXT_GPIO7, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 8)
machine_pin_obj_t pin_EXT_GPIO8_obj = PIN(8, EXT_GPIO8, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 9)
machine_pin_obj_t pin_EXT_GPIO9_obj = PIN(9, EXT_GPIO9, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 10)
machine_pin_obj_t pin_EXT_GPIO10_obj = PIN(10, EXT_GPIO10, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 11)
machine_pin_obj_t pin_EXT_GPIO11_obj = PIN(11, EXT_GPIO11, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 12)
machine_pin_obj_t pin_EXT_GPIO12_obj = PIN(12, EXT_GPIO12, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 13)
machine_pin_obj_t pin_EXT_GPIO13_obj = PIN(13, EXT_GPIO13, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 14)
machine_pin_obj_t pin_EXT_GPIO14_obj = PIN(14, EXT_GPIO14, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 15)
machine_pin_obj_t pin_EXT_GPIO15_obj = PIN(15, EXT_GPIO15, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 16)
machine_pin_obj_t pin_EXT_GPIO16_obj = PIN(16, EXT_GPIO16, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 17)
machine_pin_obj_t pin_EXT_GPIO17_obj = PIN(17, EXT_GPIO17, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 18)
machine_pin_obj_t pin_EXT_GPIO18_obj = PIN(18, EXT_GPIO18, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 19)
machine_pin_obj_t pin_EXT_GPIO19_obj = PIN(19, EXT_GPIO19, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 20)
machine_pin_obj_t pin_EXT_GPIO20_obj = PIN(20, EXT_GPIO20, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 21)
machine_pin_obj_t pin_EXT_GPIO21_obj = PIN(21, EXT_GPIO21, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 22)
machine_pin_obj_t pin_EXT_GPIO22_obj = PIN(22, EXT_GPIO22, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 23)
machine_pin_obj_t pin_EXT_GPIO23_obj = PIN(23, EXT_GPIO23, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 24)
machine_pin_obj_t pin_EXT_GPIO24_obj = PIN(24, EXT_GPIO24, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 25)
machine_pin_obj_t pin_EXT_GPIO25_obj = PIN(25, EXT_GPIO25, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 26)
machine_pin_obj_t pin_EXT_GPIO26_obj = PIN(26, EXT_GPIO26, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 27)
machine_pin_obj_t pin_EXT_GPIO27_obj = PIN(27, EXT_GPIO27, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 28)
machine_pin_obj_t pin_EXT_GPIO28_obj = PIN(28, EXT_GPIO28, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 29)
machine_pin_obj_t pin_EXT_GPIO29_obj = PIN(29, EXT_GPIO29, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 30)
machine_pin_obj_t pin_EXT_GPIO30_obj = PIN(30, EXT_GPIO30, 1, 0, NULL);
#endif
#if (MICROPY_HW_PIN_EXT_COUNT > 31)
machine_pin_obj_t pin_EXT_GPIO31_obj = PIN(31, EXT_GPIO31, 1, 0, NULL);
#endif

static const mp_rom_map_elem_t machine_pin_board_pins_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_GP0), MP_ROM_PTR(pin_GPIO0) },
    { MP_ROM_QSTR(MP_QSTR_GP1), MP_ROM_PTR(pin_GPIO1) },
    { MP_ROM_QSTR(MP_QSTR_GP2), MP_ROM_PTR(pin_GPIO2) },
    { MP_ROM_QSTR(MP_QSTR_GP3), MP_ROM_PTR(pin_GPIO3) },
    { MP_ROM_QSTR(MP_QSTR_GP4), MP_ROM_PTR(pin_GPIO4) },
    { MP_ROM_QSTR(MP_QSTR_GP5), MP_ROM_PTR(pin_GPIO5) },
    { MP_ROM_QSTR(MP_QSTR_GP6), MP_ROM_PTR(pin_GPIO6) },
    { MP_ROM_QSTR(MP_QSTR_GP7), MP_ROM_PTR(pin_GPIO7) },
    { MP_ROM_QSTR(MP_QSTR_GP8), MP_ROM_PTR(pin_GPIO8) },
    { MP_ROM_QSTR(MP_QSTR_GP9), MP_ROM_PTR(pin_GPIO9) },
    { MP_ROM_QSTR(MP_QSTR_GP10), MP_ROM_PTR(pin_GPIO10) },
    { MP_ROM_QSTR(MP_QSTR_GP11), MP_ROM_PTR(pin_GPIO11) },
    { MP_ROM_QSTR(MP_QSTR_GP12), MP_ROM_PTR(pin_GPIO12) },
    { MP_ROM_QSTR(MP_QSTR_GP13), MP_ROM_PTR(pin_GPIO13) },
    { MP_ROM_QSTR(MP_QSTR_GP14), MP_ROM_PTR(pin_GPIO14) },
    { MP_ROM_QSTR(MP_QSTR_GP15), MP_ROM_PTR(pin_GPIO15) },
    { MP_ROM_QSTR(MP_QSTR_GP16), MP_ROM_PTR(pin_GPIO16) },
    { MP_ROM_QSTR(MP_QSTR_GP17), MP_ROM_PTR(pin_GPIO17) },
    { MP_ROM_QSTR(MP_QSTR_GP18), MP_ROM_PTR(pin_GPIO18) },
    { MP_ROM_QSTR(MP_QSTR_GP19), MP_ROM_PTR(pin_GPIO19) },
    { MP_ROM_QSTR(MP_QSTR_GP20), MP_ROM_PTR(pin_GPIO20) },
    { MP_ROM_QSTR(MP_QSTR_GP21), MP_ROM_PTR(pin_GPIO21) },
    { MP_ROM_QSTR(MP_QSTR_GP22), MP_ROM_PTR(pin_GPIO22) },
    { MP_ROM_QSTR(MP_QSTR_GP25), MP_ROM_PTR(pin_GPIO25) },
    { MP_ROM_QSTR(MP_QSTR_LED), MP_ROM_PTR(pin_GPIO25) },
    { MP_ROM_QSTR(MP_QSTR_GP26), MP_ROM_PTR(pin_GPIO26) },
    { MP_ROM_QSTR(MP_QSTR_GP27), MP_ROM_PTR(pin_GPIO27) },
    { MP_ROM_QSTR(MP_QSTR_GP28), MP_ROM_PTR(pin_GPIO28) },
};
MP_DEFINE_CONST_DICT(machine_pin_board_pins_locals_dict, machine_pin_board_pins_locals_dict_table);

static const mp_rom_map_elem_t machine_pin_cpu_pins_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_GPIO0), MP_ROM_PTR(pin_GPIO0) },
    { MP_ROM_QSTR(MP_QSTR_GPIO1), MP_ROM_PTR(pin_GPIO1) },
    { MP_ROM_QSTR(MP_QSTR_GPIO2), MP_ROM_PTR(pin_GPIO2) },
    { MP_ROM_QSTR(MP_QSTR_GPIO3), MP_ROM_PTR(pin_GPIO3) },
    { MP_ROM_QSTR(MP_QSTR_GPIO4), MP_ROM_PTR(pin_GPIO4) },
    { MP_ROM_QSTR(MP_QSTR_GPIO5), MP_ROM_PTR(pin_GPIO5) },
    { MP_ROM_QSTR(MP_QSTR_GPIO6), MP_ROM_PTR(pin_GPIO6) },
    { MP_ROM_QSTR(MP_QSTR_GPIO7), MP_ROM_PTR(pin_GPIO7) },
    { MP_ROM_QSTR(MP_QSTR_GPIO8), MP_ROM_PTR(pin_GPIO8) },
    { MP_ROM_QSTR(MP_QSTR_GPIO9), MP_ROM_PTR(pin_GPIO9) },
    { MP_ROM_QSTR(MP_QSTR_GPIO10), MP_ROM_PTR(pin_GPIO10) },
    { MP_ROM_QSTR(MP_QSTR_GPIO11), MP_ROM_PTR(pin_GPIO11) },
    { MP_ROM_QSTR(MP_QSTR_GPIO12), MP_ROM_PTR(pin_GPIO12) },
    { MP_ROM_QSTR(MP_QSTR_GPIO13), MP_ROM_PTR(pin_GPIO13) },
    { MP_ROM_QSTR(MP_QSTR_GPIO14), MP_ROM_PTR(pin_GPIO14) },
    { MP_ROM_QSTR(MP_QSTR_GPIO15), MP_ROM_PTR(pin_GPIO15) },
    { MP_ROM_QSTR(MP_QSTR_GPIO16), MP_ROM_PTR(pin_GPIO16) },
    { MP_ROM_QSTR(MP_QSTR_GPIO17), MP_ROM_PTR(pin_GPIO17) },
    { MP_ROM_QSTR(MP_QSTR_GPIO18), MP_ROM_PTR(pin_GPIO18) },
    { MP_ROM_QSTR(MP_QSTR_GPIO19), MP_ROM_PTR(pin_GPIO19) },
    { MP_ROM_QSTR(MP_QSTR_GPIO20), MP_ROM_PTR(pin_GPIO20) },
    { MP_ROM_QSTR(MP_QSTR_GPIO21), MP_ROM_PTR(pin_GPIO21) },
    { MP_ROM_QSTR(MP_QSTR_GPIO22), MP_ROM_PTR(pin_GPIO22) },
    { MP_ROM_QSTR(MP_QSTR_GPIO23), MP_ROM_PTR(pin_GPIO23) },
    { MP_ROM_QSTR(MP_QSTR_GPIO24), MP_ROM_PTR(pin_GPIO24) },
    { MP_ROM_QSTR(MP_QSTR_GPIO25), MP_ROM_PTR(pin_GPIO25) },
    { MP_ROM_QSTR(MP_QSTR_GPIO26), MP_ROM_PTR(pin_GPIO26) },
    { MP_ROM_QSTR(MP_QSTR_GPIO27), MP_ROM_PTR(pin_GPIO27) },
    { MP_ROM_QSTR(MP_QSTR_GPIO28), MP_ROM_PTR(pin_GPIO28) },
    { MP_ROM_QSTR(MP_QSTR_GPIO29), MP_ROM_PTR(pin_GPIO29) },
    #if (MICROPY_HW_PIN_EXT_COUNT > 0)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO0), MP_ROM_PTR(pin_EXT_GPIO0) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 1)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO1), MP_ROM_PTR(pin_EXT_GPIO1) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 2)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO2), MP_ROM_PTR(pin_EXT_GPIO2) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 3)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO3), MP_ROM_PTR(pin_EXT_GPIO3) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 4)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO4), MP_ROM_PTR(pin_EXT_GPIO4) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 5)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO5), MP_ROM_PTR(pin_EXT_GPIO5) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 6)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO6), MP_ROM_PTR(pin_EXT_GPIO6) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 7)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO7), MP_ROM_PTR(pin_EXT_GPIO7) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 8)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO8), MP_ROM_PTR(pin_EXT_GPIO8) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 9)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO9), MP_ROM_PTR(pin_EXT_GPIO9) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 10)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO10), MP_ROM_PTR(pin_EXT_GPIO10) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 11)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO11), MP_ROM_PTR(pin_EXT_GPIO11) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 12)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO12), MP_ROM_PTR(pin_EXT_GPIO12) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 13)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO13), MP_ROM_PTR(pin_EXT_GPIO13) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 14)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO14), MP_ROM_PTR(pin_EXT_GPIO14) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 15)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO15), MP_ROM_PTR(pin_EXT_GPIO15) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 16)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO16), MP_ROM_PTR(pin_EXT_GPIO16) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 17)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO17), MP_ROM_PTR(pin_EXT_GPIO17) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 18)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO18), MP_ROM_PTR(pin_EXT_GPIO18) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 19)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO19), MP_ROM_PTR(pin_EXT_GPIO19) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 20)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO20), MP_ROM_PTR(pin_EXT_GPIO20) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 21)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO21), MP_ROM_PTR(pin_EXT_GPIO21) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 22)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO22), MP_ROM_PTR(pin_EXT_GPIO22) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 23)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO23), MP_ROM_PTR(pin_EXT_GPIO23) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 24)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO24), MP_ROM_PTR(pin_EXT_GPIO24) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 25)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO25), MP_ROM_PTR(pin_EXT_GPIO25) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 26)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO26), MP_ROM_PTR(pin_EXT_GPIO26) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 27)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO27), MP_ROM_PTR(pin_EXT_GPIO27) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 28)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO28), MP_ROM_PTR(pin_EXT_GPIO28) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 29)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO29), MP_ROM_PTR(pin_EXT_GPIO29) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 30)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO30), MP_ROM_PTR(pin_EXT_GPIO30) },
    #endif
    #if (MICROPY_HW_PIN_EXT_COUNT > 31)
    { MP_ROM_QSTR(MP_QSTR_EXT_GPIO31), MP_ROM_PTR(pin_EXT_GPIO31) },
    #endif
};
MP_DEFINE_CONST_DICT(machine_pin_cpu_pins_locals_dict, machine_pin_cpu_pins_locals_dict_table);
