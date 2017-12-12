#ifndef COMMANDEVALUATE_H_
#define COMMANDEVALUATE_H_
#include <Command.h>

class CommandEvaluate: public Command
{
	string _serverIP;
	string _NNWeights;
	string _typeMethod;
public:
	CommandEvaluate(int argc, const char** argv);
	void CreateCommand()override;
    void ExecuteCommand(Newbie& newbie)override;	
	~CommandEvaluate();
};

#endif //  COMMANDEVALUATE_H_