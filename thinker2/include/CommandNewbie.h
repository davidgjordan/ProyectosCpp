#ifndef COMMANDNEWBIE_H_
#define COMMANDNEWBIE_H_

#include <Command.h>

class CommandNewbie : public Command
{
    int _amount;
    const char** _values;
public:
    CommandNewbie(int argc, const char** argv);
    void CreateCommand()override;
    void ExecuteCommand(Newbie& newbie)override;
    void CreateOptionCommand(Newbie& newbie);
    ~CommandNewbie(); 
};
#endif //  COMMANDNEWBIE_H_