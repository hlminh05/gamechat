#include "gameloop.h"

Gameloop *g = new Gameloop();
const int FPS = Gameloop::FPS;
const int frameDelay = 1000 / FPS;

Uint32 frameStart;
int frameTime;
int main(int argc, char *args[])
{
    Gameloop::CreateWindow();

    g->Initialize();
    while (g->GetGameState())
    {

        frameStart = SDL_GetTicks();
        Gameloop::timer++;
        g->Event();
        g->Update();
        g->Render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < frameDelay)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    g->Clear();
    return 0;
}
