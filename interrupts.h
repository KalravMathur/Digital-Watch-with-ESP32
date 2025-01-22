#ifndef INTERRUPTS_H
#define INTERRUPTS_H
#include <Arduino.h>

struct Button
{
    const int PIN;
    bool isPressed;
    unsigned long lastPress;
};

extern Button b1;
extern Button b2;
extern Button b3;

// Function prototypes
void IRAM_ATTR interruptB1();
void IRAM_ATTR interruptB2();
void IRAM_ATTR interruptB3();
#endif