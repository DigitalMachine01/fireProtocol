#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "fire.h"

void read_message(uint8_t *data, uint32_t size);
uint8_t write_byte(uint8_t byte);

static uint8_t buf[100];

static const fire_packet_st fire = {
        .buf = buf,
        .bufsize = sizeof(buf),
        .crc_seed = 0xFFFF,
        .read_message = read_message,
        .write_byte = write_byte
};

static fire_packet_handler_st handler;

int main(void)
{
        fire_init(&handler, &fire);

        char *to_send = "Sumit";
        printf("SEND: %s\n", to_send);
        fire_send_packet(&handler, to_send, strlen(to_send));

        uint8_t emulated_rcv[] = {0xC0, 0x53, 0x75, 0x6D, 0x69, 0x74, 0x42, 0x47, 0xC0};
        for(uint8_t i = 0; i < sizeof(emulated_rcv); i++){
            uint8_t rx = emulated_rcv[i];
            printf("RX: %02X\n", rx);
            fire_read_byte(&handler, rx);
        }
        return 0;
}

void read_message(uint8_t *data, uint32_t size)
{
        char recv_buf[size + 1];

        memcpy(recv_buf, data, size);
        recv_buf[size] = 0;

        printf("RECV: %s\n", recv_buf);
}

uint8_t write_byte(uint8_t byte)
{
        printf("TX: %02X\n",  byte);
        return 1;
}