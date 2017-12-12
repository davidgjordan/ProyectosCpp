#ifndef COMMANDINSTALL_H_
#define COMMANDINSTALL_H_

#include <Command.h>

class CommandInstall : public Command
{
public:
	CommandInstall(int argc, const char** argv);
	void CreateCommand()override;
    void ExecuteCommand(Newbie& newbie)override;
    ~CommandInstall();	
};
#endif //  COMMANDINSTALL_H_