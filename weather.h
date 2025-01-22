#ifndef WEATHER_H
#define WEATHER_H
#include <Arduino.h>

struct weatherInfo
{
    int temp;
    String description;
};

extern weatherInfo w1;
extern String city;

void getWeatherInfo();
float kalvinToCelsius(float);
#endif