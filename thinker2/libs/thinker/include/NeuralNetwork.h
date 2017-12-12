#include <Data.h>
#include <random>
#include <NeuralNetworkDTO.h>


#define GTest

class NeuralNetwork : public NeuralNetworkDTO
{
public:
    #ifdef GTest
    public:
    #else
    private:
    #endif
    int limitLoop=1000;

    public:
        NeuralNetwork();
        NeuralNetwork(int inputNodes,int quantityLayersHidden,int hiddenNodes,int outputNodes);
        NeuralNetwork(int inputNodes,int quantityLayersHidden,int hiddenNodes,TypeOfTransition hiddenFunction,int outputNodes,TypeOfTransition outputFunction,double learnRate,double momentum,double error);
        void FeedForward(vector<double>& inputs);
        ~NeuralNetwork();
        void ShowWeights();
        void Train(const string& exmaples);
        void Train(vector<vector<double>>& inputs, vector<vector<double>>& outputs);
        void TrainByMomemtum(const string& exmaples);
        void SetTransitionFunction(int layer, TypeOfTransition typeFunction);
        void TrainByBatches(const string& examples);
        vector<double> Evaluate(vector<double>& outPut);
    #ifdef GTest
        public:
    #else    
        private:
    #endif
        int* ShuffleIndex(int* sequence,size_t size);
        double Backpropagation(vector<vector<double>>& inputs,vector<vector<double>>& expected,int * sequence);
        double BackpropagationByBatches(vector<vector<double>>& inputs,vector<vector<double>>& expected,int * sequence);
        void ComputeGradient(vector<double>& expected,vector<vector<double>>& generalError);
        void UpdateWeightsAndBias();
        void UpdateWeightsBiasByMomentum(vector<vector<vector<double>>>& diffWeight,vector<vector<double>>& diffBias);
		double MeanSquaredError(vector<vector<double>>& generalError);
		void SummaryGradients(vector<vector<double>>& gradientsTotal);	
        double CalculateError(vector<vector<double>>& errorValue);
};
