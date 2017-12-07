#ifndef STEP_H_
#define STEP_H_

#include <IGameModel.h>
#include <IAction.h>

class IStep
{
    public:
        virtual void SetModel(IGameModel* model) = 0;
        virtual void SetAction(void* action) = 0;
        virtual IGameModel* GetModel() = 0;
        // virtual IAction<T>* GetAction() = 0;
};

#endif //STEP_H_

