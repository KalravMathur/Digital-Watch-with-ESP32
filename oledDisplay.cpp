#include "oledDisplay.h"
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displayTime(int hr, int min, int sec)
{
    display.setTextSize(1);
    display.setCursor(30, 10);
    display.printf("%02d:%02d:%02d", hr, min, sec);
}

void displayDate(int dd, int mm, int yy)
{
    display.setTextSize(1);
    display.setCursor(30, 30);
    display.printf("%02d/%02d/%02d", dd, mm, yy);
}

void displayDay(String day)
{
    display.setTextSize(1);
    display.setCursor(30, 50);
    display.print(day);
}