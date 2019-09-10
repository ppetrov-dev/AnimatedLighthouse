#ifndef blinkerH
#define blinkerH
#include "MyTimer.h"
#include "Arduino.h"

class Blinker
{
private:
    byte _pin = 0;
    bool _isStarted = false;
    bool _isOn = false;

public:
    Blinker(byte pin);

    void SwithOn();
    void SwithOff();

    bool GetIsOn();
};

#endif // !blinkerH
