#include "ExceptionNoInstall.h"

ExceptionNoInstall::ExceptionNoInstall()
{
	_msg = "ERROR: Not installed yet";
}

const char* ExceptionNoInstall::what() const throw ()
{
    return _msg;
}