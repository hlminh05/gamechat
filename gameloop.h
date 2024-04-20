#pragma once
#include "Header.cpp"
#include "TextureManager.h"
#include "player.h"
#include "pipe.h"
#include "item.h"
#include "bkg.h"
#include <vector>
class Gameloop
{
private:
public:
    static int FPS;
    static int timer;
    static int HEIGHT;
    static int WIDTH;
    static SDL_Window *window;
    static SDL_Renderer *renderer;
    static bool GameState;
    static SDL_Event event;
    bool GetGameState();
    Gameloop();

    static void CreateWindow();

    static std::vector<bkg *> BKG;
    static std::vector<item *> ITEM;
    static std::vector<player *> PLAYER;
    static std::vector<pipe *> PIPE;

    bool inSpecial = false;
    const int timeSpecial = 6000;
    short start_Special = -5000;
    static int score;
    int HightScore;

    void Initialize();
    void addItem(bool t = true);
    void clearItem();
    void Event();
    void Update();
    void Render();
    void Close();
    static void initBKG();

    void Clear();
};