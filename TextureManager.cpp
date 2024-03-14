#include"TextureManager.h"

SDL_Texture* TextureManager::Texture(const char* file, SDL_Renderer* bkg){
    SDL_Surface* surface;
    surface = IMG_Load(file);
    SDL_Texture* tex;
    tex = SDL_CreateTextureFromSurface(bkg, surface);
    return tex;
}
