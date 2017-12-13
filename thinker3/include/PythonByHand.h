#ifndef PYTHON_BY_HAND_H_
#define PYTHON_BY_HAND_H_
#include "IPythonScript.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class PythonByHand : public IPythonScript{
    string _pathScript;
    Json _configUser;
    Json _result;

public:
    PythonByHand(const string path);
    void addParameter(Json configUser);
    void addParameter(string inputStreaming);
    void run();
    Json getResult();
};

#endif