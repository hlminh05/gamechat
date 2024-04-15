#pragma once
#include "button.h"
#include "gameloop.h"

class Menu
{
public:
    int eventDelay = -2000;
    std::vector<Button *> BUTTON;
    bool isRunning = false;
    void addButton(std::string Command, const char *imagePath);
    void SetPos(int PosX, int PosY);
    std::string update();
    void render();
    void close();
};