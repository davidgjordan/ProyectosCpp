#include <Newbie.h>
#include <Persistence.h>
#include <Defines.h>
#include "gtest/gtest.h"
#include <json.hpp>

class InstanceNewbieTest : public ::testing::Test 
{
    protected:
    virtual void SetUp() 
    {

    }
    virtual void TearDown() 
    {

    }
};

TEST_F(InstanceNewbieTest,isIstalledNewbie)
{
    Newbie* newbie = new Newbie();
    newbie->Install();
    bool isIstalled = newbie->IsInstalled();
    EXPECT_TRUE(isIstalled);
    remove(JSONFILE);
    delete newbie;
}