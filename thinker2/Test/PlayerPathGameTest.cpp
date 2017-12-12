#include <Newbie.h>
#include <Persistence.h>
#include <Defines.h>
#include <json.hpp>
#include "gtest/gtest.h"
#include <Player.h>
#include <iostream>

using Json = nlohmann::json;
using namespace std;

class PlayerTest : public ::testing::Test
{
    
};

    void DeleteFolderNames(string path)
    {
        DIR* direction;
        dirent* dirent;
        string files;
        direction = opendir(path.c_str());

        while (dirent = readdir(direction))
        {
            string name = dirent->d_name;
            if((strcmp(name.c_str(),".")!=0) && (strcmp(name.c_str(),"..")!=0))
            {
                files = path + name;
                remove(files.c_str());
            }
        }

        free(direction);
        delete(dirent);
    }

TEST_F(PlayerTest,CreatePathGame)
{
    
    Newbie* newbie = new Newbie();
    Persistence* persistence = new Persistence();
    vector<string> nameFolderstoDelete;
    puts("**************************************************************");
    puts("THIS UNIT TEST NEEDS AN ACTIVE SERVER");
    puts("**************************************************************");
    
    newbie->Install();

    string gameName = "MsPacman-ram-v0";
    string directory = persistence->CreateNewGame(newbie, gameName);
    string serverIP = newbie->GetServer();
    string directoryController = "./Configuration/keyControlsA.json";

    Player* run = new Player(gameName, directory, serverIP, "B", false, directoryController);

    ifstream pathGame {directory};
    bool result = pathGame.is_open();

    remove(JSONFILE);

    string directoryToDeleteRGB = directory + "/rgb/";

    DeleteFolderNames(directoryToDeleteRGB);

    string directoryToDeleteMatch = directory + "/match.json";
    string directoryToDeleteCarpetRGB = directory + "/rgb";

    remove(directoryToDeleteMatch.c_str());
    remove(directoryToDeleteCarpetRGB.c_str());
    remove(directory.c_str());
    remove(gameName.c_str());
    
    delete run;
    delete persistence;
 
    EXPECT_TRUE(result);   
}