#pragma once
#include "Object.h"
class item : public object
{
public:
    double dash = 0;
    static double slow;
    static short time_slow;
    static int start_slow;
    int space = 100;
    int val = 0;

    item();
    static void SlowAllItem(short ms);
    std::string type;
    double speed_item;
    void tele();
    void respawn();
};