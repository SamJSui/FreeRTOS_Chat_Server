/**
 * @file rtos.h
 * @author Sam Sui
 * @brief Defines functions to create FreeRTOS tasks for the scheduler
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SUICHAT_RTOS_H
#define SUICHAT_RTOS_H

#include "wifi.h"

#include <FreeRTOS_SAMD21.h>

extern TaskHandle_t handle_client_loop;

extern void client_loop(void *pvParameters);

#endif // SUICHAT_RTOS_H