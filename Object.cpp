#include "Object.h"
#include "TextureManager.h"

void object::FixData()
{
	dest.x = int(x);
	dest.y = int(y);
	dest.h = height * scale;
	dest.w = width * scale;
}

void object::SetRect(int w, int h)
{
	width = w;
	height = h;
}

void object::SetImage(const char *address)
{
	image = TextureManager::LoadImage(address, src);
	dest = src;
	width = src.w;
	height = src.h;
}

void object::Draw()
{
	FixData();
	SDL_RenderCopy(Gameloop::renderer, image, &src, &dest);
}

void object::SetPos(double x, double y)
{
	this->x = x;
	this->y = y;
}
void object::SetScale(double x)
{
	scale = x;
	FixData();
}

SDL_Rect object::getDest()
{
	return dest;
}

bool object::Collision(SDL_Rect A)
{
	SDL_Rect B = dest;
	return !(
		A.x > B.x + B.w ||
		A.y > B.y + B.h ||
		B.x > A.x + A.w ||
		B.y > A.y + A.h);
}