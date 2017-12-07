#ifndef LEVELVELOCITY_H_
#define LEVELVELOCITY_H_

#include <Defines.h>
#include <stdio.h>
#include <iostream>


class LevelVelocity
{

    enum Velocity
    {
        fast = 1,
        medium,
        slow
    };

    public:
    unsigned int SetSpeedLevel(int);
};

#endif//LEVELVELOCITY_H_