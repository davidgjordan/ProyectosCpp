#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <cmath>
#include <random>
#include <PerceptronDTO.h>
#include <TransitionByStep.h>
using namespace std;

class Transition;

class Perceptron : public PerceptronDTO
{
public:
  Transition* transition;
  double output;
  double gradient;
    public:
        Perceptron(int numberInputs);
        Perceptron(int numberInputs, Transition* function, uniform_real_distribution<double>& distribution, default_random_engine& generator);
        double Evaluate(vector<double>& inputs) const;
        double Summatory(vector<double>& inputs) const;
        void Train(vector< vector<double> >& trainDataInput, vector<double>& expectedoutput,double learning_rate,int loop_learn);
        ~Perceptron();
};
#endif // PERCEPTRON_H

