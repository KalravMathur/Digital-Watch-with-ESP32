#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <WiFiUdp.h>
#include "timeDataClass.h"
#include "interrupts.h"
#include "oledDisplay.h"

// NTPClient setup
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000); // Time offset (3600 for GMT+1), update interval

#define apiInterval 10000 // internval in millis (10 sec)
unsigned int lastFetch = -apiInterval;

void timeDataApi::updateTimeInfo()
{
    unsigned int currentTime = millis();
    if (currentTime - lastFetch > apiInterval)
    {
        timeClient.update();
        lastFetch = currentTime;
        unsigned long epochTime = timeClient.getEpochTime();

        t1.hours = hourFormat12(epochTime);
        t1.mins = minute(epochTime);
        d1.date = day(epochTime);
        d1.day = dayToWord(weekday(epochTime));
        d1.month = month(epochTime);
        d1.year = year(epochTime) % 2000;
    }
}
String timeDataApi::dayToWord(int n)
{
    String dayW;
    switch (n)
    {
    case 1:
        dayW = "Sun";
        return (dayW);
    case 2:
        dayW = "Mon";
        return (dayW);
    case 3:
        dayW = "Tue";
        return (dayW);
    case 4:
        dayW = "Wed";
        return (dayW);
    case 5:
        dayW = "Thu";
        return (dayW);
    case 6:
        dayW = "Fri";
        return (dayW);
    case 7:
        dayW = "Sat";
        return (dayW);
    default:
        dayW = "invalid";
        return (dayW);
    }
}

#define start b1.isPressed
#define increment b2.isPressed
#define isBack b3.isPressed
#define MAX_INT 60
int sec = 0;

void timeDataApi::timerInterface()
{
    while (!isBack)
    {
        displayTimer(sec);
        if (increment)
        {
            increment = false;
            Serial.println("increment");
            sec = sec + 10;
        }

        else if (start)
        {
            Serial.println("start");
            start = false;

            for (int i = sec; i >= 0; i--)
            {
                if (isBack)
                {
                    sec = 0;
                    Serial.println("back to home");
                    isBack = false;
                    break;
                }
                displayTimer(i);
                delay(1000);
            }
            sec = 0;
        }
        delay(200);
    }
    sec = 0;
    isBack = false;
    return;
}

void timeDataApi::stopWatchInterface()
{
    while (!isBack)
    {
        displayStopWatch(0);
        if (start)
        {
            Serial.println("start");
            start = false;

            for (int i = 0; i <= MAX_INT; i++)
            {
                if (isBack)
                {
                    Serial.println("back to home");
                    isBack = false;
                    break;
                }
                displayStopWatch(i);
                delay(1000);
            }
        }
        delay(200);
    }
    isBack = false;
    return;
}
