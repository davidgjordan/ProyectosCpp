#ifndef NORMALIZATION_H_
#define NORMALIZATION_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <json.hpp>
#include <BrainPersistence.h>

using namespace std;

class Normalization
{
	vector<double> _min;
	vector<double> _max;
public:
	Normalization();	
	void Normalize(vector<vector<double>>& data);
    void GausNormal(vector<vector<double>>& data, const int column);
    void MinMaxNormal(vector<vector<double>>& data, const int column);
    vector<double> Normalize_WhitDates(vector<vector<double>>& data);
    void MinMaxNormalObs(vector<vector<double>>& data, const int column);
    vector<double> GetMin();
    vector<double> GetMax();
    void SetMin(vector<double>& min);
    void SetMax(vector<double>& max);


	~Normalization();	

};
#endif//NORMALIZATION_H_