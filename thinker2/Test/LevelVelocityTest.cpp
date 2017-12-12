#include <LevelVelocity.h>
#include "gtest/gtest.h"

class LevelVelocityTest: public ::testing::Test 
{
protected:

    virtual void SetUp()
    {

    }

    virtual void TearDown() 
    {

    }
};

TEST_F(LevelVelocityTest, PlayerVelocity)
{
    LevelVelocity velocity;
    unsigned int result;
    unsigned int speed;
    result = MEDIUM;
    speed = velocity.SetSpeedLevel(2);

    EXPECT_EQ(result,speed);
}