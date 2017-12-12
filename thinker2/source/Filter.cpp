#include <Filter.h>
#include <string>

Filter::Filter()
{

}

void Filter::Load(string configurationFilePath)
{
    ifstream fileJson ((configurationFilePath).c_str());

    if (fileJson.peek() != EOF)
    {
        if(fileJson.good())
        {
            fileJson >> _configJson;
        }
        else
        {
            printf("SOME THING ABOUT THIS FILE <%s.json> IS WRONG!\n", configurationFilePath.c_str());
        }
    }    
    else
    {   
        // ERROR
    }

    fileJson.close();
}

vector<vector<double>>& Filter::FilterObservation(vector<vector<double>>& observation)
{
    for (Json::iterator it = _configJson.begin(); it != _configJson.end(); ++it) {
        auto key = it.key();
        auto filterOption = _configJson[key];

        if (key == FILTER_BY_COLUMNS)
        {
            vector<int> columns = filterOption[FILTER_COLUMNS];

            if (filterOption[FILTER_OPERATION] == FILTER_COLUMNS_ONLY_THIS)
            {
                observation = Consider(observation, columns);
            }
            else
            {
                observation = Ignore(observation, columns);
            }
        }

        if (key == FILTER_EXCLUDE_CONSTANTS)
        {
            if (filterOption == true)
            {
                observation = Variables(observation);
            }
        }

        if (key == FILTER_BY_VALUE)
        {
            int value = filterOption[FILTER_BY_VALUE_VALUE];

            if (filterOption[FILTER_OPERATION] == FILTER_BY_VALUE_OPERATION_GREATER_EQUAL)
            {
                ByValue(observation, value, ByValueOperator::GREATER_EQUAL);
            }
            else
            {
                ByValue(observation, value, ByValueOperator::LESS_EQUAL);
            }
        }

        if (key == FILTER_BY_RANGES_VALUES)
        {
            vector<Json> ranges = filterOption[FILTER_BY_RANGES_VALUES_RANGES];
            vector<pair<int, int>> filterBytes;

            for (auto const& jsonObj: ranges)
            {
                filterBytes.push_back(pair<int, int>(jsonObj[FILTER_BY_RANGES_VALUES_MIN], jsonObj[FILTER_BY_RANGES_VALUES_MAX]));
            }

            observation = Multiple(observation, filterBytes);
            PrintMatrix(observation);
        }

        if (key == FILTER_TOP_CHANGE_COLUMNS)
        {
            int quantity = _configJson[FILTER_TOP_CHANGE_COLUMNS];
            ByColumnsChangeMostTimes(observation, quantity);
        }

        if (key == FILTER_TIMES_COLUMN_CHANGE_VALUE)
        {
            int quantity = filterOption["value"];
            if (filterOption[FILTER_OPERATION] == FILTER_BY_VALUE_OPERATION_GREATER_EQUAL)
            {
                observation = ByColumnsChangeValue(observation, quantity, ByValueOperator::GREATER_EQUAL);
            }
            else
            {
                observation = ByColumnsChangeValue(observation, quantity, ByValueOperator::LESS_EQUAL);
            }
        }        
    }
    return observation;
}

void Filter::SelectColumns(vector<vector<double>>& bytes, const int column, int nveces, vector<int>& v)
{
    int aux = 0;
    for (int i = 1; i <= bytes.size(); i++)
    {
        if(i<bytes.size())
        {
            if(bytes[i][column] != bytes[i-1][column])
            {
                aux++;
            }       
        }
    }
    if (aux>=nveces)
    {
        v.push_back(column);
    }
}

vector<vector<double>> Filter::ByColumns(vector<vector<double>>& bytes, vector<int>& escogidos)
{
    int count = 0;

    vector<vector<double>> res;

    for (int row = 0; row < bytes.size(); row++)
    {
        vector<double> aux;

        for (int i = 0; i < escogidos.size(); i++)
        {
            aux.push_back(bytes[row][escogidos[i]]);
        }
        res.push_back(aux);
    }
    return res;
}

vector<vector<double>> Filter::ByColumnsChangeValue(vector<vector<double>>& bytes, int quantity, ByValueOperator op)
{
    vector<int> v;

    for (int j = 0; j < bytes[0].size(); j++)
    {
        SelectColumns(bytes, j, quantity, v);
    }
    if(op == ByValueOperator::GREATER_EQUAL)
    {
        return ByColumns(bytes, v);
    }
    else
    {
        puts("que cagada");
        return Ignore(bytes, v);
    }
}

void Filter::ExceptColumns(vector<vector<double>>& bytes, vector<int>& columns)
{
    for (int i = 0; i < bytes.size(); i++)
    {
        for (int j = 0; j < columns.size(); j++)
        {
            bytes[i].erase (bytes[i].begin()+columns[j]-j);
        }
    }
}

vector<vector<double>> Filter::Fill(vector<vector<double>> bytes, vector<int> receiveFilters)
{
    vector<vector<double>> newDataBytes;
    vector<double> bytesByStep;
    int sizeSteps = bytes.size();
    int sizeReceiveFilters = receiveFilters.size();

    for (int step = 0; step < sizeSteps; ++step)
    {
        for (int byte = 0; byte < sizeReceiveFilters; ++byte)
        {
            bytesByStep.push_back(bytes[step][receiveFilters[byte]]);
        }

        newDataBytes.push_back(bytesByStep);
        bytesByStep.clear();
    }

    return newDataBytes;
}

vector<int> Filter::TakeBytes(bool activateConsiderIgnore, vector<int> receiveFilters, int sizeBytes)
{
    if (activateConsiderIgnore == true)
    {
        return receiveFilters;
    }
    else
    {
        Node* tree = NULL;
        vector<int> newFilterBytes;
        int sizeReceiveFilters = receiveFilters.size();

        for (int byte = 0; byte < sizeReceiveFilters; ++byte)
        {
            tree->Add(tree, receiveFilters[byte]);
        }

        for (int byte = 0; byte < sizeBytes; ++byte)
        {
            if (tree->Search(tree, byte) == false)
            {
                newFilterBytes.push_back(byte); 
            }
        }

        tree->Clear(tree);

        return newFilterBytes;
    }
}

vector<int> Filter::InequalityBytes(bool activateMoreLess, int receiveFilter, int sizeBytes)
{
    vector<int> newFilterBytes;

    if (activateMoreLess == true)
    {
        for (int byte = receiveFilter; byte < sizeBytes; ++byte)
        {
            newFilterBytes.push_back(byte);
        }
    }
    else
    {
        for (int byte = 0; byte <= receiveFilter; ++byte)
        {
            newFilterBytes.push_back(byte);
        }
    }

    return newFilterBytes;
}

vector<int> Filter::RangeBytes(bool activateSimpleMultiple, pair<int, int> simpleFilter, vector<pair<int, int>> multipleFilters)
{
    vector<int> newFilterBytes;
    auto fillRange = [&newFilterBytes](pair<int, int> filters) -> void
    {
        int startRange = filters.first;
        int endRange = filters.second;

        for (int byte = startRange; byte <= endRange; ++byte)
        {
            newFilterBytes.push_back(byte);
        }
    };

    if (activateSimpleMultiple == true)
    {
        fillRange(simpleFilter);
    }
    else
    {
        int startSizeFilter = 0;
        int endSizeFilter = multipleFilters.size();

        while(startSizeFilter < endSizeFilter)
        {
            fillRange(multipleFilters[startSizeFilter]);

            startSizeFilter++;
        }
    }

    return newFilterBytes;
}

vector<int> Filter::FixBytes(vector<vector<double>> bytes, int minimumChangeThreshold, bool activateBytesCounter, int sizeThresholdByByte)
{
    bool isRepetitiveByte;
    int thresholdCounter;
    int step;
    int sizeSteps = bytes.size();
    int sizeBytes = bytes[FIRST_STEP_BYTES].size();
    Node* tree;
    vector<int> newFilterBytes;
    vector<int> counterDifferentBytes;

    for (int byte = 0; byte < sizeBytes; ++byte)
    {
        isRepetitiveByte = true;
        thresholdCounter = 0;
        step = 0;
        tree = NULL;

        tree->Add(tree, bytes[FIRST_STEP_BYTES][byte]);

        while((step < sizeSteps) && (isRepetitiveByte != false))
        {
            if (activateBytesCounter == true)
            {
                if (tree->Search(tree, bytes[step][byte]) == false)
                {
                    tree->Add(tree, bytes[step][byte]);

                    thresholdCounter = tree->countNodes(tree);
                }

                if (thresholdCounter >= sizeThresholdByByte)
                {
                    newFilterBytes.push_back(byte);

                    isRepetitiveByte = false;
                }
            }
            else
            {
                if (thresholdCounter < minimumChangeThreshold)
                {
                    if (tree->Search(tree, bytes[step][byte]) == false)
                    {
                        tree->Add(tree, bytes[step][byte]);
                    }

                    thresholdCounter = tree->countNodes(tree);

                    if (thresholdCounter == minimumChangeThreshold)
                    {
                        newFilterBytes.push_back(byte);
                    }
                }
                else
                {
                    isRepetitiveByte = false;
                }
            }

            step++;
        }

        tree->Clear(tree);
    }

    return newFilterBytes;
}

vector<vector<double>> Filter::Consider(vector<vector<double>> bytes, vector<int> filterBytes)
{
    return Fill(bytes, TakeBytes(true, filterBytes, bytes[FIRST_STEP_BYTES].size()));
}

vector<vector<double>> Filter::Ignore(vector<vector<double>> bytes, vector<int> filterBytes)
{
    return Fill(bytes, TakeBytes(false, filterBytes, bytes[FIRST_STEP_BYTES].size()));
}

vector<vector<double>> Filter::Multiple(vector<vector<double>>& bytes, vector<pair<int, int>>& filterBytes)
{
    pair<int, int> none;

    return Fill(bytes, RangeBytes(false, none, filterBytes));
}

Node* Filter::FillValueRangeBytes(vector<pair<int, int>> rangeFilterBytes)
{
    Node* tree = NULL;
    int startSizeFilter = 0;
    int endSizeFilter = rangeFilterBytes.size();

    while(startSizeFilter < endSizeFilter)
    {
        for (int range = rangeFilterBytes[startSizeFilter].first; range <= rangeFilterBytes[startSizeFilter].second; ++range)
        {
            tree->Add(tree, range);
        }

        startSizeFilter++;
    }

    return tree;
}

vector<int> Filter::rangeThreshold(vector<vector<double>> bytes, vector<pair<int, int>> rangeValueByByte)
{
    vector<int> newFilterBytes;
    int sizeSteps = bytes.size();
    int sizeBytes = bytes[FIRST_STEP_BYTES].size();
    bool isByteInRange = false;
    Node* tree = NULL;

    tree = FillValueRangeBytes(rangeValueByByte);

    for (int byte = 0; byte < sizeBytes; ++byte)
    {
        int step = 0;
        isByteInRange = false;

        while((step < sizeSteps) && (isByteInRange == false))
        {
            if (tree->Search(tree, bytes[step][byte]) == true)
            {
                //printf("byte<%d><%d>={%0.2f}\n", step, byte, bytes[step][byte]);

                newFilterBytes.push_back(byte);

                isByteInRange = true;
            }

            step ++;
        }
    }

    tree->Clear(tree);

    return newFilterBytes;
}

vector<vector<double>> Filter::ThresholdRangeByByte(vector<vector<double>> bytes, vector<pair<int, int>> rangeValueByByte)
{
    return Fill(bytes, rangeThreshold(bytes, rangeValueByByte));
}

vector<vector<double>> Filter::Variables(vector<vector<double>> bytes)
{
    int staticThresholdNumber = 2;
    bool staticActivateBytesCounter = false;
    int staticThresholdByByte = -1;

    return Fill(bytes, FixBytes(bytes, staticThresholdNumber, staticActivateBytesCounter, staticThresholdByByte));
}

vector<vector<double>> Filter::VariableThreshold(vector<vector<double>> bytes, int threshold)
{
    bool staticActivateBytesCounter = false;
    int staticThresholdByByte = -1;

    return Fill(bytes, FixBytes(bytes, threshold, staticActivateBytesCounter, staticThresholdByByte));
}

void Filter::ByValue(vector<vector<double>>& bytes, int limit, ByValueOperator op)
{
    for (int row = 0; row < bytes.size(); row++)
    {
        for (int col = 0; col < bytes[row].size(); col++)
        {
            if (op == ByValueOperator::GREATER_EQUAL)
            {
                if (bytes[row][col] < limit)
                {
                    bytes[row][col] = 0;   
                }
            }
            else
            {
                if(bytes[row][col]>limit)
                {
                    bytes[row][col] = 0;
                }    
            }
        }
    }
}

void Filter::ByColumnsChangeMostTimes(vector<vector<double>>& bytes, int quantity)
{
    if (bytes[0].size() >= quantity)
    {
        vector<double> aux;
        vector<pair<int, int>> pairs;

        int counter = 0;

        for (int col = 0; col < bytes[0].size(); col++)
        {
            for (int row = 0; row < bytes.size(); row++)
            {
                double elem = bytes[row][col];

                if (!(find(aux.begin(), aux.end(), elem) != aux.end()))
                {
                    aux.push_back(bytes[row][col]);
                    counter++;
                }
            }

            pairs.push_back(pair<int, int>(col, counter));

            aux.clear();
            counter = 0;
        }

        sort(pairs.begin(), pairs.end(), [=](pair<int, int>& a, pair<int, int>& b) {
            return b.second < a.second;
        });

        vector<double> a;
        vector<vector<double>> res;
    
        for (int j = 0; j < bytes.size(); j++)
        {
            for(int i = 0; i < quantity; i++)
            {
                a.push_back(bytes[j][pairs[i].first]);
            }    

            res.push_back(a);
            a.clear();
        }

        bytes = res;
    }
    else
    {
        throw "el tamanio requerido es mas grande que el vector";
    }
}

void Filter::PrintVectorPairs(vector<pair<int, int>>& v)
{
    for (const auto& p : v)
    {
      std::cout << p.first << ", " << p.second << std::endl;
    }
}

void Filter::PrintMatrix(vector<vector<double>>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }

        cout << endl;
    }
}

Filter::~Filter()
{

}