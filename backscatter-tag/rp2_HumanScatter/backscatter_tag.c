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
#include "py/runtime.h"

#include "pico/util/queue.h"
#include "pico/binary_info.h"
#include "pico/util/datetime.h"
#include "hardware/spi.h"

#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "project_pico_libs/backscatter.h"
#include "project_pico_libs/packet_generation.h"

#define TX_DURATION            350 // send a packet every 250ms (when changing baud-rate, ensure that the TX delay is larger than the transmission time)
#define RECEIVER              2500 // define the receiver board either 2500 or 1352
#define PIN_TX1                 5
#define PIN_TX2                 27
#define CLOCK_DIV0              20 // larger
#define CLOCK_DIV1              18 // smaller
#define DESIRED_BAUD        100000
#define BUFFERLENGTH            10
#define TWOANTENNAS           true

//  SETUP   ///////////////////////////////////////////////////////////////////////////

static mp_obj_t setup_BT(void) {
    //backscatter_tag_setup();
    stdio_init_all();
    
    /* setup backscatter state machine */
    PIO pio = pio0;
    uint sm = 0;
    struct backscatter_config backscatter_conf;
    uint16_t instructionBuffer[32] = {0}; // maximal instruction size: 32
    backscatter_program_init(pio, sm, PIN_TX1, PIN_TX2, CLOCK_DIV0, CLOCK_DIV1, DESIRED_BAUD, &backscatter_conf, instructionBuffer, TWOANTENNAS);

    return 0;
    mp_printf(&mp_plat_print, "Setup Done\n");
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(setup_BT_obj, setup_BT);


//  SEND   ///////////////////////////////////////////////////////////////////////////

static mp_obj_t send_BT(mp_obj_t heap) {
    
    //  Check if the length of the message is ok
    const char *message_python = mp_obj_str_get_str(heap);
    if (strlen(message_python) > PAYLOADSIZE) {
        mp_printf(&mp_plat_print, "(!) Error : payload size should be smaller than %u bytes\n",(int) PAYLOADSIZE);
        return mp_const_none;
    }

    static uint8_t message[buffer_size(PAYLOADSIZE+2, HEADER_LEN)*4] = {0};  // include 10 header bytes
    static uint32_t buffer[buffer_size(PAYLOADSIZE, HEADER_LEN)] = {0}; // initialize the buffer
    static uint8_t seq = 0;
    uint8_t *header_tmplate = packet_hdr_template(RECEIVER);
    uint8_t tx_payload_buffer[PAYLOADSIZE];
    PIO pio = pio0;
    uint sm = 0;

    //Generate message
    char message_text[(int8_t) strlen(message_python)];
    memcpy(message_text, message_python, strlen(message_python)+1);

    /* generate new data */
    generate_data(tx_payload_buffer, PAYLOADSIZE, true);

    // add header (10 byte) to packet
    add_header(&message[0], seq, header_tmplate,strlen(message_python));
    // add payload to packet
    for (uint8_t i=0; i < ((uint8_t) sizeof(message_text)); i++)
        memcpy(&message[i+BUFFERLENGTH], &message_text[i], sizeof(char));
    /* casting for 32-bit fifo */
    for (uint8_t i=0; i < buffer_size(PAYLOADSIZE, HEADER_LEN); i++) {
    buffer[i] = ((uint32_t) message[4*i+3]) | (((uint32_t) message[4*i+2]) << 8) | (((uint32_t) message[4*i+1]) << 16) | (((uint32_t)message[4*i]) << 24);
    }

    /* put the data to FIFO (start backscattering) */
    backscatter_send(pio,sm,buffer,buffer_size(PAYLOADSIZE, HEADER_LEN));
    sleep_ms(ceil((((double) buffer_size(PAYLOADSIZE, HEADER_LEN))*8000.0)/((double) DESIRED_BAUD))+3); // wait transmission duration (+3ms)
        
    /* increase seq number*/ 
    seq++;
    if(seq==255)
        seq = 0;

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(send_BT_obj, send_BT);

static const mp_rom_map_elem_t backscatter_tag_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__),            MP_ROM_QSTR(MP_QSTR_backscatter_tag) },
    { MP_ROM_QSTR(MP_QSTR_setup_BT),            MP_ROM_PTR(&setup_BT_obj) },
    { MP_ROM_QSTR(MP_QSTR_send_BT),             MP_ROM_PTR(&send_BT_obj) },
};
static MP_DEFINE_CONST_DICT(backscatter_tag_module_globals, backscatter_tag_module_globals_table);


const mp_obj_module_t mp_module_backscatter_tag = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&backscatter_tag_module_globals,
};
MP_REGISTER_MODULE(MP_QSTR_backscatter_tag, mp_module_backscatter_tag);
