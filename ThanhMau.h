#ifndef THANHMAU_H_
#define THANHMAU_H_


#include "BaseObject.h"

class HealthBar
{
public:
    HealthBar();

    void Render(SDL_Rect* currentClip, SDL_Renderer* g_Renderer, BaseObject g_HealthBarTexture );

    int GetPosX();
    int GetPosY();
private:
    int PosX, PosY;
    int status;
};

#endif // THANHMAU_H_
