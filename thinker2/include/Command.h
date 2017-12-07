#ifndef COMMAND_H_
#define COMMAND_H_
#include <ICommand.h>

using namespace std;

class Command : public ICommand
{
public:
	string _valueOption;
	bool _optionState;
    OptionParser _optionParser;

	virtual void CreateCommand() = 0;
    virtual void ExecuteCommand(Newbie& newbie) = 0;
    
};
#endif //  COMMAND_H_