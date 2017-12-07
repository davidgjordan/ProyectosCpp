#ifndef Layer_H
#define Layer_H
#include <random>
#include <Perceptron.h>
#include <LayerType.h>
#include <TransitionSoftMax.h>
#include <TransitionHiperbolicTangent.h>
#include <TransitionSigmoid.h>
#include <TransitionByStep.h>
#include <TransitionType.h>
#include <vector>

constexpr size_t INPUTS_PER_NODE = 1;

class Layer
{
	public:
	TypeOfTransition transitionType;
	LayerType layerType;
    vector<Perceptron*> layerPerceptron;
	Transition* function;
	vector<double> outPutProcessFeed;
		
	Layer(int numNodes,int numInputs, TypeOfTransition typeFunction, LayerType layerType,uniform_real_distribution<double>& distribution,default_random_engine& generator);
	Layer(int numNodes, LayerType layerType,uniform_real_distribution<double>& distribution,default_random_engine& generator);
	vector<double>& Evaluate(vector<double>& inputs);
	~Layer();
};
#endif