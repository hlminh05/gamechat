#pragma once
#include "Header.cpp"
#include "TextureManager.h"
#include"player.h"
class Gameloop{
    private:
        int HEIGHT = 512;
        int WIDTH = 450;
        // int HEIGHT = 512;
        // int WIDTH = 450;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool GameState;
        SDL_Event event;
        player *chim;
        SDL_Texture* player1;
        SDL_Texture* player2;
        SDL_Texture* player3;
        SDL_Texture* background;
        SDL_Texture* base;
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