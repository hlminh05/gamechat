#include"player.h"
void player::Gravity(){
		jumpHeight += gravity;
		Ypos += jumpHeight;
		if(Ypos > 376) Ypos = 376;
		if(Ypos < 0) Ypos = 0;
		setDest(90,Ypos,34,24);
	
}

void player::Render(SDL_Renderer* ren, int x)
{
	SDL_Rect src = getSrc();
	SDL_Rect dest = getDest();
	SDL_RenderCopy(ren, Texts[x], &src, &dest);
	//SDL_RenderCopyEx(ren, Texts[x] ,&src, &dest, 0, NULL, SDL_FLIP_NONE);
}
void player::Jump()
{
	jumpHeight = -3;
}
void player::Render(SDL_Renderer* ren)
{
	SDL_Rect src = getSrc();
	SDL_Rect dest = getDest();
	SDL_RenderCopy(ren, text, &src, &dest);
}
void player::tele(){
	Xpos -= 1;
	if(Xpos < -642) Xpos = 0;
	setDest(Xpos,400,642*2,112);
}
void player::tele1(){
	Xpos += 0.5;
	if(Xpos > 273) Xpos = 0;
	
	setSrc(Xpos,0,642,512);
}