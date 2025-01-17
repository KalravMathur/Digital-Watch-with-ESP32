#include "wifiSetup.h"
#include <Arduino.h>

const char *WIFI_SSID = "kalrav";
const char *WIFI_PASS = "9634593284";

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
