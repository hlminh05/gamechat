#pragma once
#include "Header.cpp"
class object
{
private:
    SDL_Texture *image = nullptr;

public:
    SDL_Rect dest;
    SDL_Rect src;
    double x = 0, y = 0;
    double width, height;
    double scale = 1;

    void FixData();

    void SetImage(const char *address);
    void Draw();
    void SetPos(double x, double y);
    void SetScale(double x);
    void SetRect(int w, int h);

    SDL_Rect getDest();

    bool Collision(SDL_Rect A);
};