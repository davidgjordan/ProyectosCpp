#include "ExceptionNoPath.h"

ExceptionNoPath::ExceptionNoPath()
{
	_msg = "ERROR: The path is not validated";
}

const char* ExceptionNoPath::what() const throw ()
{
    return _msg;
}