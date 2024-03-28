#include"gameloop.h"

Gameloop::Gameloop(){
    window = NULL;
    renderer = NULL;
    GameState = false;

}

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
            //base->setDest(0,HEIGHT-112,900,112);
            bkg = new player;
            bkg->text = TextureManager::Texture("img/bg.png", renderer);
            bkg->setSrc(0,0,1108,512);  
            bkg->setDest(0,0,642,510);
            Pipe = new pipe;  
            Pipe->init("img/sword.png",renderer,450); 
            Pipe1 = new pipe;  
            Pipe1->init("img/sword.png",renderer,580); 
            Pipe2 = new pipe;  
            Pipe2->init("img/sword.png",renderer,710);     
            Pipe3 = new pipe;  
            Pipe3->init("img/sword.png",renderer,840);     
            Pipe4 = new pipe;  
            Pipe4->init("img/sword.png",renderer,970);
            Pipe5 = new pipe;  
            Pipe5 ->init("img/sword.png",renderer,1100);
            rocket = new pipe;
            rocket->init("img/rocket.png",renderer);
            std::cout<<"load ddc"<<std::endl;  
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
     Pipe1->update(1);
     Pipe->update(1);
     Pipe2->update(1);
     Pipe3->update(1);
     Pipe4->update(1);
     Pipe5->update(3);
     rocket->updatefly();
}

void Gameloop::Render(){
    SDL_RenderClear(renderer);
        bkg->Render(renderer);
        base->Render(renderer);
        Pipe1->render(renderer);
        Pipe->render(renderer);
        Pipe2->render(renderer);
        Pipe3->render(renderer);
        Pipe4->render(renderer);
        Pipe5->render(renderer);
        rocket->render(renderer);
        chim-> Render(renderer, (int)chim->fly);
        chim->fly+= 0.05;// ép kiểu nguyên để ảnh chim chuyển lâu hơn
        if (chim->fly>=3) chim->fly = 0;
        SDL_RenderPresent(renderer);
    
}

void Gameloop::Clear(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}