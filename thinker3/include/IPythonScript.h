#ifndef IPYTHONSCRIPT_H_
#define IPYTHONSCRIPT_H_
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <json.hpp>

using Json = nlohmann::json;

using namespace std;

class IPythonScript{
public:
    virtual void addParameter(Json configUser)=0;
    virtual void addParameter(string inputStreaming)=0;
    virtual void run()=0;
    virtual Json getResult()=0;
};

#endif