#include <Newbie.h>
#include <Persistence.h>
#include <RgbTool.h>
#include <SourceRAM.h>

#include <json.hpp>
#include "gtest/gtest.h"

using Json = nlohmann::json;
using namespace std;

class NeuralNetworkRAMTest : public ::testing::Test 
{
    
};

TEST_F(NeuralNetworkRAMTest, RAMtoDatesNeuralNetworkInput)
{
	SourceRAM* dataSource = new SourceRAM();
    vector<string> folders;
    vector<vector<double>> bytes;
    vector<vector<double>> _keys;
    int pos = 0;

    float bytesExcepted [] = { 0.000000, 112.000000, 114.000000, 115.000000, 48.000000, 3.000000,
        88.000000, 88.000000, 88.000000, 88.000000, 88.000000, 0.000000, 80.000000,
        80.000000, 80.000000, 50.000000, 98.000000, 0.000000, 0.000000,
        3.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 1.000000,
        6.000000, 6.000000, 198.000000, 4.000000, 66.000000, 0.000000,
        45.000000, 1.000000, 0.000000, 198.000000, 198.000000, 0.000000,
        0.000000, 1.000000, 0.000000, 0.000000, 52.000000, 0.000000, 0.000000,
        120.000000, 0.000000, 100.000000, 130.000000, 0.000000, 0.000000,
        112.000000, 1.000000, 222.000000, 0.000000, 0.000000, 3.000000,
        0.000000, 6.000000, 80.000000, 255.000000, 255.000000, 0.000000, 255.000000,
        255.000000, 80.000000, 255.000000, 255.000000, 80.000000,
        255.000000, 255.000000, 80.000000, 255.000000, 255.000000, 80.000000,
        191.000000, 191.000000, 80.000000, 191.000000, 191.000000, 80.000000,
        191.000000, 191.000000, 80.000000, 255.000000, 255.000000, 80.000000,
        255.000000, 255.000000, 80.000000, 255.000000, 255.000000, 80.000000,
        255.000000, 255.000000, 0.000000, 255.000000, 255.000000, 80.000000,
        255.000000, 255.000000, 20.000000, 223.000000, 43.000000, 217.000000,
        123.000000, 217.000000, 123.000000, 217.000000, 123.000000,
        217.000000, 123.000000, 217.000000, 123.000000, 217.000000, 221.000000,
        0.000000, 63.000000, 0.000000, 0.000000, 0.000000, 0.000000,
        0.000000, 2.000000, 66.000000, 240.000000, 146.000000, 215.000000};

    float _keysExcepted [] = {0.000000, 0.000000, 1.000000, 0.000000, 0.000000};


    string path = "./partidas/MsPacman/";

    folders = dataSource->GetFolderNames(path);

    for (int i = 0; i < folders.size(); i++)
    {
        Json jsonData;
        ifstream dataStream {path + folders[i] + '/' + MATCH_JSON};
        dataStream >> jsonData;

        Json steps = jsonData[GAME_STEPS];
        Json keys = jsonData[GAME_KEYS];
        
        for (Json::iterator it = steps.begin(); it != steps.end(); ++it) 
        {
            bytes.push_back(it.value());
        }

        for (Json::iterator it = keys.begin(); it != keys.end(); ++it) 
        {
            _keys.push_back(it.value());
        }
    }

    for (int i = 0; i < 1; i++)
    {
        for (float x : bytes[i])
        {
            EXPECT_FLOAT_EQ(bytesExcepted[pos], x);
            pos++;

        }
    }

    pos = 0;

    for (int i = 0; i < 1; i++)
    {
        for (float x : _keys[i])
        {
            EXPECT_FLOAT_EQ(_keysExcepted[pos], x);
            pos++;
        }
    }
}

TEST_F(NeuralNetworkRAMTest, RAMtoInputsOutputsNeuralNetwork)
{
    Newbie* newbie = new Newbie();

    newbie->Install();

    string trainer = "Hideky";
    string path = "./partidas/";
    string server = "10.28.132.49";
    string trainerMethod = "ram";

    newbie->AssignTrainer(trainer);
    newbie->AssignDirectory(path);
    newbie->AssignServer(server);
    newbie->SetDataSource(trainerMethod, "MsPacman","A" ,"./Configuration/NNTopology.json","./Configuration/NNWeights.json", false);

    SourceRAM* dataSource = new SourceRAM();

    path += "MsPacman/";

    dataSource->SetDataPath(path);
    dataSource->ReadAllData();
    dataSource->ProcessAllData();
    vector<vector<double>> inputs = dataSource->GetNeuralNetworkInputs();
    vector<vector<double>> outputs = dataSource->GetNeuralNetworkOutputs();
    
    int inputsNodesExpected = 10;
    float inputsExpected [] = {88.000000, 98.000000, 88.000000, 50.000000, 88.000000, 80.000000, 88.000000, 80.000000, 88.000000, 80.000000};
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
