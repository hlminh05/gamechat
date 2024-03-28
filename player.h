#pragma once
#include"Object.h"
class player : public object{
    private:
        double gravity = 0.15;
        int Ypos = 0;
        double Xpos = 0;
        double jumpHeight = 0;
    public:
        // double Xpos = 0;
        // int Ypos = 0;
        double fly = 0;
        void Gravity();
        //int getYpos();
        void Render(SDL_Renderer* ren,int x);
        void Jump();
        SDL_Texture* Texts[3];
        SDL_Texture* text;
        //SDL_Texture* text1;
        void Render(SDL_Renderer* ren);
        void tele();
        void tele1();
        void Render1(SDL_Renderer* ren);

};
