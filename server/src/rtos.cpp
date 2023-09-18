/**
 * @file rtos.c
 * @author Sam Sui
 * @brief Defines routines to pass into FreeRTOS task threads
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "rtos.h"

void client_loop(void *pvParameters) {
    Serial.println("Client Loop started");
    while (1) {
        WiFiClient client = server.available();
        if (client) {
            if (!already_connected) {
                client.flush();
                Serial.println("We have a new client");
                client.println("Hello, client!");
                already_connected = true;
            }
            if (client.available() > 0) {
                char thisChar = client.read();
                server.write(thisChar);
                // Serial.write(thisChar);
            }
        }
    }
}