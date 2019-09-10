#include "StateMachine.h"

State StateMachine::GetNextState()
{
    switch (_state)
    {
    case AnimateNormal:
        return AnimateSlow;
    case AnimateSlow:
        return AnumateFast;
    case AnumateFast:
        return AnimateNormal;
    }
    return AnimateNormal;
}
State StateMachine::GetPreviousState()
{
    switch (_state)
    {
    case AnimateNormal:
        return AnumateFast;
    case AnimateSlow:
        return AnimateNormal;
    case AnumateFast:
        return AnimateSlow;
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