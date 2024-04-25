#ifndef BOTTON_H_
#define BOTTON_H_


#include "BaseObject.h"
#include "Func.h"

class Button
{
public:
    ButtonSprite currentSprite;

    Button();

    Button(int x, int y);

    void SetPosition(int x, int y);

    bool IsInside(SDL_Event *e, int size);

    void Render(SDL_Rect* currentClip, SDL_Renderer* g_Renderer, BaseObject g_ButtonTexture);

private:
    SDL_Point position;   //Cau truc diem(x,y)
};

#endif // BOTTON_H_INCLUDED
