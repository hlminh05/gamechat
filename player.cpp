#include"player.h"
void player::Gravity(){
	if (JumpState())
	{
		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		jumpHeight = jumpHeight + gravity;
		Ypos = Ypos + gravity + accelerator1 + accelerator2 + jumpHeight;
		setDest(90,Ypos,34,24);
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -6;
		}
	}
	else
	{

		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		Ypos = Ypos + gravity + accelerator1 + accelerator2;
		setDest(90,Ypos,34,24);
	}
	
}
int player::getYpos()
{
	return Ypos;
}

bool player::JumpState(){
    return inJump;
}
void player::Render(SDL_Renderer* ren)
{
	SDL_Rect src = getSrc();
	SDL_Rect dest = getDest();
	SDL_RenderCopy(ren, getTexture(), &src, &dest);
}
