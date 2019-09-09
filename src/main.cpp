#include <Arduino.h>
#include "settings.h"

#include "MyTimer.h"
#include "OneButton.h"
#include "Lighthouse/Lighthouse.h"

OneButton _button = OneButton(PIN_Button, true, true);
Lighthouse _lighthouse;

 void setup()
{
  pinMode(PIN_Button, INPUT_PULLUP);

  
}

void loop() {
  _button.tick();
  _lighthouse.Tick();
}