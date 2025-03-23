#ifndef __COMMON_HEADER_H
#define __COMMON_HEADER_H
/* 标准库头文件 */
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

/* FreeRTOS 核心头文件 */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"

/* FreeRTOS 配置头文件 */
#include "FreeRTOSConfig.h"

/* 调试输出宏 */
#define TASK_DEBUG(fmt, ...) \
    printf("[%s] " fmt "\n", pcTaskGetName(NULL), ##__VA_ARGS__)

/* 安全延时宏 */
inline void osDelay(uint32_t ms) {
    vTaskDelay(pdMS_TO_TICKS(ms));
}

/* 临界区保护宏 */
#define ENTER_CRITICAL() taskENTER_CRITICAL()
#define EXIT_CRITICAL()  taskEXIT_CRITICAL()
#endif