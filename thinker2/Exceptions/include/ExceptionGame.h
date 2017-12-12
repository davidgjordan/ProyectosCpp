#ifndef EXCEPTIONGAME_H_
#define EXCEPTIONGAME_H_
#include <exception>
#include <string>
using namespace std;

class ExceptionGame: public exception
{
    const char* _msg;
    public:
        ExceptionGame();
        const char* what() const throw();
};

#endif //EXCEPTIONGAME_H_