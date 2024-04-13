#pragma once
#include "Object.h"
class bkg : public object
{

public:
    bkg();
    double speed = 1;
    void slip();
};