#include <Player.h>

Player::Player(string nameGame, string directory, string serverIP, string keysConfig, bool saveActionNone, string keyboard): _nameGame{nameGame}, _directory{directory}, _serverIP{serverIP}, _keysConfig{keysConfig}, _saveActionNone{saveActionNone}, _keyboard{keyboard}
{

    _imageDisplay = new Str2Image();

    puts("Input the speed level : 1 = fast , 2 = medium , 3 = slow");
    int velocity; 
               
    cin >> velocity;
    if(velocity == 1 | velocity == 2 | velocity == 3)
    {
        try
        {
            _client = Gym::client_create(_serverIP, PORT);///agregar el atributo server address
        }
        catch (const exception& except) 
        {
            fprintf(stderr, "ERROR: %s\n", except.what());
        }
        runTraining(_client, _nameGame, velocity);
    }
    else
    {
        throw ExceptionVelocity();
    }
}

void Player::ExecuteFormAction(vector<float>& k, vector<float>& action, pair <float, vector<float>>& pairCommand)
{
    action[COMMAND] = pairCommand.first;
    k = pairCommand.second;
}

template<typename T>
void Player::ExecuteAction(bool& isCombination, vector<float>& k, vector<float>& action, pair <float, vector<float>>& pairCommand, const unsigned int* sequence, T& c, Controller& controller)
{
    auto& comb = c;
    if (_imageDisplay->_displayer.is_key_sequence(sequence,comb.second.size(),true)) 
    { 
        isCombination = true;
        pairCommand = controller.pressKey(comb.first); 
        ExecuteFormAction(k, action, pairCommand);
    }
}

void Player::ExecuteActionOnlyKey(vector<float>& k, vector<float>& action, pair <float, vector<float>>& pairCommand, Controller& controller)
{
    if(_imageDisplay->_displayer.is_key())
    {
        pairCommand = controller.pressKey(_imageDisplay->_displayer.key(0));
        ExecuteFormAction(k, action, pairCommand);
    }
    else
    {
        pairCommand = controller.pressKey();                
        ExecuteFormAction(k, action, pairCommand);
    }
}

void Player::Save(pair <float, vector<float>>& pairCommand, string& observationNumber, Gym::State& state, vector<float>& k)
{
    _stepContainer.insert(pair<string ,vector<float>>(observationNumber,state.observation));
    _keyContainer.insert(pair<string, vector<float>>(observationNumber, k));
}

void Player::SaveObservation(pair <float, vector<float>>& pairCommand, string& observationNumber, Gym::State& state, vector<float>& k)
{
    if(pairCommand.first==NOTHING)
    {
        if(_saveActionNone)
        {
            Save(pairCommand, observationNumber, state, k);
        }
    }
    else
    {
        Save(pairCommand, observationNumber, state, k);
    }
}   

void Player::runTraining(const boost::shared_ptr<Gym::Client>& client, const string& environmentID, int velocity)
{
    Controller controller(_nameGame, _keyboard, _keysConfig);
    
    boost::shared_ptr<Gym::Environment> environment = client->make(environmentID);
    vector<float> action(1, 0.0f);
    float totalReward = 0;
    int totalSteps = 0;
    int pressKey = 0;
    LevelVelocity vel;
    Json json;
    ifstream ipf {_directory + "/" + MATCH_JSON};
    ipf>>json;
    ipf.close();

    Gym::State state;
    environment->reset(&state);
        
    unsigned int microseconds;
    microseconds = vel.SetSpeedLevel(velocity);
    _imageDisplay->SetRgbArray(state.render);

    pair <float,    vector<float>> pairCommand = controller.pressKey();
    action[COMMAND] = pairCommand.first;
    vector<float> k = pairCommand.second;

    while(!_imageDisplay->_displayer.is_keyESC() && !state.done)
    {
        usleep(microseconds);
        environment->step(action, false, &state);
        
        string observationNumber = to_string(totalSteps);
        
        bool isCombination = false;
        
        for(auto& comb: controller._combinations)
        {
            const unsigned int* sequence = &comb.second[0];
            ExecuteAction(isCombination, k, action, pairCommand, sequence, comb, controller);
        }

        if(isCombination ==false)
        {
            ExecuteActionOnlyKey(k, action, pairCommand, controller);
        }

        _imageDisplay->SaveRgbArray(_directory + "/" + RGB_PATH + "/" + to_string(totalSteps));

        SaveObservation(pairCommand, observationNumber, state, k);

        _imageDisplay->DisplayImage();
        totalReward += state.reward;
        totalSteps += 1;
    }
    
    json[GAME_SCORE] = totalReward;
    json[GAME_STEPS] = _stepContainer;
    json[GAME_KEYS] = _keyContainer;

    ofstream opf {_directory + "/" + MATCH_JSON};
    opf<<setw(INDENTATION)<<json<<"\n";
    opf.close();
}

Player::~Player()
{
    delete _imageDisplay;
}