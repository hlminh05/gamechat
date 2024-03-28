#include"pipe.h"
void pipe::init(const char* path, SDL_Renderer* ren,int x){
    CreateTexture(path, ren);
    SDL_Texture* tex = getTexture();
    setSrc(0,0,64,64);
    xPos = x;
    setDest(xPos,300,52,100);
}
void pipe:: init(const char* path,SDL_Renderer*nen){
    CreateTexture(path, nen);
    SDL_Texture* tex = getTexture();
    srand(time(0));
    setSrc(0,0,612,612);
    xPos = 642;
    yPos = 0;
    setDest(xPos,yPos,70,80);

}
void pipe:: updatefly(){
    xPos-=9;
    setDest(xPos,yPos,70,80);
    if(xPos < -70){
        xPos = 642;
        yPos = rand() % 330;
    }
}

void pipe:: update(int sp)
{
    xPos-= sp;
    setDest(xPos,300,52,100);
    if(xPos < -52)
    {
        xPos = 642;
    }
}

void pipe:: render(SDL_Renderer*ren)
{
    SDL_Rect src = getSrc();
	SDL_Rect dest = getDest();
   
    
	SDL_RenderCopy(ren, getTexture(), &src, &dest);
    

}