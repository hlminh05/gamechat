#pragma once
#include"Header.cpp"
#include"Object.h"
class player : public object{
    private:
        double gravity = 0.2;
        int Ypos = 0;
        double accelerator1 = 0;
        double accelerator2 = 0;
        bool inJump = false;
        double jumpHeight = -6;
        double jumpTimer;
        double lastJump = 0;
        SDL_Texture* Tex1;
        SDL_Texture* Tex2;
    public:
        void Gravity();
        bool JumpState();
        int getYpos();
        void Render(SDL_Renderer* ren);


};
