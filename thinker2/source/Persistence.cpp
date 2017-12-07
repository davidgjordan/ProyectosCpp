#include <Persistence.h>


Persistence::Persistence()
{
   
}

void Persistence::SaveNNTopology(const int quantityLayersHidden, const int hiddenNodes, const string path)
{
    Json jsonNNTopology;
    ofstream fileWriter{path};
    jsonNNTopology[QUANTITYLAYERSHIDDEN] = quantityLayersHidden;
    jsonNNTopology[HIDDENNODES] = hiddenNodes;
    fileWriter << setw(INDENTATION) << jsonNNTopology << "\n";
    fileWriter.close();
}

int Persistence::LoadNNTopology(const string name, const string path)
{
    Json jsonNNTopology;
    ifstream fileReader{path};
    if(fileReader.is_open())
    {
        fileReader >> jsonNNTopology;
        return jsonNNTopology[name];
    }
    else
    {
        throw ExceptionNoFile();
    }
    return 0;
}

void Persistence::Save(NewbieDTO* newbie)
{
    ofstream fileWriter {JSONFILE};
    _manager[TRAINER] = newbie->GetTrainer();
    _manager[DIRECTORY] = newbie->GetDirectory();
    _manager[SERVER] = newbie->GetServer();
    _manager[METHOD] = newbie->GetTrainMethod();
    _manager[THRESHOLDS] = newbie->GetThresholdsPath();
    _manager[KEYBOARD] = newbie->GetKeysConfigPath();
    fileWriter << setw(INDENTATION) << _manager << "\n";
    fileWriter.close(); 
}

Newbie* Persistence::Load(Newbie* newbie)
{
    ifstream fileReader {JSONFILE};
    fileReader >> _manager;
    newbie->SetTrainer(_manager[TRAINER]);
    newbie->SetDirectory(_manager[DIRECTORY]);
    newbie->SetServer(_manager[SERVER]);
    newbie->SetTrainMethod(_manager[METHOD]);
    newbie->SetThresholdsPath(_manager[THRESHOLDS]);
    newbie->SetKeysConfigPath(_manager[KEYBOARD]);
    return newbie;
}

bool Persistence::IsInstalled()
{
    ifstream g {JSONFILE};

    if(g.good())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string Persistence::CreateNewGame(NewbieDTO* newbie, const string& gameName)
{
    time_t timeSystem = time(0);
    struct tm *tlocal = localtime(&timeSystem);
    char output[DATA_LENGTH];
    strftime(output, DATA_LENGTH, "%y_%m_%d_%H_%M_%S", tlocal);
    string path = newbie->GetDirectory()+ gameName +"/";

    ifstream validDirectory{path};
    if(!validDirectory.is_open())
    {   
        string auxPath = "mkdir -p " + path;
        system(auxPath.c_str());
    }

    path += newbie->GetTrainer() + (string)output;

    string auxPath = "mkdir -p " + path;
    system(auxPath.c_str());

    auxPath = "mkdir -p " + path + "/" + RGB_PATH;
    system(auxPath.c_str());

    string newGameFile = path + "/" + MATCH_JSON;
    ofstream fileWriter {newGameFile}; 
    _managerGame[TRAINER] = newbie->GetTrainer();
    _managerGame[GAME_SCORE] = "";
    _managerGame[GAME_STEPS] = "";
    _managerGame[THRESHOLDS] = newbie->GetThresholdsPath();
    fileWriter << setw(INDENTATION) << _managerGame << "\n";

    fileWriter.close();
    return path;
}

Persistence::~Persistence()
{
    //dtor
}