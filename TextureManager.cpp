#include"TextureManager.h"

SDL_Texture* TextureManager::Texture(const char* file, SDL_Renderer* bkg){
    SDL_Surface* surface;
    surface = IMG_Load(file);
    SDL_Texture* tex;
    tex = SDL_CreateTextureFromSurface(bkg, surface);
    return tex;
}

// SDL_Texture* TextureManager::Texture(const char* file, SDL_Renderer* bkg, SDL_Rect &src){
//     SDL_Surface* surface;
//     surface = IMG_Load(file);
//     src.w = surface->w ;
//     src.h = surface->h ;
//     SDL_Texture* tex;
//     tex = SDL_CreateTextureFromSurface(bkg, surface);
//     return tex;
// }