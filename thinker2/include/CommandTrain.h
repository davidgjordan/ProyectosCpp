#ifndef COMMANDTRAIN_H_
#define COMMANDTRAIN_H_

#include <Command.h>


class CommandTrain : public Command
{
	string _typeMethod;
	string _gameName;
	string _NNTopology;
	string _NNWeights;
	string _keysConfig = "A";
public:
	CommandTrain(int argc, const char** argv);
	void CreateCommand()override;
    void ExecuteCommand(Newbie& newbie)override;
    ~CommandTrain();	
	
};
#endif//COMMANDTRAIN_H_