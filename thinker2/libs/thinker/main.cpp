#include <iostream>
#include <NeuralNetwork.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string ruta = "../training-data.json";

    int inputNodes = 2;
    int quantityLayersHidden = 1;
    int hiddenNodes = 5;
    int outputNodes = 3;

    double learnRate = 0.01;
    double momentum = 0.02;
    double error = 0.012;

    vector<vector<double>> inputs = {{25,63000},{36,55000},{40,74000},{23,28000}};

    vector<vector<double>> expectedOutpus = {{0,0,1},{0,0,1},{0,0,1},{0,0,1}};

    NeuralNetwork net {inputNodes,quantityLayersHidden,hiddenNodes,TypeOfTransition::TANGHIPERBOLIC,outputNodes,TypeOfTransition::SOFTMAX,learnRate,momentum,error};

    NeuralNetwork net2{};

    // net.Train(ruta);
    net.Train(inputs, expectedOutpus);

    net.Save("SaveTrainNeural.json");

    net2.Load("SaveTrainNeural.json");

    vector<double> result;

    vector<double> setosa{25,63000};
    result = net.Evaluate(setosa);
    cout<< result[0]<<" "<< result[1]<<" "<< result[2]<<"\n";

    result = net2.Evaluate(setosa);
    cout<< result[0]<<" "<< result[1]<<" "<< result[2]<<"\n";

    /*vector<double> versicolor{6.7,3.1,4.4,1.4};
    result = net.Evaluate(versicolor);
    cout<< result[0]<<" "<< result[1]<<" "<< result[2]<<"\n";

    result = net2.Evaluate(versicolor);
    cout<< result[0]<<" "<< result[1]<<" "<< result[2]<<"\n";

    vector<double> virginica{7.2,3.0,5.8,1.6};
    result = net.Evaluate(virginica);
    cout<< result[0]<<" "<< result[1]<<" "<< result[2]<<"\n";

    result = net2.Evaluate(virginica);
    cout<< result[0]<<" "<< result[1]<<" "<< result[2]<<"\n";*/

 }

