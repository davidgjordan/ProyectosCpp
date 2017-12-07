#ifndef PERSISTENCE_H_
#define PERSISTENCE_H_

#include <string>
#include <Defines.h>
#include <Newbie.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <json.hpp>
#include <ExceptionNoFile.h>

using Json = nlohmann::json;
using namespace std;

class Persistence
{
    Json _manager;
    Json _managerGame;
    string _fileName;
    
    public:
        Persistence();
        void Save(NewbieDTO* newbie);
        Newbie* Load(Newbie* newbie);
        int LoadNNTopology(const string name, const string path);
        void SaveNNTopology(const int quantityLayersHidden, const int hiddenNodes, const string name);
        bool IsInstalled();
        string CreateNewGame(NewbieDTO* newbie, const string& gameName);
        void SaveStep();
        virtual ~Persistence();
};

#endif // PERSISTENCE_H_
