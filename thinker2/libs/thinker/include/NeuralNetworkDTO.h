#ifndef NEURALNETWORKDTO_H_
#define NEURALNETWORKDTO_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <random>
#include <typeinfo>
#include <json.hpp>
#include <Layer.h>
#include <BrainPersistence.h>
#include <Normalization.h>

#define INPUTNODES "inputNodes"
#define QUANTITYLAYERHIDDEN "quantityLayersHidden"
#define HIDDENNODES "hiddenNodes"
#define OUTPUTNODES "outputNodes"
#define LAYER "layer"
#define PERCEPTRON "perceptron"
#define BIAS "bias"
#define WEIGHTS "weights"
#define ERROR "error"
#define LEARNRATE "learnRate"
#define MOMENTUM "momentum"

using Json = nlohmann::json;
using namespace std;

class NeuralNetworkDTO
{
	BrainPersistence* _persistenceBrain;
	int _inputNodes;
	int _quantitylayerHidden;
	int _hiddenNodes;
	int _outputNodes;
	Json _manager;
	
	void SetNeuralNetwork();
	public:
	vector<double> min;
	vector<double> max;
		double error = 1;
    	double learnRate = 0.020;
    	double momentum = 0;
		default_random_engine generator;
    	uniform_real_distribution<double> distribution{-1,1};
		vector<Layer*> neuralNetwork;
		NeuralNetworkDTO();
		NeuralNetworkDTO(int inputNodes,int quantityLayersHidden,int hiddenNodes,int outputNodes, double error, double learnRate, double momentum);
		virtual ~NeuralNetworkDTO();
		void Save(const string& path, function<void (Json&)> jsonFunc);
		void Load(const string& path);
};

#endif // NEURALNETWORKDTO_H_