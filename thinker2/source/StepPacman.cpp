#include <StepPacman.h>

void StepPacman::SetModel(IGameModel* model)
{
    _model = model;
}

IGameModel* StepPacman::GetModel()
{
    return _model;
}

void StepPacman::SetAction(void* action)
{
    _action = (ActionPacman*) action;
}

ActionPacman* StepPacman::GetAction()
{
    return _action;
    
}
