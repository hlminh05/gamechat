#include "button.h"

void Button::update()
{

    int x, y;
    if (Gameloop::event.type == SDL_MOUSEBUTTONDOWN)
    {
        SDL_Rect tmp = {Gameloop::event.button.x, Gameloop::event.button.y, 1, 1};
        if (Collision(tmp))
        {
            isChosed = true;
        }
    }
}