#include <SourceRGB.h>

SourceRGB::SourceRGB()
{
    _rgbTool = new RgbTool("RGB");
     _stepPacman = new StepPacman();
     _actionPacman = new ActionPacman();
}

SourceRGB::SourceRGB(string dataPath)
{
    _dataPath = dataPath;
    _rgbTool = new RgbTool("RGB");

}

SourceRGB::~SourceRGB()
{
    delete(_rgbTool);
    delete(_stepPacman);
    delete(_actionPacman);
    _steps.clear(); 
}

void SourceRGB::LoadMatchJson(string path)
{
    string jsonPath = _dataPath + path + "/" + MATCH_JSON; 
    ifstream fileJson (jsonPath.c_str());
    if (fileJson.peek() == EOF)
    {
        printf(ANSI_COLOR_RED "<%s> NOT FOUND\n" ANSI_COLOR_RESET, jsonPath.c_str());
    }    
    else
    {
        if(fileJson.good())
        {
            fileJson >> _matchJson;

            if(_matchJson.empty())
            {
                printf(ANSI_COLOR_RED "<%s> IS EMPTY\n" ANSI_COLOR_RESET, jsonPath.c_str());
            }
            else
            {
                printf(ANSI_COLOR_GREEN "<%s> LOADED\n" ANSI_COLOR_RESET, jsonPath.c_str());
            }
        }
        else
        {
            printf(ANSI_COLOR_RED "SOME THING ABOUT THIS FILE <%s> IS WRONG!\n" ANSI_COLOR_RESET, jsonPath.c_str());
        }
    }

    fileJson.close();
}

vector<string> SourceRGB::NameFiles(string path)       
{
    DIR* direction;
    dirent* dirent;
    vector<string> files;
    direction = opendir(path.c_str());
    while (dirent = readdir(direction))
    {
        string name = dirent->d_name;
        if((strcmp(name.c_str(),".") != 0) && (strcmp(name.c_str(),"..") != 0))
            files.push_back(name);
    }
    sort(files.begin(), files.end());
    free(direction);
    delete(dirent);
    return files;
}
void  SourceRGB::ReadAllData()
{
    vector<string> folderNames;
    folderNames = NameFiles(_dataPath.c_str());
    for (string folder : folderNames)
    {
        for (string s : NameFiles(_dataPath + folder + "/" + RGB_PATH ))
        {
            _fileNames.push_back(_dataPath + folder + "/" + RGB_PATH + "/" + s.c_str());
        }
    }

}

void SourceRGB::ProcessAllData()
{
    vector<StepPacman> steps;
    vector<Wall> walls;
    vector<Way> ways;
    bool envieriomentMapped = 0;
   
    vector<vector<double>> actions;

    vector<string> folderNames;
    folderNames = NameFiles(_dataPath.c_str());
    for (string folder : folderNames)
    {
        LoadMatchJson(folder);
        Json actionsJson = _matchJson[GAME_KEYS];

        for (Json::iterator it = actionsJson.begin(); it != actionsJson.end(); ++it) 
        {
            actions.push_back(it.value());
        }
    }

    int actionCount = 0;

    map<char, double> positions;
    _modelPacman = new GameModelPacman();
    for (string file : _fileNames)
    {
        string stringRender;
        Pacman pacman;
        Ghost ghost1;
        Ghost ghost2;
        Ghost ghost3;
        Ghost ghost4;

        ifstream renderTxt (file.c_str());
        getline(renderTxt,stringRender);
        renderTxt.close();

        _rgbTool->SetRenderRgb(stringRender);
        _rgbTool->CharRepresent(_rgbTool->GetRenderRgb());
        if(!envieriomentMapped)
        {
            vector<vector<char>> map = _rgbTool->MappingRgb();

            for(int x = 0; x<map.size(); x++)
            {
                for(int y = 0 ; y<map[x].size(); y++)
                {
                    char representation = map[x][y];
                    double positionX = (double)x;
                    double positionY = (double)y;
                    switch(representation)
                    {
                        case MAP_CHAR_WALL:
                        {
                            Wall* wall = new Wall(positionX,positionY,representation);
                            walls.push_back(*wall);
                            delete wall; 
                        }break;
                        case MAP_CHAR_WAY:
                        {
                            Way* way = new Way(positionX,positionY,representation);
                            ways.push_back(*way);
                            delete way; 
                        }break;
                        case MAP_CHAR_PILL:
                        {
                            Way* way = new Way(positionX,positionY,representation);
                            ways.push_back(*way);
                            delete way;
                        }break;
                    }
                    
                }                
            }            
            envieriomentMapped=1;

        }

        positions = _rgbTool->GetObjectPosition(MAP_CHAR_PACMAN);
        pacman.SetPositionX(positions[POSITION_X]);
        pacman.SetPositionY(positions[POSITION_Y]);

        positions = _rgbTool->GetObjectPosition(MAP_CHAR_GHOST1);
        ghost1.SetPositionX(positions[POSITION_X]);
        ghost1.SetPositionY(positions[POSITION_Y]);

        positions = _rgbTool->GetObjectPosition(MAP_CHAR_GHOST2);
        ghost2.SetPositionX(positions[POSITION_X]);
        ghost2.SetPositionY(positions[POSITION_Y]);

        positions = _rgbTool->GetObjectPosition(MAP_CHAR_GHOST3);
        ghost3.SetPositionX(positions[POSITION_X]);
        ghost3.SetPositionY(positions[POSITION_Y]);

        positions = _rgbTool->GetObjectPosition(MAP_CHAR_GHOST4);
        ghost4.SetPositionX(positions[POSITION_X]);
        ghost4.SetPositionY(positions[POSITION_Y]);

        _modelPacman->SetPacman(pacman);
        _modelPacman->SetGhostBlinky(ghost1);
        _modelPacman->SetGhostPinky(ghost2);
        _modelPacman->SetGhostInky(ghost3);
        _modelPacman->SetGhostClyde(ghost4);    

        _actionPacman->SetAction(actions[actionCount]);
        actionCount++;
        _stepPacman->SetModel(_modelPacman);
        _stepPacman->SetAction(_actionPacman);
        _steps.push_back(_stepPacman);

       
    }

    GenerateInputsRGB();
    GenerateOutputsRGB();
    delete(_modelPacman);
    walls.clear();
    ways.clear(); 
    steps.clear();

}


void SourceRGB::ProcessData(vector<double> observation, string stringRender)
{
    Pacman pacman;
    Ghost ghost1;
    Ghost ghost2;
    Ghost ghost3;
    Ghost ghost4;
    vector<Wall> walls;
    vector<Way> ways;
    _inputs.clear();
    _steps.clear();
    string charactersToFound;

    map<string, double> positions;

    charactersToFound = MAP_CHAR_PACMAN;
    charactersToFound = charactersToFound + MAP_CHAR_GHOST1;
    charactersToFound = charactersToFound + MAP_CHAR_GHOST2;
    charactersToFound = charactersToFound + MAP_CHAR_GHOST3;
    charactersToFound = charactersToFound + MAP_CHAR_GHOST4;

    GameModelPacman* model = new GameModelPacman();

    _rgbTool->SetRenderRgb(stringRender);
    _rgbTool->CharRepresent();
    positions = _rgbTool->GetObjectAllPosition(charactersToFound.c_str());

    pacman.SetPositionX(positions[DEFAULT_POSITION_PACMAN_X]);
    pacman.SetPositionY(positions[DEFAULT_POSITION_PACMAN_Y]);

    ghost1.SetPositionX(positions[DEFAULT_POSITION_GHOST1_X]);
    ghost1.SetPositionY(positions[DEFAULT_POSITION_GHOST1_Y]);

    ghost2.SetPositionX(positions[DEFAULT_POSITION_GHOST2_X]);
    ghost2.SetPositionY(positions[DEFAULT_POSITION_GHOST2_Y]);

    ghost3.SetPositionX(positions[DEFAULT_POSITION_GHOST3_X]);
    ghost3.SetPositionY(positions[DEFAULT_POSITION_GHOST3_Y]);

    ghost4.SetPositionX(positions[DEFAULT_POSITION_GHOST4_X]);
    ghost4.SetPositionY(positions[DEFAULT_POSITION_GHOST4_Y]);

    model->SetPacman(pacman);
    model->SetGhostBlinky(ghost1);
    model->SetGhostPinky(ghost2);
    model->SetGhostInky(ghost3);
    model->SetGhostClyde(ghost4);    

    StepPacman* step = new StepPacman();
    step->SetModel(model);
    _steps.push_back(step);
    GenerateInputRGB();
    
}

void SourceRGB::GenerateInputsRGB()
{
    IStep* step;
    IGameModel* model;

    Pacman pacman;

    Ghost ghost1;
    Ghost ghost2;
    Ghost ghost3;
    Ghost ghost4;

    for (int i = 0; i < _steps.size(); i++)
    {
        step = _steps[i];

        model = step->GetModel();

        pacman = ((GameModelPacman*) model)->GetPacman();

        ghost1 = ((GameModelPacman*) model)->GetGhostBlinky();
        ghost2 = ((GameModelPacman*) model)->GetGhostPinky();
        ghost3 = ((GameModelPacman*) model)->GetGhostInky();
        ghost4 = ((GameModelPacman*) model)->GetGhostClyde();

        vector<double> positions;

        positions.push_back(pacman.GetPositionX());
        positions.push_back(pacman.GetPositionY());
        positions.push_back(ghost1.GetPositionX());
        positions.push_back(ghost1.GetPositionY());
        positions.push_back(ghost2.GetPositionX());
        positions.push_back(ghost2.GetPositionY());
        positions.push_back(ghost3.GetPositionX());
        positions.push_back(ghost3.GetPositionY());
        positions.push_back(ghost4.GetPositionX());
        positions.push_back(ghost4.GetPositionY());
        _inputs.push_back(positions);
    }
}

void SourceRGB::GenerateInputRGB()
{
    IStep* step;
    IGameModel* model;

    Pacman pacman;

    Ghost ghost1;
    Ghost ghost2;
    Ghost ghost3;
    Ghost ghost4;

    for (int i = 0; i < _steps.size(); i++)
    {
        step = _steps[i];

        model = step->GetModel();

        pacman = ((GameModelPacman*) model)->GetPacman();

        ghost1 = ((GameModelPacman*) model)->GetGhostBlinky();
        ghost2 = ((GameModelPacman*) model)->GetGhostPinky();
        ghost3 = ((GameModelPacman*) model)->GetGhostInky();
        ghost4 = ((GameModelPacman*) model)->GetGhostClyde();

        vector<double> positions;

        positions.push_back(pacman.GetPositionX());
        positions.push_back(pacman.GetPositionY());
        positions.push_back(ghost1.GetPositionX());
        positions.push_back(ghost1.GetPositionY());
        positions.push_back(ghost2.GetPositionX());
        positions.push_back(ghost2.GetPositionY());
        positions.push_back(ghost3.GetPositionX());
        positions.push_back(ghost3.GetPositionY());
        positions.push_back(ghost4.GetPositionX());
        positions.push_back(ghost4.GetPositionY());
        _inputs.push_back(positions);

        delete model;
        delete _steps[i];
    }
}

void SourceRGB::GenerateOutputsRGB()
{
    StepPacman* stepPacman;
    ActionPacman* actionPacman;

    for (int i = 0; i < _steps.size(); i++)
    {
        stepPacman = _steps[i];
        actionPacman = stepPacman->GetAction();
        _outputs.push_back(actionPacman->GetAction());
    }
}

vector<vector<double>> SourceRGB::GetNeuralNetworkInputs()
{
    return _inputs;
}

vector<vector<double>> SourceRGB::GetNeuralNetworkOutputs()
{
    return _outputs;
}

string SourceRGB::GetDataPath() const
{
    return _dataPath;
}
void  SourceRGB::SetDataPath(const string dataPath)
{
    _dataPath = dataPath;
}
