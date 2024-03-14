#include"gameloop.h"

Gameloop::Gameloop(){
    window = NULL;
    renderer = NULL;
    GameState = false;

}
//272
bool Gameloop::GetGameState(){
    return GameState;
}
 void Gameloop::Initialize(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy nigga",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,0);
    if(window){
        renderer = SDL_CreateRenderer(window,-1 ,0);
        if(renderer){
            std::cout << "created!" << std::endl;
            GameState = true;
            chim=new player;// tao chim kieu player
            base = new player;
            base->text = TextureManager::Texture("img/base.png", renderer);
            for(int i = 0;i < 3;i++){
                chim-> Texts[i] = TextureManager::Texture(("img/" + std::to_string(i) + ".png").c_str(),renderer);
            }
            
            chim->setSrc(0,0,34,24);
            base->setSrc(0,0,336,112);
            // base->setDest(0,HEIGHT-112,900,112);
            bkg = new player;
            bkg->text1 = TextureManager::Texture("img/bg.png", renderer);
            //background = TextureManager::Texture("img/bg.png", renderer);
            //base = TextureManager::Texture("img/base.png", renderer);
            bkg->setSrc(0,0,450,512);  
            bkg->setDest(0,0,450,512);       

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
    if(event.type == SDL_MOUSEBUTTONDOWN){
                chim->Jump();
        std::cout << "press start!" << std::endl;
        
    }
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_SPACE)
        {
            
                chim->Jump();
                
        }
        
        std::cout << "press start!" << std::endl;
    }
}
void Gameloop::Update(){
     chim->Gravity();
     base->tele();
     bkg->tele1();
}

void Gameloop::Render(){
    SDL_RenderClear(renderer);
         //SDL_RenderCopy(renderer, background, NULL,NULL);
        //SDL_RenderCopy(renderer,base, &point,&draw);
        bkg->Render1(renderer);
        base->Render(renderer);
        chim-> Render(renderer, (int)chim->fly);
        chim->fly+= 0.05;// ép kiểu nguyên để ảnh chuyển lâu hơn
        if (chim->fly>=3) chim->fly = 0;
        SDL_RenderPresent(renderer);
    
}

void Gameloop::Clear(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}