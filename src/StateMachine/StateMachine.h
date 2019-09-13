#ifndef stateMachineH
#define stateMachineH

#include "enums.h"
#include "settings.h"

extern "C"
{
    typedef void (*stateMachineCallback)(void);
}

class StateMachine
{
private:
    State _state = AnimateNormal;
    stateMachineCallback _stateChangedCallback;
    State GetNextState();
    State GetPreviousState();
    void SetState(State newState);

public:
    void MoveToNextState();
    void MoveToPreviousState();
    State GetState();
    unsigned long GetStateSpeedInMilliseconds();
    void AttachOnStateChanged(stateMachineCallback callback);
};

#endif // !stateMachineH
