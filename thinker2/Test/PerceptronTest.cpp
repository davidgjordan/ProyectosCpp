#include <TransitionHiperbolicTangent.h>
#include <TransitionByStep.h>
#include <TransitionSigmoid.h>
#include <TransitionSoftMax.h>
#include <Perceptron.h>
#include "gtest/gtest.h"
#include <cmath>
#include <random>
#include <iostream>
#include <cmath>
#include <random>
#include <iostream>

class PerceptronTest : public ::testing::Test
{
    protected:
        virtual void SetUp()
        {

        }

        virtual void TearDown()
        {

        }
};

double Round_places(double value, int to)
{
    double places = pow(10.0, to);
    return round(value * places) / places;
}

default_random_engine _generator1;
uniform_real_distribution<double> _distribution1{-1,1};

TEST_F(PerceptronTest,PerceptronWithBySetp )
{
    Perceptron* p = new Perceptron(2);
    vector<double> inputs = {0.1,0.1};

    EXPECT_EQ(p->Evaluate(inputs),1)<< "Se esperaba 1 de respuesta";
}

TEST_F(PerceptronTest, PerceptronWithSigmoid)
{
    Transition* transition = new TransitionSigmoid();
    int numberInputs = 2;
    Perceptron* perceptron = new Perceptron(numberInputs,transition,_distribution1,_generator1);
    vector<double> inputs = {0.1,0.1};
    EXPECT_EQ(Round_places(perceptron->Evaluate(inputs),4),0.3443)<< "Se esperaba 0.3443 de respuesta";
}

TEST_F(PerceptronTest, PerceptronTestWithTangentHiperbolic)
{
    Transition* transition = new TransitionHiperbolicTangent();
    int numberInputs = 2;
    Perceptron* perceptron = new Perceptron(numberInputs,transition,_distribution1,_generator1);
    vector<double> inputs = {0.1,0.1};
    EXPECT_EQ(Round_places(perceptron->Evaluate(inputs),4),0.1602)<< "Se esperaba 0.1602 de respuesta";
}