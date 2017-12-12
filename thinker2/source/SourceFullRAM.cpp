#include <SourceFullRAM.h>
#include <treeRam.h>
#include <StepPacman.h>
#include <Ghost.h>
#include <Pacman.h>
#include <GameModelPacman.h>
#include <Normalization.h>
#include <dirent.h>
#include <json.hpp>
#include <Filter.h>

using Json = nlohmann::json;
using namespace std;

SourceFullRAM::SourceFullRAM()
{

}

SourceFullRAM::SourceFullRAM(bool filter)
{
    _filter = filter;
}

SourceFullRAM::SourceFullRAM(string& nnWeights)
{
    Json jsonWeigths;
    ifstream dataStream {nnWeights};
    dataStream >> jsonWeigths;

    _filter = jsonWeigths[FILTER];
}

SourceFullRAM::~SourceFullRAM()
{

}

void SourceFullRAM::ReadAllData()
{
	vector<string> folders = GetFolderNames(_dataPath);

    for (int i = 0; i < folders.size(); i++)
    {
        Json jsonData;
        ifstream dataStream {_dataPath + folders[i] + '/' + MATCH_JSON};
        dataStream >> jsonData;

        Json steps = jsonData[GAME_STEPS];
        Json keys = jsonData[GAME_KEYS];

        _steps.push_back(jsonData[GAME_STEPS].size());
        
        for (Json::iterator it = steps.begin(); it != steps.end(); ++it) {
            _bytes.push_back(it.value());
        }

        for (Json::iterator it = keys.begin(); it != keys.end(); ++it) {
            _keys.push_back(it.value());
        }
    }
}

void SourceFullRAM::ProcessAllData()
{
    if (_filter == true)
    {
        Json jsonData;
        ifstream fileReader {JSONFILE};
        fileReader >> jsonData;

        string thresholdsPath = jsonData[THRESHOLDS];

        Filter filter;
        filter.Load(thresholdsPath);
        _inputs = filter.FilterObservation(_bytes);    
    }
    else
    {
        _inputs = _bytes;
    }
}

vector<vector<double>> SourceFullRAM::GetNeuralNetworkInputs()
{
	return _inputs;
}

vector<vector<double>> SourceFullRAM::GetNeuralNetworkOutputs()
{
	_outputs = _keys;

	return _outputs;
}

void SourceFullRAM::SetDataPath(const string dataPath)
{
	_dataPath = dataPath;
}

string SourceFullRAM::GetDataPath() const
{
	return _dataPath;
}

vector<string> SourceFullRAM::GetFolderNames(string path)
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
    delete(dirent);
    
    return files;
}

void SourceFullRAM::ProcessData(vector<double> observation, string stringRender)
{
    _inputs.clear();

    if (_filter)
    {
        vector<vector<double>> matrix;
        matrix.push_back(observation);

        Json jsonData;
        ifstream fileReader {JSONFILE};
        fileReader >> jsonData;

        string thresholdsPath = jsonData[THRESHOLDS];

        Filter filter;
        filter.Load(thresholdsPath);
        _inputs = filter.FilterObservation(matrix);
    }
    else
    {
        _inputs.push_back(observation);
    }
}