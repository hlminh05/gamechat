#include "player.h"
#include "gameloop.h"
player::player()
{
    Gameloop::PLAYER.push_back(this);
}

void player::init(short MaxSkin, short ms)
{
    maxSkin = MaxSkin;
    msPF = ms;
    src.w /= MaxSkin;
    SetRect(src.w, src.h);
}

void player::update()
{
    if ((Gameloop::timer - LastChange) * (1000 / Gameloop::FPS) >= msPF * item::slow)
    {
        LastChange = Gameloop::timer;
        skin++;
        skin %= maxSkin;
        src.x = skin * src.w;
    }
    jumpheight += gra;

    y += jumpheight;
    if (y < 0)
        y = 0;
    if (y > (400 - dest.h))
        y = 400 - dest.h;
}

void player::jump()
{
    jumpheight = -3;
}
