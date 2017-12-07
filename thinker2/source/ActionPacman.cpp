#include <ActionPacman.h>
#include <iostream>

ActionPacman::ActionPacman()
{
    
}

void ActionPacman::SetActionsValues(const string& NNWeigths)
{
    Json jsonWeigths;
    ifstream dataStream {NNWeigths};
    dataStream >> jsonWeigths;

    string keyboardType = jsonWeigths[KEYBOARD];
    dataStream.close();

    _controller = {"MsPacman-ram-v0", "./Configuration/keyControlsA.json", keyboardType};
}

float ActionPacman::ProcessingAction(long int action)
{
    return (float)action;
}

ActionPacman::~ActionPacman()
{

}

void ActionPacman::SetAction(vector<double> action)
{
	_key = action;
}

vector<double> ActionPacman::GetAction()
{
	return _key;
}

float ActionPacman::GetMovement(vector<double> neuralOutput)
{
    int i;
    for(i = 0;i<neuralOutput.size();i++)
    {
        if(neuralOutput[i]==1)
            break;
    }
    return _controller.GetAction(i);
}