#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Defines.h>
#include <ControllerKey.h>

#include <utility> 
#include <vector>
#include <string>
#include <map>
#include <json.hpp>
#include <fstream>

using Json = nlohmann::json;
using namespace std;
class Controller
{
    string _typeKeyboard;
	map<int, ControllerKey> _pairCommand;
	Json jsonKeyboard;
public:
    map<int, vector<unsigned int>> _combinations;
    Controller(string game, string jsonPath, string typeKeyboard);
    Controller();
    string ValidateKeyboard(string game);
    void Load(string game, string jsonPath);
    float GetAction(int posicionByte);
    void ProcessKeyboard();
    void ProcessCombinations(int &bitPosition, int &keysNumber);
    pair <float, vector<float>>  pressKey(const unsigned int keycode=0);
    ~Controller();
    
};


#endif //CONTROLLER_H