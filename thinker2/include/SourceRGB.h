#ifndef SOURCERGB_H_
#define SOURCERGB_H_

#include <IDataSource.h>
#include <Defines.h>
#include <RgbTool.h>
#include <Pacman.h>
#include <Ghost.h>
#include <Way.h>
#include <Wall.h>
#include <GameModelPacman.h>
#include <StepPacman.h>

#include <string>
#include <dirent.h>

#include <json.hpp>

using namespace std;
using Json = nlohmann::json;

class SourceRGB: public IDataSource
{
private:
    vector<StepPacman*> _steps;
    Json _matchJson;
    vector<string> _fileNames;
    RgbTool* _rgbTool;
    StepPacman* _stepPacman;
    ActionPacman* _actionPacman;
    GameModelPacman* _modelPacman ;
public:
    SourceRGB();
    SourceRGB(string dataPath);
    ~SourceRGB();

    void ReadAllData() override;
    void ProcessAllData() override;
    void SetDataPath(const string dataPath) override;
    void ProcessData(vector<double> observation, string stringRender) override;
    string GetDataPath() const override;
    void LoadMatchJson(string path);
    vector<string> NameFiles(string path);
    void GenerateInputsRGB();
    void GenerateInputRGB();
    void GenerateOutputsRGB();

    vector<vector<double>> GetNeuralNetworkInputs() override;
    vector<vector<double>> GetNeuralNetworkOutputs() override;
};
#endif //SOURCERGB_H_