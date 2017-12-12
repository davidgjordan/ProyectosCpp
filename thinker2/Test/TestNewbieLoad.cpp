#include <Newbie.h>
#include <Persistence.h>
#include <IDataSource.h>
#include <iostream>
#include "gtest/gtest.h"

class TestNewbieLoad : public ::testing::Test 
{
protected:

    virtual void SetUp()
    {

    }

    virtual void TearDown() 
    {

    }
};

TEST_F(TestNewbieLoad,NewbiePersistence)
{
   
    Newbie* newbie = new Newbie();
    newbie->Install();

    string expectedTrainer = "Hideky";
    string expectedDirectory = "./partidas/";
    string expectedServer = "10.28.132.49";

    newbie->AssignTrainer(expectedTrainer);
    newbie->AssignDirectory(expectedDirectory);
    newbie->AssignServer(expectedServer);

    Newbie* newbieLoad = new Newbie();
    newbieLoad->Load();


    EXPECT_EQ(expectedTrainer, newbieLoad->GetTrainer());
    EXPECT_EQ(expectedDirectory, newbieLoad->GetDirectory());
    EXPECT_EQ(expectedServer, newbieLoad->GetServer());

    remove(JSONFILE);
}