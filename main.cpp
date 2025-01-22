#include "oledDisplay.h"
#include "wifiSetup.h"
#include "menus.h"
#include "interrupts.h"
#include "weather.h"

void setup()
{
  Serial.begin(115200);

  // button interrupt setup
  pinMode(b1.PIN, INPUT_PULLUP);
  pinMode(b2.PIN, INPUT_PULLUP);
  pinMode(b3.PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(b1.PIN), interruptB1, FALLING);
  attachInterrupt(digitalPinToInterrupt(b2.PIN), interruptB2, FALLING);
  attachInterrupt(digitalPinToInterrupt(b3.PIN), interruptB3, FALLING);

  // display setup
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextWrap(false);

  loadAnimation();
  connectToWiFi();
  getWeatherInfo();
}

void loop()
{
  menuSelect();
}