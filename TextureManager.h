#pragma once
#include "gameloop.h"

class TextureManager
{
public:
    static SDL_Texture *LoadImage(const char *file, SDL_Rect &src);
    static TTF_Font *font;
    static SDL_Color color;
    static SDL_Texture *LoadText(const char *file, SDL_Rect &src);
};
