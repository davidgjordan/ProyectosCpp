#ifndef IDATASOURCE_H_
#define IDATASOURCE_H_

#include <IGameModel.h>
#include <IStep.h>
#include <IDataSource.h>

#include <vector>
#include <string>

using namespace std;

class IDataSource
{
    protected:
        string _dataPath;
        vector<std::vector<double>> _inputs;
        vector<std::vector<double>> _outputs;
    public:
        virtual void ReadAllData() = 0;
        virtual void ProcessAllData() = 0;
        virtual void ProcessData(vector<double> observation, string stringRender) = 0;

        virtual vector<vector<double>> GetNeuralNetworkInputs() = 0;
        virtual vector<vector<double>> GetNeuralNetworkOutputs() = 0;

        virtual void SetDataPath(const string dataPath) = 0;
        virtual string GetDataPath() const = 0; 
        virtual ~IDataSource(){}
};
#endif // IDATASOURCE_H_