#include "StateMachine.h"

State StateMachine::GetNextState()
{
    switch (_state)
    {
    case AnimateVerySlow:
        return AnimateSlow;
    case AnimateSlow:
        return AnimateNormal;
    case AnimateNormal:
        return AnimateFast;
    case AnimateFast:
        return AnimateVeryFast;
    case AnimateVeryFast:
        return AnimateSuperFast;
    case AnimateSuperFast:
        return AnimateVerySlow;

    case On:
    case Off:
        return AnimateNormal;
    }
    return AnimateNormal;
}
State StateMachine::GetPreviousState()
{
    switch (_state)
    {
    case AnimateVerySlow:
        return AnimateSuperFast;
    case AnimateSlow:
        return AnimateVerySlow;
    case AnimateNormal:
        return AnimateSlow;
    case AnimateFast:
        return AnimateNormal;
    case AnimateVeryFast:
        return AnimateFast;
    case AnimateSuperFast:
        return AnimateVeryFast;
    case On:
    case Off:
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
    case AnimateVerySlow:
        return VerySlowSpeedInMilliseconds;
    case AnimateSlow:
        return SlowSpeedInMilliseconds;
    case AnimateNormal:
        return NormalSpeedInMilliseconds;
    case AnimateFast:
        return FastSpeedInMilliseconds;
    case AnimateVeryFast:
        return VeryFastSpeedInMilliseconds;
    case AnimateSuperFast:
        return SuperFastSpeedInMilliseconds;
        
    case On:
    case Off:
        return OnAndOffSpeedInMilliseconds;
    }

    return NormalSpeedInMilliseconds;
}
