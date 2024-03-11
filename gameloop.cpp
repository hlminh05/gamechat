#include"gameloop.h"

Gameloop::Gameloop(){
    window = NULL;
    renderer = NULL;
    GameState = false;

}
bool Gameloop::GetGameState(){
    return GameState;
}

 void Gameloop::Intialize(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy happy",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);
    if(window){
        renderer = SDL_CreateRenderer(window,-1 ,0);
        if(renderer){
            std::cout << "created!" << std::endl;
            GameState = true;
        }
        else std::cout << "not created!" << std::endl;
    }
    else{
        std::cout << "window not created!"<< std::endl;
    }
}

void Gameloop::Event(){
     SDL_PollEvent(&event);
    if(event.type == SDL_QUIT){
        GameState = false;
    }
    if(event.type == SDL_MOUSEMOTION){
        std::cout <<event.motion.x << " " <<event.motion.y<< std::endl;
    }
    if(event.type == SDL_MOUSEBUTTONDOWN){
        std::cout << "press start!" << std::endl;
    }
}

void Gameloop::Render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

}

void Gameloop::Clear(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}