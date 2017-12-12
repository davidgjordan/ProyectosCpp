#include <Newbie.h>
#include <Persistence.h>
#include <Defines.h>
#include <json.hpp>
#include "gtest/gtest.h"

using Json = nlohmann::json;
using namespace std;
class NewbieTest : public ::testing::Test 
{


 protected:

  virtual void SetUp()
  {

  }

  virtual void TearDown() 
  {

  }

};

TEST_F(NewbieTest,AssignTrainer)
{
    Newbie* newbie = new Newbie();
    newbie->Install();
   
    Json manager;
    ifstream ipf {JSONFILE};
    ipf >> manager;
    string  nameTrainer = manager[TRAINER];
    string expectedName = "trainer"; 
    EXPECT_EQ(nameTrainer,expectedName);

    string name = "marisol";
    newbie->AssignTrainer(name);
    Json manager1;
    ifstream ipf1 {JSONFILE};
    ipf1 >> manager1;
    string  nameTrainer1 = manager1[TRAINER];
    EXPECT_EQ(nameTrainer1,name);

    remove(JSONFILE);
    delete newbie;
}

TEST_F(NewbieTest,AssignDirectory)
{
    Newbie* newbie = new Newbie();
    newbie->Install();
    string expectedPath = "./";

    Json manager;
    ifstream ipf {JSONFILE};
    ipf >> manager;
    string path = manager[DIRECTORY];
    EXPECT_EQ(path,expectedPath);

    string newPath = "/home/ubuntu/";
    newbie->AssignTrainer("noelia");
    newbie->AssignDirectory(newPath);
    Json manager1;
    ifstream ipf1 {JSONFILE};
    ipf1 >> manager1;
    string pathActually = manager1[DIRECTORY];
    EXPECT_EQ(pathActually,newPath);
    
    remove (JSONFILE);
    delete newbie;
}
TEST_F(NewbieTest,AssignServer)
{
    Newbie* newbie = new Newbie();
    newbie->Install();
    string expectedServer= "127.0.0.1";

    Json manager;
    ifstream ipf {JSONFILE};
    ipf >> manager;
    string server = manager[SERVER];
    EXPECT_EQ(expectedServer,server);

    string newServer = "10.28.132.47";
    newbie->AssignServer(newServer);
    Json manager1;
    ifstream ipf1 {JSONFILE};
    ipf1 >> manager1;
    string serverActually = manager1[SERVER];
    EXPECT_EQ(newServer,serverActually);
    
    remove (JSONFILE);
    delete newbie;
}



