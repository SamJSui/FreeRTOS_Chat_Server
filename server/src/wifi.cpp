/**
 * @file wifi.c
 * @author Sam Sui
 * @brief Defines WiFi module helper functions for error checking or WiFi information
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "wifi.h"
#include "wifi_secrets.h"

WiFiServer server(23);
int status = WL_IDLE_STATUS;
boolean already_connected = false;

void wifi_module_check(void) {
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        while (true);
    }
}

void wifi_firmware_check(void) {
    String fv = WiFi.firmwareVersion();
    if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }
}

void wifi_connect(void) {
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(wifi_ssid);
        status = WiFi.begin(wifi_ssid, wifi_password);
        // wait 10 seconds for connection:
        delay(10000);
    }
    server.begin();
}

void wifi_info(void) {
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}