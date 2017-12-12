#include <Newbie.h>
#include <Persistence.h>
#include <RgbTool.h>
#include <IDataSource.h>

#include <json.hpp>
#include "gtest/gtest.h"

#include <SourceRGB.h>

using Json = nlohmann::json;
using namespace std;

class NeuralNetworkRGBTest : public ::testing::Test 
{
    
};

TEST_F(NeuralNetworkRGBTest, RGBtoDatesNeuralNetworkInput)
{
	std::map<string,double> position;
    
	RgbTool* tool = new RgbTool("RGB");
    ifstream render_txt ("render.txt");

	string stringRender ;
    string matrixGenerated;

    string object = "P1234";

    float PacmanPositionXExpected = 11.000000;
    float PacmanPositionYExpected = 10.000000;

    float Ghost1PositionXExpected = 11.000000;
    float Ghost1PositionYExpected = 8.000000;

    float Ghost2PositionXExpected = 11.000000;
    float Ghost2PositionYExpected = 5.000000;

    float Ghost3PositionXExpected = 0.000000;
    float Ghost3PositionYExpected = 0.000000;

    float Ghost4PositionXExpected = 0.000000;
    float Ghost4PositionYExpected = 0.000000;

	getline(render_txt,stringRender);
	render_txt.close();

	tool->SetRenderRgb(stringRender);

	tool->CharRepresent(tool->GetRenderRgb());

	position = tool->GetObjectAllPosition(object);

    EXPECT_FLOAT_EQ (PacmanPositionXExpected, position["PX"]);
    EXPECT_FLOAT_EQ (PacmanPositionYExpected, position["PY"]);

    EXPECT_FLOAT_EQ (Ghost1PositionXExpected, position["1X"]);
    EXPECT_FLOAT_EQ (Ghost1PositionYExpected, position["1Y"]);

    EXPECT_FLOAT_EQ (Ghost2PositionXExpected, position["2X"]);
    EXPECT_FLOAT_EQ (Ghost2PositionYExpected, position["2Y"]);

    EXPECT_FLOAT_EQ (Ghost3PositionXExpected, position["3X"]);
    EXPECT_FLOAT_EQ (Ghost3PositionYExpected, position["3Y"]);

    EXPECT_FLOAT_EQ (Ghost4PositionXExpected, position["4X"]);
    EXPECT_FLOAT_EQ (Ghost4PositionYExpected, position["4Y"]);
	
	delete tool;
}



TEST_F(NeuralNetworkRGBTest, RGBtoInputsOutputsNeuralNetwork)
{
    Newbie* newbie = new Newbie();

    newbie->Install();

    string trainer = "Hideky";
    string path = "./partidas/";
    string server = "10.28.132.49";
    string trainerMethod = "rgb";

    newbie->AssignTrainer(trainer);
    newbie->AssignDirectory(path);
    newbie->AssignServer(server);

    newbie->SetDataSource(trainerMethod, "MsPacman","A","./Configuration/NNTopology.json","./Configuration/NNWeights.json", false);

    SourceRGB* dataSource = new SourceRGB();

    path += "MsPacman/";
    
    dataSource->SetDataPath(path);
    dataSource->ReadAllData();
    dataSource->ProcessAllData();
    vector<vector<double>> inputs = dataSource->GetNeuralNetworkInputs();
    vector<vector<double>> outputs = dataSource->GetNeuralNetworkOutputs();
    
    int inputsNodesExpected = 10;
    float inputsExpected [] = {11.000000, 10.000000, 0.000000, 0.000000, 11.000000, 5.000000, 0.000000, 0.000000, 11.000000, 8.000000};
    float outputsExcepted [] = {0.000000, 0.000000, 1.000000, 0.000000, 0.000000};


    int pos = 0;

    for (int i = 0; i < 1; i++)
    {
        for (float x : inputs[i])
        {
            EXPECT_FLOAT_EQ(inputsExpected[pos], x);
            pos++;
        }
    }

    pos = 0;

    for (int i = 0; i < 1; i++)
    {
        for (float x : outputs[i])
        {
            EXPECT_FLOAT_EQ(outputsExcepted[pos], x);
            pos++;
            
        }
    }

    EXPECT_EQ(inputsNodesExpected,inputs[0].size());

    remove(JSONFILE);
}
