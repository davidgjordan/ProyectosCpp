#include <Normalization.h>

Normalization::Normalization()
{}

void Normalization::Normalize(vector<vector<double>>& data)
{
    for (int column = 0; column < data[1].size(); column++)
    {
        MinMaxNormal(data,column);
    }
}

vector<double> Normalization::Normalize_WhitDates(vector<vector<double>>& data)
{
    for (int column = 0; column < data[0].size(); column++)
    {
        MinMaxNormalObs(data,column);
    }
    return data[0];
}

void Normalization::GausNormal(vector<vector<double>>& data, const int column)
{
    int sum = 0;
    for (int i = 0; i < data.size(); i++)
    {
        sum = sum + data[i][column];
    }

    double mean = sum/data.size();
    double sumSquares = 0;
    for (int i = 0; i < data.size(); ++i)
    {
        sumSquares = sumSquares + ((data[i][column] - mean) * (data[i][column] - mean));
    }
    double stdDev = sqrt(sumSquares/data.size());

    for (int i = 0; i < data.size(); ++i)
                data[i][column] = (data[i][column] - mean) / stdDev;
}

void Normalization::MinMaxNormal(vector<vector<double>>& vector, const int column)
{
    double min = vector[0][column];
    double max = vector[0][column];
    for (int i = 0; i < vector.size(); ++i)
    {
        if (vector[i][column] < min)
            min = vector[i][column];
        if (vector[i][column] > max)
            max = vector[i][column];
    }
    double range = max - min;

    _min.push_back(min);
    _max.push_back(max);
    
    if (range == 0.0)
    {
        for (int i = 0; i < vector.size(); ++i)
            vector[i][column] = 0.5;
        return;
    }
    for (int i = 0; i < vector.size(); ++i)
        vector[i][column] = (vector[i][column] - min) / range;
}

void Normalization::MinMaxNormalObs(vector<vector<double>>& vector, const int column)
{
    double range = _max[column]-_min[column];

    if (range == 0.0)
    {
        for (int i = 0; i < vector.size(); ++i)
            vector[i][column] = 0.5;
        return;
    }
    for (int i = 0; i < vector.size(); ++i)
        vector[i][column] = (vector[i][column] - _min[column]) / range;
}

vector<double> Normalization::GetMin()
{
    return _min;
}

vector<double> Normalization::GetMax()
{
    return _max;
}
void Normalization::SetMin(vector<double>& min)
{
    _min = min;
}

void Normalization::SetMax(vector<double>& max)
{
    _max = max;
}
Normalization::~Normalization()
{}

