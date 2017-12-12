#ifndef IBRAIN_H_
#define IBRAIN_H_
#include <string>
#include <functional>

#include <json.hpp>
#include <IDataSource.h>

using Json = nlohmann::json;
using namespace std;

class IBrain
{
public:
     virtual void CreateNeuronalNetwork(const string& nnWeigths) = 0;
     virtual void TrainNeuronalNetwork(IDataSource*& dataSource,
     const string& gameName, const string& nnTopology, const string& nnWeigths, function<void (Json&)> jsonFunc) = 0;
     virtual float GetAction(vector<float> observation, string render, IDataSource* dataSource) = 0;
};
#endif // IBRAIN_H_