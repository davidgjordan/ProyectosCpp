#include <Agent.h>
#include <Persistence.h>
#include <Newbie.h>
#include <SourceRAM.h>
#include <SourceRGB.h>
#include <SourceFullRAM.h>

Agent::Agent(string serverIP, string methodTrain, string NNWeights) : _serverIP{serverIP}, _methodTrain{methodTrain}, _NNWeights{NNWeights}
{
    _imageDisplay = new Str2Image();
    _brainThinker = new BrainThinker();

    IDataSource* dataSource;

    if (_methodTrain == METHOD_RAM)
    {
        dataSource = new SourceRAM();
    }
    else if (_methodTrain == METHOD_RGB)
    {
        dataSource = new SourceRGB();
    }
    else if (_methodTrain == METHOD_FULLRAM)
    {
        dataSource = new SourceFullRAM(NNWeights);
    }

    _brainThinker->CreateNeuronalNetwork(NNWeights);
    LoadGameParameters(NNWeights);

    puts("Input the speed level : 1 = fast , 2 = medium , 3 = slow");
    int velocity;
    cin >> velocity;
    if(velocity == 1 | velocity == 2 | velocity == 3)
    {
        try
        {
            _client = Gym::client_create(serverIP, PORT);
        }
        catch (const exception& except) 
        {
            fprintf(stderr, "ERROR: %s\n", except.what());
        }
        playGame(_client, _gameName, velocity, dataSource);
        delete dataSource;
    }
    else
    {
        throw ExceptionVelocity();
    }
}

Agent::~Agent()
{
    delete _brainThinker;
    delete _imageDisplay;
}

void Agent::playGame(const boost::shared_ptr<Gym::Client>& client, const string& environmentID , int velocity, IDataSource* dataSource)
{
    boost::shared_ptr<Gym::Environment> environment = client->make(environmentID);
    vector<float> action(1, 0.0f);

    LevelVelocity vel;
    
    Gym::State state;
    environment->reset(&state);
    
    action[COMMAND] = LEFT;           
    unsigned int microseconds;
    microseconds = vel.SetSpeedLevel(velocity);

    usleep(microseconds);

    environment->step(action, false, &state);
    _imageDisplay->SetRgbArray(state.render);

    while(!state.done)
    {
        usleep(microseconds);
        float command = _brainThinker->GetAction(state.observation, state.render, dataSource);

        if(command != 0.0)
        {
            action[COMMAND] = command;
        }
        environment->step(action, false, &state);
        _imageDisplay->DisplayImage();
    }
}

void Agent::LoadGameParameters(const string& nnWeigths)
{
    Json jsonWeigths;
    ifstream dataStream {nnWeigths};
    dataStream >> jsonWeigths;
    _gameName = jsonWeigths[GAME];
    dataStream.close();
}