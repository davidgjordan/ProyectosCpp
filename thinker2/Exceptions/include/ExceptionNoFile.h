#ifndef EXCEPTIONNOFILE_H_
#define EXCEPTIONNOFILE_H_
#include <exception>
#include <string>
using namespace std;

class ExceptionNoFile : public exception
{
    const char* _msg;
    public:
        ExceptionNoFile();
        const char* what() const throw();
};

#endif //EXCEPTIONNOFILE_H_