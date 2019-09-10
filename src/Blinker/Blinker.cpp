#include "Blinker.h"

Blinker::Blinker(byte pin) : _pin(pin)
{
}
void Blinker::SwithOn()
{
    pinMode(_pin, HIGH);
    _isOn = true;
}
void Blinker::SwithOff()
{
    pinMode(_pin, LOW);
    _isOn = false;
}
bool Blinker::GetIsOn()
{
    return _isOn;
}