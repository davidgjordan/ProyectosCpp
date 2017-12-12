#ifndef BRAINTHINKER_H_
#define BRAINTHINKER_H_

#include <IBrain.h>
#include <ActionPacman.h>
#include <Defines.h>
#include <NeuralNetwork.h>
#include <Persistence.h>

#include <string>
#include <vector>

#define QUANTITYLAYERSHIDDEN "quantityLayersHidden"
#define HIDDENNODES "hiddenNodes"

using namespace std;

class NeuralNetwork;

class BrainThinker: public IBrain
{
    NeuralNetwork* _neuralNetworkTrain;
    NeuralNetwork _neuralNetworkAgent;
    ActionPacman _actionPacman;
    Persistence _persistenceNNTopology{};
    string _path;
    public:
        BrainThinker();
        BrainThinker(string path);
        ~BrainThinker();
        void CreateNeuronalNetwork(const string& nnWeigths) override;
        void TrainNeuronalNetwork(IDataSource*& dataSource, const string& gameName, 
             const string& nnTopology, const string& nnWeigths, function<void (Json&)> jsonFunc) override;
        float GetAction(vector<float> observation, string render, IDataSource* dataSource) override;
        
};
#endif//BRAINTHINKER_H_