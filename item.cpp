#include "item.h"
#include "gameloop.h"

double item::slow = 1;
short item::time_slow = 0;
int item::start_slow = 0;

item::item()
{
    Gameloop::ITEM.push_back(this);
}
void item::SlowAllItem(short ms)
{
    time_slow = ms;
    start_slow = Gameloop::timer;
    slow = 5;
}
void item::tele()
{
    if (slow > 1 && (Gameloop::timer - start_slow) * 1000 / Gameloop::FPS > time_slow)
    {
        time_slow = 0;
        slow = 1;
    }
    x -= speed_item / slow;
    if (Gameloop::score >= 90 && type == "bom")
    {
        if (sin(1.0 * 2 * 3.14 * (Gameloop::timer % 100) / 100) >= 0) // hard
            y += speed_item / item::slow;
        else
            y -= speed_item / item::slow;
    }

    if (y < 0)
        y = 0;
    if (y > 400)
        y = 400;
    if (x < -100)
    {
        respawn();
    }
}

void item::respawn()
{
    if (x > 0)
        Gameloop::score += val;
    y = rand() % (400 - dest.h);
    x = Gameloop::WIDTH + space + rand() % space;
}