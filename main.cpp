#include "gameloop.h"
#include "menu.h"

Gameloop *g = new Gameloop();
const float FPS = Gameloop::FPS;
const float frameDelay = 1000 / FPS;

Uint32 frameStart;
int frameTime;
int main(int argc, char *args[])
{
    Gameloop::CreateWindow();

    Menu *menu = new Menu;
    std::string Command = "none";

    { /// init Menu
        menu->addButton("start", "img/play.png");
        menu->SetPos(Gameloop::WIDTH / 2 - 20, -50 + Gameloop::HEIGHT / 2);

        menu->addButton("exit", "img/exit.png");
        menu->SetPos(Gameloop::WIDTH / 2 - 20, Gameloop::HEIGHT / 2);
        menu->isRunning = true;
    }
    {
        Gameloop::initBKG();
    }

    while (menu->isRunning) /// Menu Loop
    {
        frameStart = SDL_GetTicks();

        if (Command == "replay") /// CM replay
        {
            Command = "start";
        }
        else
            Command = menu->update();
        { // update BKG
            for (auto &bk : Gameloop::BKG)
            {
                bk->slip();
                bk->FixData();
            }
        }
        if (Command == "exit") /// CM exit
        {
            menu->close();
        }
        else if (Command == "start") /// CM start
        {
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

            { /// replay
            }
            Menu *rePlay = new Menu;
            rePlay->addButton("replay", "img/return.png");
            rePlay->SetPos(Gameloop::WIDTH / 2 - 20, -50 + Gameloop::HEIGHT / 2);

            rePlay->addButton("exit", "img/exit.png");
            rePlay->SetPos(Gameloop::WIDTH / 2 - 20, Gameloop::HEIGHT / 2);

            rePlay->eventDelay = SDL_GetTicks();
            rePlay->isRunning = true;
            while (rePlay->isRunning)
            {
                std::string Cm = rePlay->update();
                if (Cm == "replay")
                {
                    Command = "replay";
                    rePlay->close();
                }
                else if (Cm == "exit")
                {
                    rePlay->close();
                    menu->close();
                }
                rePlay->render();
                SDL_RenderPresent(Gameloop::renderer);
            }
            rePlay->close();
            g->Close();
        }

        { /// render
            SDL_RenderClear(Gameloop::renderer);
            for (auto &bk : Gameloop::BKG)
            {
                bk->Draw();
            }
            menu->render();
            SDL_RenderPresent(Gameloop::renderer);
        }
        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < frameDelay)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    menu->close();
    g->Clear();
    return 0;
}
