#include "bkg.h"
#include "gameloop.h"

bkg::bkg()
{
    Gameloop::BKG.push_back(this);
}
void bkg::slip()
{

    x -= speed / item::slow;
    if (x + getDest().w / 2 < 0)
        x = 0;
}