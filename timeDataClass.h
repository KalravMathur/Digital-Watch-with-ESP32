#ifndef TIMEDATACLASS_H
#define TIMEDATACLASS_H

#include <Arduino.h>

class timeDataApi
{
private:
    struct time
    {
        int hours;
        int mins;
    };
    struct date
    {
        int date;
        int month;
        int year;
        String day;
    };
    String dayToWord(int);

public:
    time t1, t2;
    date d1, d2;
    void updateTimeInfo();
    void stopWatchInterface();
    void timerInterface();
};

#endif // TIMEDATACLASS_H
