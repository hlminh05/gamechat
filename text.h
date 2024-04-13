#pragma once
#include "Header.cpp"

class Text
{
public:
    SDL_Texture *Tex = nullptr;
    SDL_Rect src, dest;

    void SetText(const char *txt);
    void DrawText();
    void SetPos(int x, int y);
    void SetWidth(int w);
    void SetHeight(int h);
};