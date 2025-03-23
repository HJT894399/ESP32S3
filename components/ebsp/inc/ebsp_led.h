#ifndef __EBSP_LED_H
#define __EBSP_LED_H
#include "common_header.h"

void led_config(void);
void led_set(uint8_t state);
void led_init(void);
#endif