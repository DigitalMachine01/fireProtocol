/*
* Name: Fire Protocol
* Date: 13th September, 2022

The MIT License (MIT)

Copyright (c) 2017 Marcin Borowicz <marcinbor85@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 */

#ifndef _FIRE_H_
#define _FIRE_H_

#include <stdint.h>

#define FIRE_SPECIAL_BYTE_END       0xC0
#define FIRE_SPECIAL_BYTE_ESC       0xDB

#define FIRE_ESCAPED_BYTE_END       0xDC
#define FIRE_ESCAPED_BYTE_ESC       0xDD

typedef enum
{
        FIRE_STATE_NORMAL = 0X00,
        FIRE_STATE_ESCAPED
} fire_state_t;

typedef enum
{
        FIRE_NO_ERROR = 0x00,
        FIRE_ERROR_BUFFER_OVERFLOW,
        FIRE_ERROR_UNKNOWN_ESCAPED_BYTE,
        FIRE_ERROR_CRC_MISMATCH
} fire_error_t;

typedef struct
{
        uint8_t *buf;
        uint32_t bufsize;
        uint16_t crc_seed;

        void (*read_message)(uint8_t *data, uint32_t size);
        uint8_t (*write_byte)(uint8_t byte);
} fire_packet_st;

typedef struct
{
        fire_state_t state;
        uint32_t size;
        uint16_t crc;
        const fire_packet_st *fire;
}fire_packet_handler_st;

/* APIs*/

fire_error_t fire_init(fire_packet_handler_st *fire, const fire_packet_st *packet);
fire_error_t fire_read_byte(fire_packet_handler_st *fire, uint8_t byte);
fire_error_t fire_send_packet(fire_packet_handler_st *fire, uint8_t *pack, uint32_t size);

#endif /* _FIRE_H_ */