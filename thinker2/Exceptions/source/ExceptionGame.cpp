#include <ExceptionGame.h>
ExceptionGame::ExceptionGame()
{
	_msg = "Not Matchs Found for the Specified Game";
}
const char* ExceptionGame::what() const throw ()
{
    return _msg;
}