/**
 * @file wifi.h
 * @author Sam Sui
 * @brief Defines WiFi helper functions for error checking and WiFi information
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SUICHAT_WIFI_H
#define SUICHAT_WIFI_H

#include <WiFiNINA.h>

extern boolean already_connected;

extern int status;

extern WiFiServer server;

/**
 * @brief Checks if the device has a wifi module
 * 
 */
extern void wifi_module_check(void);

/**
 * @brief Checks the wifi module's firmware version and recommends an update if needed
 * 
 */
extern void wifi_firmware_check(void);

/**
 * @brief Repeatedly tries to connect to the given wifi network
 * 
 */
extern void wifi_connect(void);

/**
 * @brief Prints connected wifi network details
 * 
 */
extern void wifi_info(void);

#endif // SUICHAT_WIFI_H