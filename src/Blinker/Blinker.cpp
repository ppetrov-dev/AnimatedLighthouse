#include "Blinker.h"

Blinker::Blinker(byte pin) : _pin(pin)
{
}
void Blinker::Init()
{
    pinMode(_pin, OUTPUT);
}
void Blinker::SwitchOn()
{
    digitalWrite(_pin, HIGH);
    _isOn = true;
}
void Blinker::SwitchOff()
{
    digitalWrite(_pin, LOW);
    _isOn = false;
}
bool Blinker::GetIsOn()
{
    return _isOn;
}