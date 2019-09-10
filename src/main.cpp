#include <Arduino.h>
#include "settings.h"
#include "enums.h"

#include "MyTimer.h"
#include "Blinker/Blinker.h"
#include "OneButton.h"
#include "StateMachine/StateMachine.h"

OneButton _button = OneButton(PIN_Button, true, true);

Blinker _redBlinker = Blinker(PIN_RedLight);
MyTimer _redBlinkerWorkTimer;
MyTimer _redBlinkerWaitTimer;

StateMachine _stateMachine;

MyTimer _timer;

void AnimateRedBlinker()
{
  _redBlinkerWorkTimer.Start();
  _redBlinker.SwithOn();
}

void OnRedBlinkerWorkTimeExpired()
{
  _redBlinkerWorkTimer.Stop();
  _redBlinkerWaitTimer.Start();
  _redBlinker.SwithOff();
}

void OnRedBlinkerWaitTimeExpired()
{
  _redBlinkerWaitTimer.Stop();
  AnimateRedBlinker();
}

void OnButtonClick(){
  _stateMachine.MoveToNextState();
}

void OnButtonDoubleClick(){
  _stateMachine.MoveToPreviousState();
}

void OnStateMachineStateChanged(){

}

void setup()
{
  pinMode(PIN_Button, INPUT_PULLUP);

  _stateMachine.AttachOnStateChanged(&OnStateMachineStateChanged);

  _button.attachClick(&OnButtonClick);
  _button.attachDoubleClick(&OnButtonDoubleClick);

  _redBlinkerWorkTimer.SetInterval(RedBlinkerWorkTimeInMilliseconds);
  _redBlinkerWorkTimer.AttachOnTick(&OnRedBlinkerWorkTimeExpired);
  _redBlinkerWaitTimer.SetInterval(RedBlinkerWaitTimeInMilliseconds);
  _redBlinkerWorkTimer.AttachOnTick(&OnRedBlinkerWaitTimeExpired);

  AnimateRedBlinker();
}

void loop()
{
  _button.tick();

  _redBlinkerWorkTimer.Tick();
  _redBlinkerWaitTimer.Tick();
}