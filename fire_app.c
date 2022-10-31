#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "fire.h"

void read_message(uint8_t *data, uint32_t size);
uint8_t write_byte(uint8_t byte);

static uint8_t buf[100];

static const 