#ifndef SOURCERAM_H_
#define SOURCERAM_H_

#include <IDataSource.h>
#include <Defines.h>
#include <fstream>
#include <vector>
#include <dirent.h>
#include <json.hpp>
#include <GameModelPacman.h>

class StepPacman;

using Json = nlohmann::json;
using namespace std;

class SourceRAM: public IDataSource
{
private:
	vector<StepPacman*> _steps;
    vector<vector<double>> _bytes;
    vector<vector<double>> _keys;
    vector<string> _fileNames;
    Json _matchJson;
    StepPacman * _stepPacman;

public:
    SourceRAM();
    ~SourceRAM();
    void ReadAllData() override;
    void ProcessAllData() override;
    void ProcessData(vector<double> observation, string stringRender) override;
    vector<vector<double>> GetNeuralNetworkInputs() override;
    vector<vector<double>> GetNeuralNetworkOutputs() override;
    void SetDataPath(const string dataPath) override;
    string GetDataPath() const override;

    #ifdef GTEST
    public:
    #else
    private:
    #endif
    void PrintInternalData() const;
    void PrintNeuralNetworkData() const;
    vector<string> GetFolderNames(string path);
    void ModelData(vector<double>& bytes, GameModelPacman*& gameModelPacman);
};
#endif //SOURCERAM_H_