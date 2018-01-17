#include <string>
#include <iostream>
#include <cstring>

#include "windows.h"


using namespace std;

void printMsgJhose(const char *msg, int miliseconds)
{ 
    string res;

    while (*msg)
    {
        res += *msg;
        cout << res << endl;
        if(*msg!=' ')
        Sleep(miliseconds);
        cout << "\e[A";
        *(msg++);
    }
    cout << res << endl;
    
}

int main()
{

    const char *str1 = "hola mi Jhose Patlicia Belnal Ballon";
    const char *str2 = "que haciendo amol mio?";
    const char *str3 = "estudiando o q haciendo amol?";
    const char *str4 = "te amo mucho mi amol helmosa";



    printMsgJhose(str1, 500);
    printMsgJhose(str2, 500);
    printMsgJhose(str3, 500);
    printMsgJhose(str4, 300);

    return 0;
}