#include"player.h"
void player::Gravity(){
		jumpHeight += gravity;
		Ypos += jumpHeight;
		if(Ypos > 376) Ypos = 376;
		setDest(90,Ypos,34,24);
	
}
int player::getYpos()
{
	return Ypos;
}

void player::Render(SDL_Renderer* ren, int x)
{
	SDL_Rect src = getSrc();
	SDL_Rect dest = getDest();
	//SDL_RenderCopy(ren, getTexture(), &src, &dest);
	SDL_RenderCopyEx(ren, Texts[x] ,&src, &dest, 0, NULL, SDL_FLIP_NONE);
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
	Xbase -= 2;
	if(Xbase < -450) Xbase = 0;
	setDest(Xbase,400,900,112);
}
void player::tele1(){
	Xbkg += 1;
	if(Xbkg > 273) Xbkg = 0;
	setSrc(Xbkg,0,450,512);
}
void player::Render1(SDL_Renderer* ren){
	SDL_Rect src = getSrc();
	SDL_Rect dest = getDest();
	SDL_RenderCopy(ren, text1, &src, &dest);
}