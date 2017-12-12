#ifndef FILTER_H_
#define FILTER_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <treeRam.h>
#include <Defines.h>
#include <json.hpp>

using namespace std;
using Json = nlohmann::json;

enum class ByValueOperator
{
    GREATER_EQUAL,
    LESS_EQUAL
};

enum class ByColumnsOperator
{
    CONSIDER,
    EXCLUDE
};

class Filter
{
    Json _configJson;

    public:
        Filter();
        void Load(string configurationFilePath);
        vector<vector<double>>& FilterObservation(vector<vector<double>>& observation);
        ~Filter();        

    private:
        void SelectColumns(vector<vector<double>>& bytes, const int column, int nveces, vector<int>& v);     

        vector<vector<double>> Consider(vector<vector<double>> bytes, vector<int> filterBytes);
        vector<vector<double>> Ignore(vector<vector<double>> bytes, vector<int> filterBytes);      
        vector<vector<double>> Multiple(vector<vector<double>>& bytes, vector<pair<int, int>>& filterBytes);
        vector<vector<double>> Variables(vector<vector<double>> bytes);
        vector<vector<double>> VariableThreshold(vector<vector<double>> bytes, int threshold);
        vector<vector<double>> Fill(vector<vector<double>> bytes, vector<int> receiveFilters);
        vector<int> TakeBytes(bool activateConsiderIgnore, vector<int> receiveFilters, int sizeBytes);
        vector<int> InequalityBytes(bool activateMoreLess, int receiveFilter, int sizeBytes);
        vector<int> RangeBytes(bool activateSimpleMultiple, pair<int, int> simpleFilter, vector<pair<int, int>> multipleFilters);
        vector<int> FixBytes(vector<vector<double>> bytes, int minimumChangeThreshold, bool activateBytesCounter, int sizeThresholdByByte);
        vector<vector<double>> ByColumns(vector<vector<double>>& bytes, vector<int>& escogidos);
        void ByValue(vector<vector<double>>& bytes, int limit, ByValueOperator op);
        void ExceptColumns(vector<vector<double>>& bytes, vector<int>& columns);
        void ByColumnsChangeMostTimes(vector<vector<double>>& bytes, int quantity);
        vector<vector<double>> ByColumnsChangeValue(vector<vector<double>>& bytes, int quantity, ByValueOperator op);
        void PrintMatrix(vector<vector<double>>& v);
        void PrintVectorPairs(vector<pair<int, int>>& v);
        Node* FillValueRangeBytes(vector<pair<int, int>> rangeFilterBytes);
        vector<int> rangeThreshold(vector<vector<double>> bytes, vector<pair<int, int>> rangeValueByByte);
        vector<vector<double>> ThresholdRangeByByte(vector<vector<double>> bytes, vector<pair<int, int>> rangeValueByByte);
};      

#endif //FILTER_H_