#include <NeuralNetworkDTO.h>
    
NeuralNetworkDTO::NeuralNetworkDTO()
{
    _persistenceBrain = nullptr;
}
NeuralNetworkDTO::NeuralNetworkDTO(int inputNodes,int quantityLayersHidden,int hiddenNodes,int outputNodes, double error, double learnRate, double momentum):
_inputNodes{inputNodes}, _quantitylayerHidden{quantityLayersHidden}, _hiddenNodes{hiddenNodes}, _outputNodes{outputNodes}, error{error}, learnRate{learnRate}, momentum{momentum}
{
    _persistenceBrain = new BrainPersistence();
}

void NeuralNetworkDTO::SetNeuralNetwork()
{
    neuralNetwork.push_back(new Layer(_inputNodes,LayerType::INPUT, distribution, generator));
    for (int hiddenLayer = 0; hiddenLayer < _quantitylayerHidden; ++hiddenLayer)
    {
        neuralNetwork.push_back(new Layer(_hiddenNodes,_inputNodes,TypeOfTransition::TANGHIPERBOLIC,LayerType::HIDDEN, distribution, generator));
        _inputNodes = _hiddenNodes;
    }
    neuralNetwork.push_back(new Layer(_outputNodes,_inputNodes,TypeOfTransition::SOFTMAX,LayerType::OUTPUT, distribution, generator));
}

void NeuralNetworkDTO::Load(const string& path)
{   
    _manager = _persistenceBrain->Load(path);
    _inputNodes = _manager[INPUTNODES];
    _quantitylayerHidden = _manager[QUANTITYLAYERHIDDEN];
    _hiddenNodes = _manager[HIDDENNODES];
    _outputNodes = _manager[OUTPUTNODES];
    error = _manager[ERROR];
    learnRate = _manager[LEARNRATE];
    momentum = _manager[MOMENTUM];
    vector<double> mmin = _manager["min"];
    vector<double> mmax = _manager["max"];
    min = mmin;
    max = mmax;
    //min = _manager["min"];
    //max = _manager["max"];
    
    SetNeuralNetwork();
    for (int i = 0; i < neuralNetwork.size(); ++i)
    {
        for (int j = 0; j < neuralNetwork[i]->layerPerceptron.size(); ++j)
        {
            neuralNetwork[i]->layerPerceptron[j]->SetBias(_manager[LAYER+to_string(i)][PERCEPTRON+to_string(j)][BIAS]);
            neuralNetwork[i]->layerPerceptron[j]->SetWeights(_manager[LAYER+to_string(i)][PERCEPTRON+to_string(j)][WEIGHTS]);
        }
    }
}

void NeuralNetworkDTO::Save(const string& path, function<void (Json&)> jsonFunc)
{
    Json json;
    json[ERROR] = error;
    json[LEARNRATE] = learnRate;
    json[MOMENTUM] = momentum;
    json[INPUTNODES] = _inputNodes;
    json[QUANTITYLAYERHIDDEN] = _quantitylayerHidden;
    json[HIDDENNODES] = _hiddenNodes;
    json[OUTPUTNODES] = _outputNodes;
    json["min"] = min;
    json["max"] = max;

    for(int i = 0; i<neuralNetwork.size(); ++i)
    {
        for (int j = 0; j < neuralNetwork[i]->layerPerceptron.size(); ++j)
        {
            json[LAYER+to_string(i)][PERCEPTRON+to_string(j)][BIAS] = neuralNetwork[i]->layerPerceptron[j]->GetBias();
            json[LAYER+to_string(i)][PERCEPTRON+to_string(j)][WEIGHTS] = neuralNetwork[i]->layerPerceptron[j]->GetWeights();     
        }
    }
    jsonFunc(json);
    _persistenceBrain->Save(json, path);
}

NeuralNetworkDTO::~NeuralNetworkDTO()
{
    delete _persistenceBrain;
}