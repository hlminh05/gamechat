#include "menu.h"

void Menu::addButton(std::string Command, const char *imagePath)
{
    BUTTON.push_back(new Button);
    BUTTON.back()->SetImage(imagePath);
    BUTTON.back()->command = Command;
}
void Menu::SetPos(int PosX, int PosY)
{
    BUTTON.back()->SetPos(PosX, PosY);
}
std::string Menu::update()
{

    SDL_PollEvent(&Gameloop::event);
    if (SDL_GetTicks() - eventDelay <= 800)
        return "none";

    if (BUTTON.size() > 0 && Gameloop::event.type == SDL_KEYUP && Gameloop::event.key.keysym.sym == SDLK_SPACE)
    {
        return BUTTON[0]->command;
    }
    std::string CM = "none";
    for (auto &b : BUTTON)
    {
        b->update();
        if (b->isChosed)
            CM = b->command;
        b->isChosed = false;
    }
    return CM;
}
void Menu::render()
{
    if (SDL_GetTicks() - eventDelay < 800)
        return;
    for (auto &b : BUTTON)
        b->Draw();
}
void Menu::close()
{
    isRunning = false;
    for (auto &b : BUTTON)
        delete b;
    BUTTON.clear();
}