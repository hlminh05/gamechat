#pragma once
#include "Header.cpp"
class Gameloop{
    private:
        int HEIGHT = 512;
        int WIDTH = 288;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool GameState;
        SDL_Event event;
    public:
        bool GetGameState();
        Gameloop();
        void Intialize();
        void Event();
        void Render();
        void Clear();
};