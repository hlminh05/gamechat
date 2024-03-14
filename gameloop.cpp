#include"gameloop.h"


// bool inJump = false;
// double jumpHeight = -6;
// double gravity = 0.2; // gia toc
// double acc = 0;
// int ypos = 100;
// int lastJump = 0;
// int jumpTimer;
// SDL_Rect Gameloop::dest={0,0,0,0};

// void G()
// {
//     if(inJump)
//     {
//         acc+=0.035*2;
//         jumpHeight += gravity;
//         ypos += gravity + acc + jumpHeight;
//         if(ypos>400)ypos=400;
//         Gameloop::SetDest({90,ypos,34,24});
//         if(jumpHeight > 0){
//             jumpHeight = -6;
//             inJump = false;
//         }
        
//     }
//     else {
//         acc +=0.035*2;
//         ypos += gravity + acc;
//         if(ypos>400)ypos=400;
//         Gameloop::SetDest({90,ypos,34,24});
//     }
// }
// void jump()
// {
//     if (jumpTimer - lastJump > 30)
// 	{
// 		acc = 0;
// 		inJump = true;
// 		lastJump = jumpTimer;
// 	}
    
// }

// void Gameloop::SetDest(SDL_Rect ndest){
//     dest = ndest;
// }
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
            chim->CreateTexture("img/yellowbird-upflap.png",renderer);
            chim->setSrc(0,0,34,24);
            // player1 = TextureManager::Texture("img/yellowbird-upflap.png", renderer);
            // player2 = TextureManager::Texture("img/yellowbird-midflap.png", renderer);
            // player3 = TextureManager::Texture("img/yellowbird-downflap.png", renderer);
            background = TextureManager::Texture("img/background-day.png", renderer);
            base = TextureManager::Texture("img/base.png", renderer);
        }
        else std::cout << "not created!" << std::endl;
    }
    else{
        std::cout << "window not created!"<< std::endl;
    }


    point.w = 336;
    point.h = 112;
    point.x = point.y = 0;

    draw.h = 112;
    draw.w = WIDTH;
    draw.x = 0;
    draw.y = HEIGHT - 112;
}

void Gameloop::Event(){
    // jumpTimer = SDL_GetTicks();
     SDL_PollEvent(&event);
    if(event.type == SDL_QUIT){
        GameState = false;
    }
    if(event.type == SDL_MOUSEMOTION){
        std::cout <<event.motion.x << " " <<event.motion.y<< std::endl;
    }
    if(event.type == SDL_MOUSEBUTTONDOWN){
        // if (!inJump)
		// 	{
		// 		jump();
		// 	}
        std::cout << "press start!" << std::endl;
        
    }
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_SPACE)
        {
            
            // if (!inJump)
			// {
			// 	jump();
			// }

        std::cout << "press start!" << std::endl;
        }
    }
}
void Gameloop::Update(){
    chim->Gravity();
}

void Gameloop::Render(){
    SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL,NULL);
        SDL_RenderCopy(renderer,base, &point,&draw);
        chim->Render(renderer);
        SDL_RenderPresent(renderer);
    
}

void Gameloop::Clear(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}