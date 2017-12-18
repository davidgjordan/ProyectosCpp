#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
<<<<<<< HEAD
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
=======
#include <Python.h>
#include <json.hpp>

#define pi 3.141592653589793

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "Hello world" << '\n';
    json js = {
        {"\"pi\"", 3.141},
        {"\"happy\"", true},
        {"\"name\"", "\"Niels\""},
        {"\"game\"", "\"Pacman\""},
        {"\"velocity\"", 3},
        {"\"answer\"", {{"\"everything\"", 42}}},
        {"\"list\"", {1, 0, 2}},
        {"\"object\"", {{"\"currency\"", "\"USD\""}, {"\"value\"", 42.99}}}};

    IPythonScript *python = new PythonByHand("path enviado");
    python->addParameter(js);

    python->run();
    //************************************************
    //Inicio el interprete Python e imprimo informacion relevante
    // Py_Initialize();

    // PyRun_SimpleString("print hello world python");

    // Py_Finalize();

    // char terminar;
    char *fin;
    const char *src1 = "python ../source/argumentos.py ";
    string dum = js.dump();
    const char *src2 = dum.c_str();
    auto len = strlen(src1) + strlen(src2);
    fin = new char[len + 1];
    strcpy(fin, src1);
    strcat(fin, src2);
    cout << "********************************************************" << endl;
    cout << js.dump() << endl;
    cout << fin << endl;
    cout << "********************************************************" << endl;

    //system("python ../source/argumentos.py uno dos tres");
    system(fin);
>>>>>>> 758219575e509a1b813e968d1b2b378ee4ba7771

    return 1;
}

// g++ -o users -I/usr/local/include/python2.4 pyembed.cpp
// main.cpp -L/usr/local/lib/python2.4/config -Xlinker
// -export-dynamic -lpython2.4 -lm -lpthread -ltk -lutil