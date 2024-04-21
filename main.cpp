#include "gameloop.h"
#include "menu.h"

Gameloop *g = new Gameloop();
const float FPS = Gameloop::FPS;
const float frameDelay = 1000 / FPS;
Mix_Music *music = nullptr;

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
    { // intit BKG
        Gameloop::initBKG();
    }

    int format = MIX_INIT_OGG;
    Mix_Init(format);
    Mix_OpenAudio(44100, AUDIO_S32SYS, 2, 4096);
    music = Mix_LoadMUS("sound/nhac.ogg");

    Mix_PlayMusic(music, -1);

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
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();
    return 0;
}
