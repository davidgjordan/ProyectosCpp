#ifndef TRAINNER_H_
#define TRAINNER_H_

#include <json.hpp>

#include <IBrain.h>

using Json = nlohmann::json;
using namespace std;

class IDataSource;

class Trainer
{
    IBrain* _brain;
    
    public:
       Trainer();
       ~Trainer();
       void Train(IDataSource*& dataSource, const string& gameName, const string& keyboardType, const string& nnTopology, const string& nnWeigths, const bool& filter);
       void AsignTrainParameters(const string& nnWeigths, const string& gameName, const string& keyboardType, const bool& filter);
};

#endif //TRAINNER_H_