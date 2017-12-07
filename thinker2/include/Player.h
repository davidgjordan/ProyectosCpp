#ifndef TRAINER_H_
#define TRAINER_H_

#include <Newbie.h>
#include <Str2Image.h>
#include <Defines.h>
#include <LevelVelocity.h>
#include <Persistence.h>
#include <ExceptionVelocity.h>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <iterator>

#include <ListenKey.h>
#include <json.hpp>
#include <gym.h>

#include <Controller.h>

using namespace std;
using Json = nlohmann::json;

class Player
{
    boost::shared_ptr<Gym::Client> _client;
    Str2Image* _imageDisplay; 
    string _nameGame;
    string _directory;  
    string _serverIP;
    string _keysConfig;
    string _keyboard;
    bool _saveActionNone;
    map<string, vector<float>> _stepContainer;
    map<string, vector<float>> _keyContainer;
    public:
        Player(string nameGame, string directory, string serverIP, string keysConfig, bool saveActionNone, string keyboard);
        ~Player();

        void ExecuteFormAction(vector<float>& k, vector<float>& action, pair <float, vector<float>>& pairCommand);
        template<typename T>
        void ExecuteAction(bool& isCombination, vector<float>& k, vector<float>& action, pair <float, vector<float>>& pairCommand, const unsigned int* sequence, T& c, Controller& controller);
        void ExecuteActionOnlyKey(vector<float>& k, vector<float>& action, pair <float, vector<float>>& pairCommand, Controller& controller);
        void Save(pair <float, vector<float>>& pairCommand, string& observationNumber, Gym::State& state, vector<float>& k);
        void SaveObservation(pair <float, vector<float>>& pairCommand, string& observationNumber, Gym::State& state, vector<float>& k);
        void runTraining(const boost::shared_ptr<Gym::Client>& client, const string& environmentID, int velocity);
};
#endif //TRAINER_H_