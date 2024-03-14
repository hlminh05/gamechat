#include"Object.h"
#include"TextureManager.h"
object::object()
{
    Tex = NULL;
}
// void object::CreateTexture(const char* adress, SDL_Renderer* nen,SDL_Texture*Tex){
//    Tex = TextureManager::Texture(adress,nen);
//}
SDL_Rect object::getSrc()
{
	return src1;
}

SDL_Rect object::getDest()
{
	return dest1;
}


void object::setSrc(int x, int y, int w, int h)
{
	src1.x = x;
	src1.y = y;
	src1.h = h;
	src1.w = w;
}

void object::setDest(int x, int y, int w, int h)
{
	dest1.x = x;
	dest1.y = y;
	dest1.h = h;
	dest1.w = w;
}
void object::CreateTexture(const char* address,SDL_Renderer* ren)
{
	Tex = TextureManager::Texture(address, ren);
}
SDL_Texture* object:: getTexture(){
    return Tex;
}

	