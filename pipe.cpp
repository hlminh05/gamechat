#include "pipe.h"
#include "gameloop.h"

pipe::pipe()
{
    Gameloop::PIPE.push_back(this);
}

void pipe::move()
{

    x -= speed_pipe / item::slow;
    if (x < -dest.w)
    {
        x = Gameloop::WIDTH;
        // y = 400 - dest.h;
    }
}
