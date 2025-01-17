#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <WiFiUdp.h>
#include "timeDataClass.h"

// NTPClient setup
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000); // Time offset (3600 for GMT+1), update interval

void timeDateApi::updateTimeInfo()
{
    timeClient.update();
    unsigned long epochTime = timeClient.getEpochTime();

    t1.hours = hourFormat12(epochTime);
    t1.mins = minute(epochTime);
    t1.secs = second(epochTime);
    d1.date = day(epochTime);
    d1.day = dayToWord(weekday(epochTime));
    d1.month = month(epochTime);
    d1.year = year(epochTime) % 2000;
}

String timeDateApi::dayToWord(int n)
{
    String dayW;
    switch (n)
    {
    case 1:
        dayW = "Sunday";
        return (dayW);
    case 2:
        dayW = "Monday";
        return (dayW);
    case 3:
        dayW = "Tuesday";
        return (dayW);
    case 4:
        dayW = "Wednesday";
        return (dayW);
    case 5:
        dayW = "Thursday";
        return (dayW);
    case 6:
        dayW = "Friday";
        return (dayW);
    case 7:
        dayW = "Saturday";
        return (dayW);
    default:
        dayW = "invalid";
        return (dayW);
    }
}
