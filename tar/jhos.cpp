#include <string>
#include <iostream>
#include <cstring>

#include "windows.h"
#include <unistd.h>




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
        //usleep(miliseconds*1000);

        cout << "\e[A";
        *(msg++);
    }
    cout << res << endl;
    
}

int main()
{

    const char *str1 = "hola mi Jhose Patlicia Belnal Ballon hola mi Jhose Patlicia Belnal Ballonhola mi Jhose Patlicia Belnal Ballon";
    const char *str2 = "que haciendo amol mio?";
    const char *str3 = "estudiando o q haciendo amol?";
    const char *str4 = "te amo mucho mi amol helmosa";



    printMsgJhose(str2, 150);
    printMsgJhose(str1, 50);
    printMsgJhose(str3, 200);
    printMsgJhose(str4, 250);
    printMsgJhose(str1, 300);
    

    return 0;
}