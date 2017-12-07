#include "ExceptionNoMethod.h"

ExceptionNoMethod::ExceptionNoMethod()
{
	_msg = "ERROR: The Method is not validated";
}

const char* ExceptionNoMethod::what() const throw ()
{
    return _msg;
}