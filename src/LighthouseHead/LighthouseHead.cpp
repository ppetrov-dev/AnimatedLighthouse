#include "LighthouseHead.h"

LighthouseHead::LighthouseHead(byte firstPin, byte sectionCount)
{
    _firstPin = firstPin;
    _sectionCount = sectionCount;
}
void LighthouseHead::LightNext(State state)
{
    if(state == On)
    {
        SwitchOn();
        return;
    }
    else if(state == Off){
        SwitchOff();
        return;
    }

    auto nextIndex = _currentIndex + 1;
    if (nextIndex == _sectionCount)
        nextIndex = 0;

    SwitchOn(_firstPin + nextIndex);
    SwitchOff(_firstPin + _currentIndex);

    _currentIndex = nextIndex;
}
void LighthouseHead::SwitchOff(byte pin)
{
    pinMode(pin, LOW);
}

void LighthouseHead::SwitchOff()
{
    for (byte i = 0; i < _sectionCount; i++)
        SwitchOff(_firstPin + i);
}

void LighthouseHead::SwitchOn(byte pin)
{
    pinMode(pin, HIGH);
}

void LighthouseHead::SwitchOn()
{
    for (byte i = 0; i < _sectionCount; i++)
        SwitchOn(_firstPin + i);
}