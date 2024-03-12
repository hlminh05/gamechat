#pragma once
#include "gameloop.h"
class TextureManager {
    public:
        static SDL_Texture* Texture(const char* file, SDL_Renderer* nen);  
        // static SDL_Texture* Texture(const char* file, SDL_Renderer* bkg, SDL_Rect &src);
};
