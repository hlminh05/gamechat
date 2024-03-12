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
    window = SDL_CreateWindow("Flappy nigga",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);
    if(window){
        renderer = SDL_CreateRenderer(window,-1 ,0);
        if(renderer){
            std::cout << "created!" << std::endl;
            GameState = true;
            player = TextureManager::Texture("img/yellowbird-downflap.png", renderer);
            background = TextureManager::Texture("img/background-day.png", renderer);
            base = TextureManager::Texture("img/base.png", renderer);
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
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_SPACE)
        {
        std::cout << "press start!" << std::endl;
        }
    }
}
void Gameloop::Update(){
    src.h = 24;
    src.w = 34;
    src.x = src.y = 0;

    dest.h = 24;
    dest.w = 34;
    dest.x = dest.y = 10;


    point.w = 336;
    point.h = 112;
    point.x = point.y = 0;

    draw.h = 112;
    draw.w = WIDTH;
    draw.x = 0;
    draw.y = HEIGHT - 112;
}

void Gameloop::Render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL,NULL);
    SDL_RenderCopy(renderer,base, &point,&draw);
    SDL_RenderCopy(renderer, player, &src, &dest);
    SDL_RenderPresent(renderer);
    
}

void Gameloop::Clear(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}