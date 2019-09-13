#ifndef lighthouseHeadH
#define lighthouseHeadH

#include <Arduino.h>
#include "enums.h"

class LighthouseHead
{
private:
    byte _firstPin;
    byte _sectionCount = 0;
    byte _currentIndex = 0;
    void SwitchOn(byte pin);
    void SwitchOff(byte pin);

    void SwitchOff();
    void SwitchOn();

public:
    LighthouseHead(byte firstPin, byte sectionCount);
    void Init();
    void LightNext(State state);
};
#endif // !lighthouseHeadH
