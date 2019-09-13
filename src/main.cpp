#include "settings.h"
#include "enums.h"

#include "MyTimer.h"
#include "Blinker/Blinker.h"
#include "OneButton.h"
#include "StateMachine/StateMachine.h"
#include "StateMachine/StateMachine.h"
#include "LighthouseHead/LighthouseHead.h"

StateMachine _stateMachine;
OneButton _button = OneButton(PIN_Button, true, true);

Blinker _redBlinker = Blinker(PIN_RedLight);
LighthouseHead _lighthouseHead = LighthouseHead(PIN_FirstSection, SectionCount);

MyTimer _redBlinkerWorkTimer;
MyTimer _redBlinkerWaitTimer;
MyTimer _lighthouseHeadTimer;

void AnimateRedBlinker()
{
  _redBlinkerWorkTimer.Start();
  _redBlinker.SwitchOn();
}

void SetupLighthouseHeadSpeed()
{
  _lighthouseHeadTimer.Stop();
  auto speedInMilliseconds = _stateMachine.GetStateSpeedInMilliseconds();
  _lighthouseHeadTimer.SetInterval(speedInMilliseconds);
}

void AnimateLighthouseHead()
{
  SetupLighthouseHeadSpeed();
  auto state = _stateMachine.GetState();
  _lighthouseHead.LightNext(state);
  _lighthouseHeadTimer.Start();
}

void OnRedBlinkerWorkTimeExpired()
{
  _redBlinkerWorkTimer.Stop();
  _redBlinkerWaitTimer.Start();
  _redBlinker.SwitchOff();
}

void OnRedBlinkerWaitTimeExpired()
{
  _redBlinkerWaitTimer.Stop();
  AnimateRedBlinker();
}

void OnButtonClick()
{
  _stateMachine.MoveToNextState();
}

void OnButtonDoubleClick()
{
  _stateMachine.MoveToPreviousState();
}

void OnStateMachineStateChanged()
{
  AnimateLighthouseHead();
}

void OnLighthouseHeadTick()
{
  auto state = _stateMachine.GetState();
  _lighthouseHead.LightNext(state);
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

  _redBlinker.Init();
  _lighthouseHead.Init();
  _lighthouseHeadTimer.AttachOnTick(&OnLighthouseHeadTick);

  AnimateLighthouseHead();
  AnimateRedBlinker();
}

void loop()
{
  _button.tick();

  _redBlinkerWorkTimer.Tick();
  _redBlinkerWaitTimer.Tick();
  _lighthouseHeadTimer.Tick();
}