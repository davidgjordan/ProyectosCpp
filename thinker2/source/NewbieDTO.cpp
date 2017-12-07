#include <NewbieDTO.h>


NewbieDTO::NewbieDTO()
{
    this->_nameTrainer = DEFAULT_NAME_TRAINER;
    this->_gameDirectory = DEFAULT_GAME_DIRECTORY;
    this->_serverAddress = DEFAULT_SERVER_ADDRESS;
    this->_trainMethod = DEFAULT_TRAIN_METHOD;
    this->_thresholdsPath = DEFAULT_THRESHOLDS_PATH;
    this->_keysConfigPath = DEFAULT_KEYS_CONFIG_PATH;
}

string NewbieDTO::GetTrainer()const
{
   return _nameTrainer;
}

string NewbieDTO::GetDirectory()const
{
    return _gameDirectory;
}

string NewbieDTO::GetServer()const
{
    return _serverAddress;
}

string NewbieDTO::GetTrainMethod()const
{
    return _trainMethod;
}

string NewbieDTO::GetThresholdsPath()const
{
    return _thresholdsPath;
}

string NewbieDTO::GetKeysConfigPath()const
{
    return _keysConfigPath;
}

void NewbieDTO::SetTrainer(const string& newName)
{
    _nameTrainer = newName;
}

void NewbieDTO::SetDirectory(const string& newGameDirectory)
{
    _gameDirectory = newGameDirectory;
}

void NewbieDTO::SetServer(const string& newServerAddress)
{
    _serverAddress = newServerAddress;
}

void NewbieDTO::SetTrainMethod(const string& newTrainMethod)
{
    _trainMethod = newTrainMethod;
}

void NewbieDTO::SetThresholdsPath(const string& newThresholdsPath)
{
    _thresholdsPath = newThresholdsPath;
}

void NewbieDTO::SetKeysConfigPath(const string newkeysConfigPath)
{
    _keysConfigPath = newkeysConfigPath;
}

NewbieDTO::~NewbieDTO()
{
    //dtor
}
