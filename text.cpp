// #include "Text.h"
// #include "TextureManager.h"
// #include <iostream>
// void Text::SetText(const char *txt)
// {
//     if (Tex != nullptr)
//         SDL_DestroyTexture(Tex);
//     Tex = TextureManager::LoadText(txt, src);
//     dest = src;
// }

// void Text::DrawText()
// {
//     TextureManager::DrawImage(Tex, dest);
// }

// void Text::SetPos(int x, int y)
// {
//     dest.x = x;
//     dest.y = y;
// }

// void Text::SetWidth(int w)
// {
//     dest.w = w;
// }

// void Text::SetHeight(int h)
// {
//     dest.h = h;
// }