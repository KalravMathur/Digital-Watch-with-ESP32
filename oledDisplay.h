#ifndef OLEDDISPLAY_H
#define OLEDDISPLAY_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// OLED display setup
#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define sclPin 23
#define sdaPin 22

extern Adafruit_SH1106G display;
void displayTime(int, int, int);
void displayDate(int, int, int);
void displayDay(String);
#endif