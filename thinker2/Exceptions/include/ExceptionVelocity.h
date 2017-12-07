#ifndef EXCEPTIONVELOCITY_H_
#define EXCEPTIONVELOCITY_H_
#include <exception>
#include <string>
using namespace std;

class ExceptionVelocity : public exception
{
    const char* _msg;
public:
    ExceptionVelocity();
    const char* what() const throw();
};

#endif //EXCEPTIONVELOCITY_H_