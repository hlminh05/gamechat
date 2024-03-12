#pragma once
#include "Header.cpp"
#include "TextureManager.h"
class Gameloop{
    private:
        // int HEIGHT = 512;
        // int WIDTH = 288;
        int HEIGHT = 512;
        int WIDTH = 450;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool GameState;
        SDL_Event event;
        SDL_Texture* player;
        SDL_Texture* background;
        SDL_Texture* base;
        SDL_Rect src, dest;
        SDL_Rect point, draw;
    public:
        bool GetGameState();
        Gameloop();
        void Intialize();
        void Event();
        void Render();
        void Clear();
        void Update();
};