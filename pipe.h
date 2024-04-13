#pragma once
#include "Object.h"
class pipe : public object
{
public:
    pipe();
    double speed_pipe;
    void move();
    double space_pipe = 100;
};