#ifndef ICOMMAND_H_
#define ICOMMAND_H_
#include <OptionParser.h>
#include <NewbieDTO.h>
#include <Newbie.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

class ICommand
{
public:
	virtual void CreateCommand() = 0;
    virtual void ExecuteCommand(Newbie& a) = 0;	
};
#endif //  ICOMMAND_H_