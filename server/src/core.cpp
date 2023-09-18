/**
 * @file core.cpp
 * @author Sam Sui
 * @brief Defines Serial, WiFi, and FreeRTOS setup upon upload to microcontroller
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "core.h"

TaskHandle_t handle_client_loop;

void setup() {
    Serial.begin(9600);
    delay(1000);
    while(!Serial);

    vSetErrorSerial(&Serial);

    /* Boot Message */
    Serial.println("Suichat Server booted");

    /* Wifi checks and information */
    wifi_module_check();
    wifi_firmware_check();
    wifi_connect();
    wifi_info();
    delay(1000);

    /* Scheduled Tasks */
    xTaskCreate(client_loop, "Client Loop", 256, NULL, tskIDLE_PRIORITY + 1, &handle_client_loop);
    Serial.println("Tasks Created");
    Serial.flush();

    /* Function should never return and will schedule tasks */
    vTaskStartScheduler();

    /* Error: Scheduler failed to started */
    while(1) {
        Serial.println("Scheduler Failed\n");
        Serial.flush();
        delay(1000);
    }
}

void loop() {
    Serial.println("RTOS in Idle State");
    Serial.flush();
    delay(1000);
}