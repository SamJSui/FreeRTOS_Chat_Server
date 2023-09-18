/**
 * @file delay.h
 * @author Sam Sui
 * @brief Declares FreeRTOS-native delay functions
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SUICHAT_DELAY_H
#define SUICHAT_DELAY_H

#include <FreeRTOS_SAMD21.h>

/**
 * @brief 
 * 
 * @param us (microseconds)
 */
extern void delay_us(int us);

/**
 * @brief 
 * 
 * @param ms (milliseconds)
 */
extern void delay_ms(int ms);

/**
 * @brief 
 * 
 * @param previousWakeTime 
 * @param ms (milliseconds)
 */
extern void delay_ms_until(TickType_t *previous_waketime, int ms);

#endif // SUICHAT_DELAY_H