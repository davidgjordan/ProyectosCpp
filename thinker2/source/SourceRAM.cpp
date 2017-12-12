#include <SourceRAM.h>
#include <StepPacman.h>
#include <Ghost.h>
#include <Pacman.h>
#include <GameModelPacman.h>
#include <Normalization.h>

using namespace std;

SourceRAM::SourceRAM()
{
    _stepPacman = new StepPacman();
}

void SourceRAM::SetDataPath(const string dataPath)
{
    _dataPath = dataPath;
}

string SourceRAM::GetDataPath() const
{
    return _dataPath;
}

vector<string> SourceRAM::GetFolderNames(string path)
{
    DIR* direction;
    dirent* dirent;
    vector<string> files;
    direction = opendir(path.c_str());

    while (dirent = readdir(direction))
    {
        string name = dirent->d_name;
        if((strcmp(name.c_str(),".")!=0) && (strcmp(name.c_str(),"..")!=0))
            files.push_back(name);
    }

    for (int i = 0; i < files.size(); i++)
    {
        cout << files[i] << endl;
    }

    free(direction);
    delete (dirent);

    return files;
}

void SourceRAM::ReadAllData()
{
    vector<string> folders = GetFolderNames(_dataPath);

    for (int i = 0; i < folders.size(); i++)
    {
        Json jsonData;
        ifstream dataStream {_dataPath + folders[i] + '/' + MATCH_JSON};
        dataStream >> jsonData;

        Json steps = jsonData[GAME_STEPS];
        Json keys = jsonData[GAME_KEYS];
        
        for (Json::iterator it = steps.begin(); it != steps.end(); ++it) 
        {
            _bytes.push_back(it.value());
        }

        for (Json::iterator it = keys.begin(); it != keys.end(); ++it) 
        {
            _keys.push_back(it.value());
        }
    }
}

void SourceRAM::ProcessAllData()
{
    for (int i = 0; i < _bytes.size(); i++)
    {
        GameModelPacman* model = new GameModelPacman();
        ModelData(_bytes[i], model);
        StepPacman* stepPacman = new StepPacman();
        ActionPacman* actionPacman = new ActionPacman();

        actionPacman->SetAction(_keys[i]);        
        stepPacman->SetModel(model);
        stepPacman->SetAction(actionPacman);

        _steps.push_back(stepPacman);
    }
}

void SourceRAM::ModelData(vector<double>& bytes, GameModelPacman*& gameModelPacman)
{
    Ghost clyde;
    clyde.SetPositionX(bytes[POSITION_X_GHOST_CLYDE_RAM]);
    clyde.SetPositionY(bytes[POSITION_Y_GHOST_CLYDE_RAM]);

    Ghost inky;
    inky.SetPositionX(bytes[POSITION_X_GHOST_INKY_RAM]);
    inky.SetPositionY(bytes[POSITION_Y_GHOST_INKY_RAM]);

    Ghost pinky;
    pinky.SetPositionX(bytes[POSITION_X_GHOST_PINKY_RAM]);
    pinky.SetPositionY(bytes[POSITION_Y_GHOST_PINKY_RAM]);

    Ghost blinky;
    blinky.SetPositionX(bytes[POSITION_X_GHOST_BLINKY_RAM]);
    blinky.SetPositionY(bytes[POSITION_Y_GHOST_BLINKY_RAM]);

    Pacman pacman;
    pacman.SetPositionX(bytes[POSITION_X_PACMAN_RAM]);
    pacman.SetPositionY(bytes[POSITION_Y_PACMAN_RAM]);

    gameModelPacman->SetPacman(pacman);
    gameModelPacman->SetGhostClyde(clyde);
    gameModelPacman->SetGhostInky(inky);
    gameModelPacman->SetGhostPinky(pinky);
    gameModelPacman->SetGhostBlinky(blinky);
}

void SourceRAM::ProcessData(vector<double> observation, string stringRender)
{
    _steps.clear();
    vector<double> res;

    GameModelPacman* gameModelPacman = new GameModelPacman();
    ModelData(observation, gameModelPacman);
    
    _stepPacman->SetModel(gameModelPacman);

    _steps.push_back(_stepPacman);

}

vector<vector<double>> SourceRAM::GetNeuralNetworkInputs()
{
    _inputs.clear();
    IStep* step;
    IGameModel* model;

    Pacman pacman;
    Ghost blinky;
    Ghost pinky;
    Ghost inky;
    Ghost clyde;

    for (int i = 0; i < _steps.size(); i++)
    {
        step = _steps[i];
        model = step->GetModel();

        pacman = ((GameModelPacman*) model)->GetPacman();
        blinky = ((GameModelPacman*) model)->GetGhostBlinky();
        pinky = ((GameModelPacman*) model)->GetGhostPinky();
        inky = ((GameModelPacman*) model)->GetGhostInky();
        clyde = ((GameModelPacman*) model)->GetGhostClyde();

        vector<double> positions;

        positions.push_back(pacman.GetPositionX());
        positions.push_back(pacman.GetPositionY());
        positions.push_back(blinky.GetPositionX());
        positions.push_back(blinky.GetPositionY());
        positions.push_back(pinky.GetPositionX());
        positions.push_back(pinky.GetPositionY());
        positions.push_back(inky.GetPositionX());
        positions.push_back(inky.GetPositionY());
        positions.push_back(clyde.GetPositionX());
        positions.push_back(clyde.GetPositionY());

        _inputs.push_back(positions);
        delete model;
       
    }

    return _inputs;
}

vector<vector<double>> SourceRAM::GetNeuralNetworkOutputs()
{
    StepPacman* stepPacman;
    ActionPacman* actionPacman;

    for (int i = 0; i < _steps.size(); i++)
    {
        stepPacman = _steps[i];
        actionPacman = stepPacman->GetAction();
        _outputs.push_back(actionPacman->GetAction());
        delete actionPacman;
        delete _steps[i];
    }    
    return _outputs;
}

void SourceRAM::PrintInternalData() const
{
    cout << "------------------ Printing _bytes ----------------------" << endl;

    for (int i = 0; i < _bytes.size(); i++)
    {
        cout << _bytes[i][0] << " " << _bytes[i][1] << " " << _bytes[i][2] << " " << _bytes[i][3] << " " << _bytes[i][4] << " " << _bytes[i][5] << " " << _bytes[i][6] << " " << _bytes[i][7] << " " << _bytes[i][8] << " " << _bytes[i][9] << endl;
    }

    cout << "------------------ Printing _keys ----------------------" << endl;

    for (int i = 0; i < _keys.size(); i++)
    {
        cout << _keys[i][0] << " " << _keys[i][1] << " " << _keys[i][2] << " " << _keys[i][3] << endl;
    }
}

void SourceRAM::PrintNeuralNetworkData() const
{
    cout << "------------------ Printing _inputs ----------------------" << endl;

    for (int i = 0; i < _inputs.size(); i++)
    {
        cout << _inputs[i][0] << " " << _inputs[i][1] << " " << _inputs[i][2] << " " << _inputs[i][3] << " " << _inputs[i][4] << " " << _inputs[i][5] << " " << _inputs[i][6] << " " << _inputs[i][7] << " " << _inputs[i][8] << " " << _inputs[i][9] << endl;
    }

    cout << "------------------ Printing _outputs ----------------------" << endl;

    for (int i = 0; i < _outputs.size(); i++)
    {
        cout << _outputs[i][0] << " " << _outputs[i][1] << " " << _outputs[i][2] << " " << _outputs[i][3] << endl;
    }
}

SourceRAM::~SourceRAM()
{
    delete _stepPacman;
    _steps.clear();
}