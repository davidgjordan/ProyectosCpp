#include <ExceptionNoFile.h>
ExceptionNoFile::ExceptionNoFile()
{
	_msg = "ERROR: File not Found";
}
const char* ExceptionNoFile::what() const throw ()
{
    return _msg;
}