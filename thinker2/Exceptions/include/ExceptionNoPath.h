#ifndef EXCEPTIONNOPATH_H_
#define EXCEPTIONNOPATH_H_
#include <exception>
#include <string>
using namespace std;

class ExceptionNoPath : public exception
{
    const char* _msg;
public:
    ExceptionNoPath();
    const char* what() const throw();
};

#endif //EXCEPTIONNOPATH_H_