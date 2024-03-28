#pragma once
#include "Header.cpp"
#include "TextureManager.h"
#include"player.h"
#include"pipe.h"
class Gameloop{
    private:
        int HEIGHT = 512;
        //int WIDTH = 450;
        // int HEIGHT = 600;
         int WIDTH = 624;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool GameState;
        SDL_Event event;
        player *chim;
        player *base;
        player* bkg;
        pipe* Pipe;
        pipe* Pipe1;
        pipe* Pipe2;
        pipe* Pipe3;
        pipe* Pipe4;
        pipe* Pipe5;
        pipe* rocket;
        SDL_Texture* background;
        SDL_Rect point, draw;
    public:
    // static SDL_Rect dest;
        //static void SetDest(SDL_Rect ndest);
        bool GetGameState();
        Gameloop();
        void Initialize();
        void Event();
        void Render();
        void Clear();
        void Update();
};