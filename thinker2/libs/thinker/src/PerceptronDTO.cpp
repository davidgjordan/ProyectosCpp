#include <PerceptronDTO.h>

PerceptronDTO::PerceptronDTO(){}
PerceptronDTO::~PerceptronDTO(){}

vector<double> PerceptronDTO::GetWeights() const
{
    return  weights;
}

void PerceptronDTO::SetWeights(const vector<double>& weightsInput)
{
    weights = weightsInput;
}

double PerceptronDTO::GetBias() const
{
    return bias;
}

void PerceptronDTO::SetBias(const double& biasInput)
{
    bias = biasInput;
}