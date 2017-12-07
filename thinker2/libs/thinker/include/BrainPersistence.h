#ifndef BRAINPERSISTENCE_H_
#define BRAINPERSISTENCE_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

#include <json.hpp>

#define INDENTATION 4

using Json = nlohmann::json;
using namespace std;

class BrainPersistence
{
    public:
        BrainPersistence();
        ~BrainPersistence();
        void Save(Json& persistenceBrain, const string& path);
        Json Load(const string& path);
};
#endif // BrainPERSISTENCE_H_