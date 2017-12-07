#include "ExceptionVelocity.h"

ExceptionVelocity::ExceptionVelocity()
{
	_msg = "ERROR: The speed level's value is not valid";
}

const char* ExceptionVelocity::what() const throw ()
{
    return _msg;
}