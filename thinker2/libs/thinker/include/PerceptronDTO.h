#ifndef PERCEPTRONDTO_H_
#define PERCEPTRONDTO_H_
#include <vector>
#include <iostream>

using namespace std;

class PerceptronDTO
{
	public:
		vector<double> weights;
    	double bias;
		PerceptronDTO();
		virtual ~PerceptronDTO();
		vector<double> GetWeights() const;
		void SetWeights(const vector<double>& weightsInput);
		double GetBias() const;
		void SetBias(const double& biasInput);
};

#endif // PERCEPTRONDTO_H_