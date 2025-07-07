/**
 * Tobias Mages & Wenqing Yan
 * Backscatter PIO
 * 02-March-2023
 *
 * See the sub-projects ... for further information:
 *  - baseband
 *  - carrier-CC2500
 *  - receiver-CC2500
 *
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "pico/stdlib.h"

#include "pico/util/queue.h"
#include "pico/binary_info.h"
#include "pico/util/datetime.h"
#include "hardware/spi.h"

#include "hardware/pio.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "project_pico_libs/backscatter.h"
#include "project_pico_libs/carrier_CC2500.h"
#include "project_pico_libs/receiver_CC2500.h"
#include "project_pico_libs/packet_generation.h"

#include "py/runtime.h"


#define RADIO_SPI             spi0
#define RADIO_MISO               4
#define RADIO_MOSI               3
#define RADIO_SCK                2


#define RECEIVER              2500 // define the receiver board either 2500 or 1352
#define PIN_TX1                  5
#define PIN_TX2                  27
#define CLOCK_DIV0              20 // larger
#define CLOCK_DIV1              18 // smaller
#define DESIRED_BAUD        100000
#define TWOANTENNAS              false

#define CARRIER_FEQ     2450000000

#define LED_PIN_1               21
#define LED_PIN_2               22
#define LED_BUILTIN             PICO_DEFAULT_LED_PIN
#define LOOP_INFINITE           true
uint8_t msg[RX_BUFFER_SIZE];
bool led_value = false;


// *************************************************************************
// *                                                                       *
// *    C functionality                                                    *
// *                                                                       *
// *************************************************************************


void gpio_callback() {
    stdio_init_all();
    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);

    if (led_value)
        led_value = false;
    else
        led_value = true;
    
    gpio_put(LED_PIN_2, led_value);
    //sleep_ms(400);
    //gpio_put(LED_PIN_2, 0);
}

int carrier_receiver_setup() {
    // setup SPI 
    stdio_init_all();
    spi_init(RADIO_SPI, 5 * 1000000); // SPI0 at 5MHz.
    gpio_set_function(RADIO_SCK, GPIO_FUNC_SPI);
    gpio_set_function(RADIO_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(RADIO_MISO, GPIO_FUNC_SPI);

    // Make the SPI pins available to picotool
    bi_decl(bi_3pins_with_func(RADIO_MOSI, RADIO_MISO, RADIO_SCK, GPIO_FUNC_SPI));

    // Initialize LEDs
    gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);
    gpio_put(LED_PIN_1, 0);
    
    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);
    gpio_put(LED_PIN_2, 0);

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, 0);

    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_init(CARRIER_CSN);
    gpio_set_dir(CARRIER_CSN, GPIO_OUT);
    gpio_put(CARRIER_CSN, 1);
    bi_decl(bi_1pin_with_name(CARRIER_CSN, "SPI Carrier CS"));

    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_init(RX_CSN);
    gpio_set_dir(RX_CSN, GPIO_OUT);
    gpio_put(RX_CSN, 1);
    bi_decl(bi_1pin_with_name(RX_CSN, "SPI Receiver CS"));

    // setup backscatter state machine 
    PIO pio = pio0;
    uint sm = 0;
    struct backscatter_config backscatter_conf;
    uint16_t instructionBuffer[32] = {0}; // maximal instruction size: 32
    backscatter_program_init(pio, sm, PIN_TX1, PIN_TX2, CLOCK_DIV0, CLOCK_DIV1, DESIRED_BAUD, &backscatter_conf, instructionBuffer, TWOANTENNAS);

    //static uint8_t message[buffer_size(PAYLOADSIZE+2, HEADER_LEN)*4] = {0};  // include 10 header bytes
    //static uint32_t buffer[buffer_size(PAYLOADSIZE, HEADER_LEN)] = {0}; // initialize the buffer
    //static uint8_t seq = 0;
    //uint8_t *header_tmplate = packet_hdr_template(RECEIVER);
    //uint8_t tx_payload_buffer[PAYLOADSIZE];

    // Setup carrier
    printf("\nConfiguring one CC2500 as carrier generator:\n");
    setupCarrier();
    set_frecuency_tx(CARRIER_FEQ);
    sleep_ms(1);

    // Start Receiver 
    printf("\nConfiguring one CC2500 to approximate the obtained radio settings:\n");
    //event_t evt = no_evt;
    //Packet_status status;
    //uint8_t rx_buffer[RX_BUFFER_SIZE];
    //uint64_t time_us;
    
    //setupReceiver();    //Possible block
    
    set_frecuency_rx(CARRIER_FEQ + backscatter_conf.center_offset);
    set_frequency_deviation_rx(backscatter_conf.deviation);
    set_datarate_rx(backscatter_conf.baudrate);
    set_filter_bandwidth_rx(backscatter_conf.minRxBw);
    sleep_ms(1);
    
    //Activate Awake Led
    gpio_put(PICO_DEFAULT_LED_PIN, 1);
    gpio_put(LED_PIN_1, 1);
    gpio_put(LED_PIN_2, 1);
    sleep_ms(1000);
    gpio_put(LED_PIN_1, 0);
    gpio_put(LED_PIN_2, 0);
    gpio_put(PICO_DEFAULT_LED_PIN, 0);

    //RX_start_listen();

    //startCarrier();
    //bool rx_ready = true;
    
    //gpio_pull_down(RX_GDO0_PIN);
    
    //gpio_set_irq_enabled_with_callback(RX_GDO0_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    
        
    //loop 2
    
/*
    // loop 
    do{
        evt = get_event();
        switch(evt){
            case rx_assert_evt:
                // started receiving
                rx_ready = false;
            break;
            case rx_deassert_evt:
                // finished receiving
                time_us = to_us_since_boot(get_absolute_time());
                status = readPacket(rx_buffer);
                printPacket(rx_buffer,status,time_us);
                RX_start_listen();
                rx_ready = true;
                gpio_put(LED_PIN_2, 1);
                sleep_ms(50);
                gpio_put(LED_PIN_2, 0);
            break;
            case no_evt:
                if (rx_ready){
                   startCarrier();
                   gpio_put(LED_PIN_1, 1);
                   sleep_ms(1); // wait for carrier to start
                }
            break;
        }
        sleep_ms(1);
    }while (LOOP_INFINITE);

    // stop carrier and receiver - never reached 
    RX_stop_listen();
    gpio_put(LED_PIN_1, 0);
    stopCarrier();
    memset(msg,'0',sizeof(msg));
    memcpy(msg,rx_buffer,sizeof(rx_buffer));
    
    gpio_put(PICO_DEFAULT_LED_PIN, 0);*/

    return(0);
}

int carrier_receiver_receive() {

    /*
    // setup backscatter state machine 
    PIO pio = pio0;
    uint sm = 0;
    uint16_t instructionBuffer[32] = {0}; // maximal instruction size: 32
    backscatter_program_init(pio, sm, PIN_TX1, PIN_TX2, CLOCK_DIV0, CLOCK_DIV1, DESIRED_BAUD, &backscatter_conf, instructionBuffer, TWOANTENNAS);

    // Setup carrier 
    printf("\nConfiguring one CC2500 as carrier generator:\n");
    setupCarrier();
    set_frecuency_tx(CARRIER_FEQ);
    sleep_ms(1);

    // Start Receiver
    printf("\nConfiguring one CC2500 to approximate the obtained radio settings:\n");
    
    setupReceiver();    //Possible block
    
    set_frecuency_rx(CARRIER_FEQ + backscatter_conf.center_offset);
    set_frequency_deviation_rx(backscatter_conf.deviation);
    set_datarate_rx(backscatter_conf.baudrate);
    set_filter_bandwidth_rx(backscatter_conf.minRxBw);
    sleep_ms(1);
    printf("started listening\n");
*/
    stdio_init_all();

    Packet_status status;
    uint8_t rx_buffer[RX_BUFFER_SIZE];
    uint64_t time_us;
    bool rx_ready = true;
    
    event_t evt = no_evt;
    RX_start_listen();
    gpio_put(PICO_DEFAULT_LED_PIN, 1);

    // loop 
    do{
        evt = get_event();
        switch(evt){
            case rx_assert_evt:
                // started receiving
                rx_ready = false;
            break;
            case rx_deassert_evt:
                // finished receiving
                time_us = to_us_since_boot(get_absolute_time());
                status = readPacket(rx_buffer);
                printPacket(rx_buffer,status,time_us);
                RX_start_listen();
                rx_ready = true;
                gpio_put(LED_PIN_2, 1);
                sleep_ms(50);
                gpio_put(LED_PIN_2, 0);
            break;
            case no_evt:
                if (rx_ready){
                   startCarrier();
                   gpio_put(LED_PIN_1, 1);
                   sleep_ms(1); // wait for carrier to start
                }
            break;
        }
        sleep_ms(1);
    }while (LOOP_INFINITE);

    // stop carrier and receiver - never reached 
    RX_stop_listen();
    gpio_put(LED_PIN_1, 0);
    stopCarrier();
    gpio_put(PICO_DEFAULT_LED_PIN, 0);
    memset(msg,'0',sizeof(msg));
    memcpy(msg,rx_buffer,sizeof(rx_buffer));
    return(0);
}

/*
int interrupt_test() {
    
    gpio_put(PICO_DEFAULT_LED_PIN, 1);

    // loop 
    do{
        evt = get_event();
        switch(evt){
            case rx_assert_evt:
                // started receiving
                rx_ready = false;
            break;
            case rx_deassert_evt:
                // finished receiving
                time_us = to_us_since_boot(get_absolute_time());
                status = readPacket(rx_buffer);
                printPacket(rx_buffer,status,time_us);
                RX_start_listen();
                rx_ready = true;
                gpio_put(LED_PIN_2, 1);
                sleep_ms(50);
                gpio_put(LED_PIN_2, 0);
            break;
            case no_evt:
                if (rx_ready){
                   startCarrier();
                   gpio_put(LED_PIN_1, 1);
                   sleep_ms(1); // wait for carrier to start
                }
            break;
        }
        sleep_ms(1);
    }while (LOOP_INFINITE);

    // stop carrier and receiver - never reached 
    RX_stop_listen();
    gpio_put(LED_PIN_1, 0);
    stopCarrier();
    gpio_put(PICO_DEFAULT_LED_PIN, 0);
    memset(msg,'0',sizeof(msg));
    memcpy(msg,rx_buffer,sizeof(rx_buffer));
    return(0);
}
*/

// .-----------------------------------------------------------------------.
// *    MicroPython integration                                            |
// `-----------------------------------------------------------------------'

static mp_obj_t start_carrier_CR(void) {
    startCarrier();
    gpio_put(LED_PIN_1, 1);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(start_carrier_CR_obj, start_carrier_CR);

static mp_obj_t stop_carrier_CR(void) {
    stopCarrier();
    gpio_put(LED_PIN_1, 0);   
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(stop_carrier_CR_obj, stop_carrier_CR);

static mp_obj_t setup_CR(void) {
    stdio_init_all();
    spi_init(RADIO_SPI, 5 * 1000000); // SPI0 at 5MHz.
    gpio_set_function(RADIO_SCK, GPIO_FUNC_SPI);
    gpio_set_function(RADIO_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(RADIO_MISO, GPIO_FUNC_SPI);

    // Make the SPI pins available to picotool
    bi_decl(bi_3pins_with_func(RADIO_MOSI, RADIO_MISO, RADIO_SCK, GPIO_FUNC_SPI));

    // Initialize LEDs
    gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);
    gpio_put(LED_PIN_1, 0);
    
    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);
    gpio_put(LED_PIN_2, 0);

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, 0);

    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_init(CARRIER_CSN);
    gpio_set_dir(CARRIER_CSN, GPIO_OUT);
    gpio_put(CARRIER_CSN, 1);
    //bi_decl(bi_1pin_with_name(CARRIER_CSN, "SPI Carrier CS"));

    // Chip select is active-low, so we'll initialise it to a driven-high state
    //gpio_init(RX_CSN);
    //gpio_set_dir(RX_CSN, GPIO_OUT);
    //gpio_put(RX_CSN, 1);
    //bi_decl(bi_1pin_with_name(RX_CSN, "SPI Receiver CS"));

    // setup backscatter state machine 
    PIO pio = pio0;
    uint sm = 0;
    struct backscatter_config backscatter_conf;
    uint16_t instructionBuffer[32] = {0}; // maximal instruction size: 32
    backscatter_program_init(pio, sm, PIN_TX1, PIN_TX2, CLOCK_DIV0, CLOCK_DIV1, DESIRED_BAUD, &backscatter_conf, instructionBuffer, TWOANTENNAS);

    //static uint8_t message[buffer_size(PAYLOADSIZE+2, HEADER_LEN)*4] = {0};  // include 10 header bytes
    //static uint32_t buffer[buffer_size(PAYLOADSIZE, HEADER_LEN)] = {0}; // initialize the buffer
    //static uint8_t seq = 0;
    //uint8_t *header_tmplate = packet_hdr_template(RECEIVER);
    //uint8_t tx_payload_buffer[PAYLOADSIZE];

    // Setup carrier
    printf("\nConfiguring one CC2500 as carrier generator:\n");
    setupCarrier();
    set_frecuency_tx(CARRIER_FEQ);
    sleep_ms(1);

    // Start Receiver 
    printf("\nConfiguring one CC2500 to approximate the obtained radio settings:\n");
    //event_t evt = no_evt;
    //Packet_status status;
    //uint8_t rx_buffer[RX_BUFFER_SIZE];
    //uint64_t time_us;
    
    setupReceiver();    //Possible block
    
    set_frecuency_rx(CARRIER_FEQ + backscatter_conf.center_offset);
    set_frequency_deviation_rx(backscatter_conf.deviation);
    set_datarate_rx(backscatter_conf.baudrate);
    set_filter_bandwidth_rx(backscatter_conf.minRxBw);
    sleep_ms(1);
    
    //Activate Awake Led
    gpio_put(PICO_DEFAULT_LED_PIN, 1);
    gpio_put(LED_PIN_1, 1);
    gpio_put(LED_PIN_2, 1);
    sleep_ms(1000);
    gpio_put(LED_PIN_1, 0);
    gpio_put(LED_PIN_2, 0);
    gpio_put(PICO_DEFAULT_LED_PIN, 0);

    RX_start_listen();

    //startCarrier();
    //bool rx_ready = true;
    
    //gpio_pull_down(RX_GDO0_PIN);
    
    //gpio_set_irq_enabled_with_callback(RX_GDO0_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    
        
    //loop 2
    
/*
    // loop 
    do{
        evt = get_event();
        switch(evt){
            case rx_assert_evt:
                // started receiving
                rx_ready = false;
            break;
            case rx_deassert_evt:
                // finished receiving
                time_us = to_us_since_boot(get_absolute_time());
                status = readPacket(rx_buffer);
                printPacket(rx_buffer,status,time_us);
                RX_start_listen();
                rx_ready = true;
                gpio_put(LED_PIN_2, 1);
                sleep_ms(50);
                gpio_put(LED_PIN_2, 0);
            break;
            case no_evt:
                if (rx_ready){
                   startCarrier();
                   gpio_put(LED_PIN_1, 1);
                   sleep_ms(1); // wait for carrier to start
                }
            break;
        }
        sleep_ms(1);
    }while (LOOP_INFINITE);

    // stop carrier and receiver - never reached 
    RX_stop_listen();
    gpio_put(LED_PIN_1, 0);
    stopCarrier();
    memset(msg,'0',sizeof(msg));
    memcpy(msg,rx_buffer,sizeof(rx_buffer));
    
    gpio_put(PICO_DEFAULT_LED_PIN, 0);*/
    mp_printf(&mp_plat_print, "Setup Done\n");
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(setup_CR_obj, setup_CR);

static mp_obj_t receive_CR(void) {
    carrier_receiver_receive();
    return mp_obj_new_str((char*) msg,sizeof(msg));
}
MP_DEFINE_CONST_FUN_OBJ_0(receive_CR_obj, receive_CR);

static mp_obj_t test_SPI_CR(void) {
    mp_printf(&mp_plat_print, "Test SPI\n");
    gpio_init(RX_CSN);
    gpio_set_dir(RX_CSN, GPIO_OUT);
    //write_strobe_rx(SIDLE);
    sleep_ms(3000);
    //cs_select_rx();
    gpio_put(RX_CSN, 0);
    cs_select_tx();
    gpio_init(RX_CSN);
    gpio_set_dir(RX_CSN, GPIO_OUT);
    sleep_ms(3000);
    //gpio_init(RX_CSN);
    //gpio_set_dir(RX_CSN, GPIO_OUT);
    //cs_deselect_rx();
    gpio_put(RX_CSN, 1);
    gpio_deinit(RX_CSN);
    cs_deselect_tx();
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(test_SPI_CR_obj, test_SPI_CR);

static const mp_rom_map_elem_t carrier_receiver_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__),            MP_ROM_QSTR(MP_QSTR_carrier_receiver) },
    { MP_ROM_QSTR(MP_QSTR_setup_CR),            MP_ROM_PTR(&setup_CR_obj) },
    { MP_ROM_QSTR(MP_QSTR_receive_CR),          MP_ROM_PTR(&receive_CR_obj) },
    { MP_ROM_QSTR(MP_QSTR_start_carrier_CR),            MP_ROM_PTR(&start_carrier_CR_obj) },
    { MP_ROM_QSTR(MP_QSTR_stop_carrier_CR),            MP_ROM_PTR(&stop_carrier_CR_obj) },
    { MP_ROM_QSTR(MP_QSTR_test_SPI_CR),            MP_ROM_PTR(&test_SPI_CR_obj) },
};
static MP_DEFINE_CONST_DICT(carrier_receiver_module_globals, carrier_receiver_module_globals_table);

const mp_obj_module_t mp_module_carrier_receiver = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&carrier_receiver_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_carrier_receiver, mp_module_carrier_receiver);
