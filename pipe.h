#pragma once
#include"Object.h"
class pipe : public object{
    private:
    int xPos;
    int yPos;
    public:
        void init(const char* path, SDL_Renderer* ren,int x);
        void init(const char* path,SDL_Renderer*nen);
        void update(int sp);
        void render(SDL_Renderer*ren);
        void updatefly();


};