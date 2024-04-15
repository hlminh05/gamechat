#pragma once
#include "gameloop.h"

class Button : public object
{
public:
    bool isChosed = false;
    std::string command = "";
    void update();
};