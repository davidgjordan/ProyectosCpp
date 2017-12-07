#ifndef STEPPACMAN_H_
#define STEPPACMAN_H_

#include <ActionPacman.h>
#include <IStep.h>
#include <iostream>

class StepPacman: public IStep
{
    IGameModel* _model;
    // cannot declare parameter action to be of abstract type IAction<double>
    // IAction<double> _action;
    ActionPacman* _action;

    public:
        
        void SetModel(IGameModel* model) override;
        void SetAction(void* action) override;
        IGameModel* GetModel() override;
        ActionPacman* GetAction();


};

#endif //STEPPACMAN_H_