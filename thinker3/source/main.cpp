#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include <stdio.h>

using namespace std;


std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "w");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}



int main(int argc, char **argv)
{   
    const char * cmd = "../source/argumentos.py uno dos tres";
    
    cout<<exec(cmd)<<endl;
    

    //system("python argumentos.py uno dos tres cuatro");

    return 1;
}

// g++ -o users -I/usr/local/include/python2.4 pyembed.cpp
// main.cpp -L/usr/local/lib/python2.4/config -Xlinker
// -export-dynamic -lpython2.4 -lm -lpthread -ltk -lutil