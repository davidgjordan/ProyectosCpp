#ifndef ACTIONPACMAN_H_
#define ACTIONPACMAN_H_
#include <IAction.h>
#include <Controller.h>
#include <Defines.h>
#include <vector>
#include <cstdlib>


using namespace std;

class ActionPacman: public IAction<float>
{
    vector<double> _key;
	float _action;
    Controller _controller;
    
public:
    float ProcessingAction(long int action) override;
    float GetMovement(vector<double> neuralOutput);
    ActionPacman();
    ~ActionPacman();
    void SetAction(vector<double> action) override;
    void SetActionsValues(const string& NNWeigths);
    vector<double> GetAction() override;
};
#endif//ACTIONPACMAN_H_