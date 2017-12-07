#ifndef SOURCEFULLRAMM_H_
#define SOURCEFULLRAMM_H_

#include <IDataSource.h>
#include <Defines.h>
#include <StepPacman.h>

#include <fstream>
#include <vector>

#include <json.hpp>

using Json = nlohmann::json;
using namespace std;

class SourceFullRAM : public IDataSource
{	
	vector<vector<double>> _bytes;
	vector<vector<double>> _keys;
	vector<int> _steps;
    bool _filter;

	public:
        SourceFullRAM();
        SourceFullRAM(bool filter);
		SourceFullRAM(string& nnWeights);
		~SourceFullRAM();
    	void ReadAllData() override;
    	void ProcessAllData() override;
    
    	vector<vector<double>> GetNeuralNetworkInputs() override;
    	vector<vector<double>> GetNeuralNetworkOutputs() override;

    	void SetDataPath(const string dataPath) override;
    	string GetDataPath() const override;

    	vector<string> GetFolderNames(string path);
    	void ProcessData(vector<double> observation, string stringRender) override;
};

#endif //SOURCEFULLRAMM_H_