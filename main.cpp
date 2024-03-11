#include "gameloop.h"

Gameloop* g = new Gameloop();

int main(int argc, char* args[]) {
    g -> Intialize();
    while(g->GetGameState()){
        g->Render();
        g->Event();
    }
    g->Clear();
    return 0;
}
