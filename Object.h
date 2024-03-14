#pragma once
#include"Header.cpp"
class object{
    private:
        SDL_Rect src1, dest1;
        SDL_Texture* Tex;
    public:
         object();
         void CreateTexture(const char* address,SDL_Renderer* ren);
        // void CreateTexture(const char* adress, SDL_Renderer* nen,SDL_Texture* Tex);
        // void virtual Render() = 0;
        SDL_Texture* getTexture();
        SDL_Rect getSrc();
        SDL_Rect getDest();
        void setSrc(int x, int y, int w, int h);
        void setDest(int x, int y, int w, int h);
        
};