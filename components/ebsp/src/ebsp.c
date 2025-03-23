#include "ebsp.h"
#include "ebsp_led.h"

void ebsp_led_set(uint8_t led_state)
{
    led_set(led_state);
}

void ebsp_init(void)
{
    led_init();
}