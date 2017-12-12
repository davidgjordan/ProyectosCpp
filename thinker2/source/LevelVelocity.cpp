#include <LevelVelocity.h>

unsigned int  LevelVelocity::SetSpeedLevel(int value = 2)
{
    unsigned int speedLevel;
    if(value == Velocity::fast) speedLevel = FAST;
    if(value == Velocity::medium) speedLevel = MEDIUM;
    if(value == Velocity::slow) speedLevel = SLOW;

    return speedLevel;
}
