#ifndef WIFISETUP_H
#define WIFISETUP_H

#include <WiFi.h>
// wifi credentials
extern const char* WIFI_SSID;
extern const char* WIFI_PASS;

// function
void connectToWiFi();

#endif