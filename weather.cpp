#include "weather.h"
#include <HTTPClient.h>
#include <Arduino_JSON.h>
HTTPClient http;
weatherInfo w1;
const String openWeatherApiKey = "API_KEY";
String city = "CITY";
String countryCode = "REGION";
String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherApiKey;
String jsonBuffer;

String httpGETRequest(const char *serverName)
{
    // Your Domain name with URL path or IP address with path
    http.begin(serverName);

    // Send HTTP POST request
    int httpResponseCode = http.GET();

    String payload = "{}";

    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    }
    else
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();

    return payload;
}
void getWeatherInfo()
{
    jsonBuffer = httpGETRequest(serverPath.c_str());
    Serial.println(jsonBuffer);
    JSONVar tempData = JSON.parse(jsonBuffer);
    if (JSON.typeof(tempData) == "undefined")
    {
        Serial.println("Parsing input failed!");
        return;
    }
    w1.temp = (int)kalvinToCelsius((double)tempData["main"]["temp"]);
    w1.description = (const char *)tempData["weather"][0]["description"];
}

float kalvinToCelsius(float k)
{
    float c = (k - 273.15);
    return c;
}
