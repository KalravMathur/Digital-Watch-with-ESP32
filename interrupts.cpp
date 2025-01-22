#include "interrupts.h"

// Define buttons
Button b1 = {19, false, 0};
Button b2 = {18, false, 0};
Button b3 = {5, false, 0};

unsigned long currentPress = 0;
const int debouncingDelay = 250;

void IRAM_ATTR interruptB1()
{
    currentPress = millis();
    if (currentPress - b1.lastPress > debouncingDelay)
    {
        b1.lastPress = currentPress;
        b1.isPressed = true;
    }
}
void IRAM_ATTR interruptB2()
{
    currentPress = millis();
    if (currentPress - b2.lastPress > debouncingDelay)
    {
        b2.lastPress = currentPress;
        b2.isPressed = true;
    }
}
void IRAM_ATTR interruptB3()
{
    currentPress = millis();
    if (currentPress - b3.lastPress > debouncingDelay)
    {
        b3.lastPress = currentPress;
        b3.isPressed = true;
    }
}