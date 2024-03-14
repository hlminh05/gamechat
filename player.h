#pragma once
#include"Header.cpp"
#include"Object.h"
class player : public object{
    private:
        double gravity = 0.15;
        int Ypos = 80;
        int Xbase = 0;
        int Xbkg = 0;
        double jumpHeight = 0;
        //SDL_Texture* text;
    public:
        double fly = 0;
        void Gravity();
        int getYpos();
        void Render(SDL_Renderer* ren,int x);
        void Jump();
        SDL_Texture* Texts[3];
        SDL_Texture* text;
        SDL_Texture* text1;
        void Render(SDL_Renderer* ren);
        void tele();
        void tele1();
        void Render1(SDL_Renderer* ren);

};
