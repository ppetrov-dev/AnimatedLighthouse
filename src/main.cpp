#include <Arduino.h>
#include "settings.h"

#include "MyTimer.h"
#include "Blinker/Blinker.h"
#include "OneButton.h"
#include "Lighthouse/Lighthouse.h"

OneButton _button = OneButton(PIN_Button, true, true);
Lighthouse _lighthouse;

Blinker _redBlinker = Blinker(PIN_RedLight);
MyTimer _redBlinkerWorkTimer;
MyTimer _redBlinkerWaitTimer;

void OnRedBlinkerWorkTimeExpired(){
  _redBlinkerWorkTimer.Stop();
  _redBlinkerWaitTimer.Start();
  _redBlinker.SwithOff();
}

void OnRedBlinkerWaitTimeExpired(){
  _redBlinkerWaitTimer.Stop();
  AnimateRedBlinker();
}

void AnimateRedBlinker(){
  _redBlinkerWorkTimer.Start();
  _redBlinker.SwithOn();
}

void setup()
{
  pinMode(PIN_Button, INPUT_PULLUP);

  _redBlinkerWorkTimer.SetInterval(RedBlinkerWorkTimeInMilliseconds);
  _redBlinkerWorkTimer.AttachOnTick(&OnRedBlinkerWorkTimeExpired);
  _redBlinkerWaitTimer.SetInterval(RedBlinkerWaitTimeInMilliseconds);
  _redBlinkerWorkTimer.AttachOnTick(&OnRedBlinkerWaitTimeExpired);
  
  AnimateRedBlinker();
}

void loop()
{
  _button.tick();
  _lighthouse.Tick();

  _redBlinkerWorkTimer.Tick();
  _redBlinkerWaitTimer.Tick();
}