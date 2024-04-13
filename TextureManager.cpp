#include "TextureManager.h"
#include "gameloop.h"

TTF_Font *TextureManager::font;
SDL_Color TextureManager::color;

SDL_Texture *TextureManager::LoadImage(const char *file, SDL_Rect &src)
{
    SDL_Surface *surface;
    surface = IMG_Load(file);
    src.x = src.y = 0;
    src.w = surface->w;
    src.h = surface->h;

    SDL_Texture *tex;
    tex = SDL_CreateTextureFromSurface(Gameloop::renderer, surface);
    SDL_FreeSurface(surface);
    return tex;
}

SDL_Texture *TextureManager::LoadText(const char *file, SDL_Rect &src)
{

    SDL_Surface *surface;
    surface = TTF_RenderText_Solid(font, file, color);
    src = {0, 0, surface->w, surface->h};

    SDL_Texture *tex = nullptr;
    tex = SDL_CreateTextureFromSurface(Gameloop::renderer, surface);

    SDL_FreeSurface(surface);
    return tex;
}