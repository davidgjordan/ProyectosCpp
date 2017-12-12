#include <BrainThinker.h>


BrainThinker::BrainThinker()
{
    
}

BrainThinker::~BrainThinker()
{
    
}

void BrainThinker::CreateNeuronalNetwork(const string& nnWeigths)
{
    cout << "Loading Neural Network Data..." << endl;
    _neuralNetworkAgent.Load(nnWeigths);
    _actionPacman.SetActionsValues(nnWeigths);
}

void BrainThinker::TrainNeuronalNetwork(IDataSource*& dataSource, const string& gameName, 
                const string& nnTopology, const string& nnWeigths, function<void (Json&)> jsonFunc)
{
    dataSource->ReadAllData();
    dataSource->ProcessAllData();
    vector<vector<double>> inputs = dataSource->GetNeuralNetworkInputs();
    vector<vector<double>> outputs= dataSource->GetNeuralNetworkOutputs();

    int quantityLayersHidden = _persistenceNNTopology.LoadNNTopology(QUANTITYLAYERSHIDDEN, nnTopology);
    int outputNodes = outputs[0].size();
    //double learnRate = 0.0005;
    double learnRate = 0.0005;
    double momentum = 0.0015;
    double error = 0.3;

    int inputNodes = inputs[0].size();
    int hiddenNodes = _persistenceNNTopology.LoadNNTopology(HIDDENNODES, nnTopology);

    cout << "----------------- Training Parameters -----------------" << endl;

    cout << "input nodes: " << inputNodes << endl;
    cout << "hidden quantityLayersHidden: " << quantityLayersHidden << endl;
    cout << "hidden nodes: " << hiddenNodes << endl;
    cout << "output nodes: " << outputNodes << endl;

    _neuralNetworkTrain = new NeuralNetwork(inputNodes, quantityLayersHidden, hiddenNodes, TypeOfTransition::TANGHIPERBOLIC, outputNodes, TypeOfTransition::SOFTMAX, learnRate, momentum, error);

    cout << "----------------- Starting Training -----------------" << endl;

    _neuralNetworkTrain->Train(inputs, outputs);

    cout << "----------------- Training Finished -----------------" << endl;

    _neuralNetworkTrain->Save(nnWeigths, jsonFunc);

    delete _neuralNetworkTrain;
}

float BrainThinker::GetAction(vector<float> observation, string render, IDataSource* dataSource)
{
    vector<double> obs(observation.begin(), observation.end());

    dataSource->ProcessData(obs, render);

    vector<double> input = dataSource->GetNeuralNetworkInputs()[0];
    
    cout << "input: ";

    for (int i = 0; i < input.size(); ++i)
    {
        cout << input[i] << " ";
    }

    cout << endl;
    
    vector<double> res = _neuralNetworkAgent.Evaluate(input);

    cout << "res: ";

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }

    cout << "\n" << endl;

    return _actionPacman.GetMovement(res);
}

