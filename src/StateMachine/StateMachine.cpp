#include "StateMachine.h"

State StateMachine::GetNextState()
{
    switch (_state)
    {
    case AnimateNormal:
        return AnimateSlow;
    case AnimateSlow:
        return AnimateFast;
    case AnimateFast:
        return On;
    case On:
        return Off;
    case Off:
        return AnimateNormal;
    }
    return AnimateNormal;
}
State StateMachine::GetPreviousState()
{
    switch (_state)
    {
    case AnimateNormal:
        return Off;
    case Off:
        return On;
    case On:
        return AnimateFast;
    case AnimateFast:
        return AnimateSlow;
    case AnimateSlow:
        return AnimateNormal;
    }
    return AnimateNormal;
}

void StateMachine::SetState(State newState)
{
    if (_state == newState)
        return;

    _state = newState;

    if (_stateChangedCallback)
        _stateChangedCallback();
}

void StateMachine::MoveToNextState()
{
    SetState(GetNextState());
}
void StateMachine::MoveToPreviousState()
{
    SetState(GetPreviousState());
}
State StateMachine::GetState()
{
    return _state;
}
void StateMachine::AttachOnStateChanged(stateMachineCallback callback)
{
    _stateChangedCallback = callback;
}
unsigned long StateMachine::GetStateSpeedInMilliseconds()
{
    switch (_state)
    {
    case AnimateSlow:
        return SlowSpeedInMilliseconds;
    case AnimateNormal:
        return NormalSpeedInMilliseconds;
    case AnimateFast:
        return FastSpeedInMilliseconds;
    case On:
    case Off:
        return OnAndOffSpeedInMilliseconds;
    }

    return NormalSpeedInMilliseconds;
}
