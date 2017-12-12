#ifndef EXCEPTIONNOINSTALL_H_
#define EXCEPTIONNOINSTALL_H_
#include <exception>
#include <string>
using namespace std;

class ExceptionNoInstall : public exception
{
    const char* _msg;
public:
    ExceptionNoInstall();
    const char* what() const throw();
};

#endif //EXCEPTIONNOINSTALL_H_