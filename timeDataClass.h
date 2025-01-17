#ifndef TIMEDATACLASS_H
#define TIMEDATACLASS_H

#include <Arduino.h>

class timeDateApi
{
private:
    struct time
    {
        int hours;
        int mins;
        int secs;
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
};

#endif // TIMEDATACLASS_H