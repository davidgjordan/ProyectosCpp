#ifndef NEWBIE_H_
#define NEWBIE_H_

#include <NewbieDTO.h>
#include <ExceptionNoInstall.h>
#include <ExceptionNoPath.h>
#include <ExceptionNoMethod.h>
#include <ExceptionGame.h>

class IDataSource;
class Persistence;
class IBrain;

class Newbie : public NewbieDTO
{
    IDataSource* _dataSource;
    Persistence* _persistence;

    public:
        Newbie();
        void Install();
        bool IsInstalled();
        void AssignTrainer(const string& trainerName);
        void AssignDirectory(const string& directory);
        void AssignServer(const string& serverAddress);
        void SetDataSource(const string& trainingMethod, const string& gameName, const string& keyboardType, const string& NNTopology, const string& NNWeigths, bool filter);
        void Play(const string& nameGame, const string& keysConfig, const bool& saveActionNone);
        void Evaluate(const string& trainingMethod, const string& weigths);
        IDataSource* getDataSource();
        void Load();
        void ExecuteCommandTrain(string typeMethod, string nameGame, string thresholdsPath, string NNTopology,string NNWeigths);
        virtual ~Newbie();

    private:
        
        void Train(const string& trainingMethod, const string& gameName, const string& keyboardType, const string& nnTopology, const string& nnWeigths, const bool& filter);
};

#endif // NEWBIE_H_
