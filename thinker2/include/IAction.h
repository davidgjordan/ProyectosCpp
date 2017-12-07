#ifndef IACTION_H_
#define IACTION_H_

#include <Defines.h>
#include <vector>
#include <cstdio>

using namespace std;

template<typename T>
class IAction
{
public:
    virtual T ProcessingAction(long int action)=0;
    virtual void SetAction(vector<double> key)=0;
    virtual vector<double> GetAction()=0;
};

#endif // IACTION_H_

