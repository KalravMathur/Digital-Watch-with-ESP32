#include "oledDisplay.h"
#include "weather.h"
#define leftX 0
#define rightX 105
#define topY 0
#define bottomY 56

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int calculateMidX(int len, int size)
{
    int pix = size * 5 * len + size * (len - 1);
    return (128 - pix) / 2;
}
int calculateMidY(int len, int size)
{
    int pix = size * 7;
    return (64 - pix) / 2;
}
void displayHome(int hr, int min, int dd, int mm, int yy, String day)
{
    display.clearDisplay();
    // time
    display.setTextSize(2);
    display.setCursor(calculateMidX(5, 2), calculateMidY(5, 2));
    display.printf("%02d:%02d", hr, min);

    // date
    display.setTextSize(1);
    display.setCursor(leftX, topY);
    display.printf("%02d.%02d.%02d", dd, mm, yy);

    // day
    display.setTextSize(1);
    display.setCursor(111, topY);
    display.print(day);

    // menus
    display.setTextSize(1);
    display.setCursor(leftX, bottomY);
    display.print("StopW");
    display.setCursor(calculateMidX(5, 1), bottomY);
    display.print("Timer");
    display.setCursor(rightX, bottomY);
    display.print("Temp");

    display.display();
}

void displayStopWatch(int sec)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(calculateMidX(10, 1), topY);
    display.print("Stop Watch");

    display.setTextSize(2);
    display.setCursor(calculateMidX(2, 2), calculateMidY(2, 2));
    display.printf("%02d", sec);

    display.setTextSize(1);
    display.setCursor(leftX, bottomY);
    display.print("Start");
    display.setCursor(rightX, bottomY);
    display.print("Back");
    display.display();
}
void displayTimer(int sec)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(calculateMidX(5, 1), topY);
    display.print("Timer");

    display.setTextSize(2);
    display.setCursor(calculateMidX(2, 2), calculateMidY(2, 2));
    display.printf("%02d", sec);

    display.setTextSize(1);
    display.setCursor(leftX, bottomY);
    display.print("Start");
    display.setCursor(calculateMidX(3, 1), bottomY);
    display.print("+10");
    display.setCursor(rightX, bottomY);
    display.print("Back");
    display.display();
}
void displayWeather(int temp, String desc)
{
    display.clearDisplay();
    // top bar
    display.setTextSize(1);
    display.setCursor(calculateMidX(7, 1), topY);
    display.print("Weather");

    // city
    display.setCursor(leftX, 15);
    display.print(city);
    // temp
    display.setTextSize(2);
    display.setCursor(calculateMidX(2, 2), calculateMidY(2, 2));
    display.printf("%02d", temp);
    // degree symbol
    display.setTextSize(1);
    display.setCursor(78, 21);
    display.print("o");
    // weather description
    display.setTextSize(1);
    display.setCursor(calculateMidX(desc.length(), 1), 43);
    display.print(desc);
    // back button
    display.setCursor(rightX, bottomY);
    display.print("Back");
    display.display();
}
void loadAnimation()
{
    for (int i = 0; i <= 33; i++)
    {
        display.clearDisplay();

        display.setCursor(calculateMidX(13, 1), calculateMidY(13, 1));
        display.setTextSize(1);
        display.print("Digital Watch");

        display.setCursor(leftX, bottomY);
        display.print("Made by K.M.");

        display.fillRect(0, -1, 128, 33 - i, SH110X_WHITE);
        display.fillRect(0, 32 + i, 128, 32, SH110X_WHITE);
        display.display();
        delay(50);
    }
}
