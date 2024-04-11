#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

#include "Func.h"


using namespace std;

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();

    bool LoadFromRenderedTexture ( string TextureText, TTF_Font* g_Font, SDL_Color textColor, SDL_Renderer* g_Renderer); //TAO KET CAU TU TEP VAN BAN
    bool LoadFromFile(string path, SDL_Renderer* g_Renderer);    //TAO KET CAU TU TEP HINH ANH
    void Render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = nullptr);   //VE KET CAU TAI CAC VI TRI TOA DO (X,Y)
    void Free();

    int GetWidth();
    int GetHeight();

private:
    SDL_Texture* m_Texture;
    int m_Width;
    int m_Height;
};

#endif // BASEOBJECT_H_
