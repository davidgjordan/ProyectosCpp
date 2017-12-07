#include <iostream>
#include <ICommand.h>
#include <CommandNewbie.h>
#include <Command.h>
#include <Newbie.h>
#include <exception>

int main(int argc, const char* argv[])
{
	Newbie newbie;
    ICommand* command = new CommandNewbie(argc, argv);

	try
	{
	    command->ExecuteCommand(newbie);
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}

	delete command;
    return 0;
}