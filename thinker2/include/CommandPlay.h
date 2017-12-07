#ifndef COMMANDPLAY_H_
#define COMMANDPLAY_H_

#include <Command.h>

class CommandPlay : public Command
{
	string _nameGame;
    string _keysConfig = "A";
    bool _saveActionNone = true;
public:
	CommandPlay(int argc, const char** argv);
	void CreateCommand()override;
    void ExecuteCommand(Newbie& newbie)override;
    ~CommandPlay();
};
#endif //  COMMANDPLAY_H_