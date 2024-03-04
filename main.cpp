#include <bits/stdc++.h>
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_image.h"
#include "include/SDL2/SDL_mixer.h"
#include "include/SDL2/SDL_ttf.h"
#include "include/SDL2/SDL_net.h"
#include "Screen.hpp"
#include "Render.hpp"

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Error: SDL failed to initialize - " << SDL_GetError();
        return 1;
    }

    Screen currentScreen;
    Render currentRenderer(currentScreen.window);

    bool running = true;
    SDL_Event event;

    while(running){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
        SDL_SetRenderDrawColor(currentRenderer.renderer,249,228,50, 225);
        currentRenderer.Clear();
        currentRenderer.Display();
    }

    currentScreen.CleanUp();
    currentRenderer.CleanUp();
    SDL_Quit();
    return 0;
}