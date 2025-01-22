#include "menus.h"
#include "interrupts.h"
#include "oledDisplay.h"
#include "timeDataClass.h"
#include "weather.h"
#include <Arduino.h>

// put function declarations here:
timeDataApi timeApi;

void menuSelect()
{
    if (b1.isPressed)
    {
        b1.isPressed = false;
        stopWatch();
    }
    else if (b2.isPressed)
    {
        b2.isPressed = false;
        timer();
    }
    else if (b3.isPressed)
    {
        b3.isPressed = false;
        weather();
    }
    else
    {
        home();
    }
}

void home()
{
    timeApi.updateTimeInfo();
    displayHome(timeApi.t1.hours, timeApi.t1.mins, timeApi.d1.date, timeApi.d1.month, timeApi.d1.year, timeApi.d1.day);
}

void stopWatch()
{
    delay(200);
    timeApi.stopWatchInterface();
}
void timer()
{
    delay(200);
    timeApi.timerInterface();
}
void weather()
{
    getWeatherInfo();
    while (!b3.isPressed) // keep showing untill back is pressed
    {
        displayWeather(w1.temp, w1.description);
    }
    b3.isPressed = false; // reset all flags
    b2.isPressed = false;
    b1.isPressed = false;
}