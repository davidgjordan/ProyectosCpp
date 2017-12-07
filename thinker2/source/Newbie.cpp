#include <Newbie.h>
#include <Persistence.h>
#include <SourceRAM.h>
#include <SourceFullRAM.h>
#include <SourceRGB.h>
#include <Trainner.h>
#include <BrainThinker.h>
#include <Player.h>
#include <Agent.h>

Newbie::Newbie()
{
    _dataSource = nullptr;
    _persistence = new Persistence();
}

void Newbie::Install()
{
    if( !_persistence->IsInstalled() )
    {
        _persistence->Save(this);
        cout << "Newbie was installed succesfully" << endl;
    }
    else
    {
        cout << "Already Installed" << endl;
    }   
}

void Newbie::AssignTrainer(const string& trainerName)
{   
    SetTrainer(trainerName);
    _persistence->Save(this);
    cout << "The trainer name was updated succesfully" << endl;
}

void Newbie::AssignDirectory(const string& directory)
{
    if(_persistence->IsInstalled())
    {   
        SetDirectory(directory);
        _persistence->Save(this);
        cout << "The path was updated succesfully" << endl;
    }
    else
    {
        throw ExceptionNoInstall();
    }
}

void Newbie::AssignServer(const string& serverAddress)
{
    if(_persistence->IsInstalled())
    {
        SetServer(serverAddress);
        _persistence->Save(this);
        cout << "The server address was updated succesfully" << endl; 
    }
    else
    {
        throw ExceptionNoInstall();
    }  
}

void Newbie::SetDataSource(const string& trainingMethod,const string& gameName, const string& keyboardType, const string& nnTopology, const string& nnWeigths, bool filter)
{   
    if (trainingMethod == METHOD_RAM)
    {
        _dataSource = new SourceRAM();
    }
    else if (trainingMethod == METHOD_RGB)
    {
        _dataSource = new SourceRGB();
    }
    else if (trainingMethod == METHOD_FULLRAM)
    {
        _dataSource = new SourceFullRAM(filter);
    }else
    {
        throw ExceptionNoMethod();  
    }
    
    Train(trainingMethod, gameName, keyboardType, nnTopology, nnWeigths, filter);
}

void Newbie::Train(const string& trainingMethod, const string& gameName, const string& keyboardType, const string& nnTopology, const string& nnWeigths, const bool& filter)
{
    string directory = GetDirectory() + gameName + "/";
    ifstream validDirectory{directory};

    if(validDirectory.is_open())
    {  
        _dataSource->SetDataPath(directory);
        Trainer trainer;
        trainer.Train(_dataSource, gameName, keyboardType, nnTopology, nnWeigths, filter);
        SetTrainMethod(trainingMethod);
        _persistence->Save(this);
    }
    else
    {
        throw ExceptionGame();
    }
}

void Newbie::Play(const string& nameGame, const string& keysConfig, const bool& saveActionNone)
{    
    Player run {nameGame, _persistence->CreateNewGame(this, nameGame), GetServer(), keysConfig, saveActionNone, GetKeysConfigPath()}; 
}


void Newbie::Evaluate(const string& trainingMethod, const string& weigths)
{
    Agent agente {GetServer(), trainingMethod, weigths}; 
}

IDataSource* Newbie::getDataSource()
{
    return _dataSource;
}
void Newbie::Load()
{
    if(_persistence->IsInstalled())
    {
        Newbie* newNewbie = _persistence->Load(this);
        _dataSource = newNewbie->getDataSource();
    }
    else
    {
        throw ExceptionNoInstall();
    }
}

bool Newbie::IsInstalled()
{
    return _persistence->IsInstalled();
}

Newbie::~Newbie()
{
    delete _dataSource;
}
