#ifndef ECH_H_
#define ECH_H_

#include "BaseObject.h"

#define JUMP 1
#define FALL 2
#define RUSH 3
#define RUN	0

class Character
{
public:
    static const int NHAY_SPEED = 6;
    static const int ROI_SPEED = 6;

    Character();

    bool TrenMatDat();
    void Event(SDL_Event &e, Mix_Chunk *g_Jump);
    void DiChuyen();
    void Render(SDL_Rect *currentClip, SDL_Renderer *g_Renderer, BaseObject g_CharacterTexture);
    int GetPosX();
    int GetPosY();

private:
    int posX, posY, status;
};
#endif // ECH_H_INCLUDED
