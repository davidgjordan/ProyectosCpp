#ifndef AGENT_H_
#define AGENT_H_

#include <BrainThinker.h>
#include <LevelVelocity.h>
#include <IDataSource.h>
#include <ExceptionVelocity.h>

#include <Str2Image.h>
#include <Defines.h>

#include <gym.h>

using namespace std;

class Agent
{
    BrainThinker* _brainThinker;
    Str2Image* _imageDisplay; 
    boost::shared_ptr<Gym::Client> _client;
    string _serverIP;
    string _methodTrain;
    string _gameName;
    string _keyBoard;
    string _NNWeights;

    void playGame(const boost::shared_ptr<Gym::Client>& client, const string& environmentID, int velocity, IDataSource* dataSource);
    void LoadGameParameters(const string& nnWeigths);
    public:
    Agent(string serverIP, string methodTrain, string NNWeights);
    ~Agent();
    
};
#endif//AGENT_H_