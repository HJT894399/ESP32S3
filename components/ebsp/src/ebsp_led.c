#include "ebsp_led.h"
#include "driver/gpio.h"
void led_config(void)
{
    gpio_config_t ledio = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1 << GPIO_NUM_1,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
    };
    gpio_config(&ledio);
    gpio_set_level(GPIO_NUM_1, 1);
}

void led_set(uint8_t state)
{
    gpio_set_level(GPIO_NUM_1, state);

}

void led_init(void)
{
    led_config();
}