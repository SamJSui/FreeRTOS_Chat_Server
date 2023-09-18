/**
 * @file delay.c
 * @author Sam Sui
 * @brief Defines FreeRTOS-native delay functions
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "delay.h"

void delay_us(int us) {
    vTaskDelay( us / portTICK_PERIOD_US );  
}

void delay_ms(int ms) {
    vTaskDelay( (ms * 1000) / portTICK_PERIOD_US );  
}

void delay_ms_until(TickType_t *previous_waketime, int ms) {
    vTaskDelayUntil( previous_waketime, (ms * 1000) / portTICK_PERIOD_US );  
}