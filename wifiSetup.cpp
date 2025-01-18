#include "wifiSetup.h"
#include <Arduino.h>

const char *WIFI_SSID = "YOUR_SSID";
const char *WIFI_PASS = "YOUR_PASSWORD";

void connectToWiFi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Unable to connect to wifi");
        delay(1000);
    }
    delay(100);
    Serial.println("wifi connected");
}
