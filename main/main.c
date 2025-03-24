#include "common_header.h"
#include "ebsp.h"

static TaskHandle_t task_handle[5];

void led_task(void *param)
{
    bool led_level = 0;
    while (1)
    {
        led_level = !led_level;
        led_set(led_level);
        osDelay(500);
    }
}

void create_task(void *param)
{
    ebsp_init();
    //运行灯
    xTaskCreatePinnedToCore(led_task, "LED_TASK", configMINIMAL_STACK_SIZE * 2, NULL, 5, &task_handle[1], 1);
    vTaskDelete(NULL);
}

void app_main(void)
{
    xTaskCreatePinnedToCore(create_task, "CREATE_TASK", configMINIMAL_STACK_SIZE * 2, NULL, 5, &task_handle[0], 1);
    // vTaskStartScheduler(); 
}
