#include "Blinker.h"

Blinker::Blinker(byte pin) : _pin(pin)
{
}
void Blinker::SwitchOn()
{
    pinMode(_pin, HIGH);
    _isOn = true;
}
void Blinker::SwitchOff()
{
    pinMode(_pin, LOW);
    _isOn = false;
}
bool Blinker::GetIsOn()
{
    return _isOn;
}