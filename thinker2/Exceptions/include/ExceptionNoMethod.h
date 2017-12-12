#ifndef EXCEPTIONNOMATHOD_H_
#define EXCEPTIONNOMATHOD_H_
#include <exception>
#include <string>
using namespace std;

class ExceptionNoMethod : public exception
{
    const char* _msg;
public:
    ExceptionNoMethod();
    const char* what() const throw();
};

#endif //EXCEPTIONNOMATHOD_H_