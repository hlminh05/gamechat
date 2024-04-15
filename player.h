#pragma once
#include "Object.h"
class player : public object
{
public:
    short skin = 0;
    short form = 0;
    short maxForm = 1;
    short maxSkin = 1;
    short msPF = 500;
    int LastChange = 0;
    double jumpheight = 0;
    double gra = 0.15;

    player();
    void init(short MaxSkin, short ms);
    void update();
    void gravity();
    void jump();
};
