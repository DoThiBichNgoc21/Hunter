#include "Ech.h"
#include "TienIch.h"

using namespace std;

Character::Character()
{
    posX = 280;
    posY = GROUND;
    status = 0;
}

bool Character::TrenMatDat()
{
    return posY == GROUND;
}

void Character::Event( SDL_Event& e, Mix_Chunk* g_Jump)
{
    if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:{
            if ( TrenMatDat() )
            {
                Mix_PlayChannel( MIX_CHANNEL, g_Jump, NOT_REPEATITIVE );
                status = JUMP;
            }
            break;
        }
        case SDLK_RIGHT:{
            Mix_PlayChannel( MIX_CHANNEL, g_Jump, NOT_REPEATITIVE );
            status = RUSH;
            break;
        }
        }
    }
}

void Character::DiChuyen()
{
    if ( status == JUMP && posY >= MAX_HEIGHT )
    {
        posY += -NHAY_SPEED;
    }
    if ( posY <= MAX_HEIGHT )
    {
        status = FALL;
    }
    if ( status == FALL && posY < GROUND )
    {
        status += ROI_SPEED;
    }
    if ( status == RUSH && posY == GROUND )           //Cần thiết vì hàm chỉ được thực hiện khi có các dòng lênh if này
    {

    }
}

void Character::Render( SDL_Rect* currentClip, SDL_Renderer *g_Renderer, BaseObject g_CharacterTexture )
{
    g_CharacterTexture.Render( posX, posY, g_Renderer, currentClip );
}

int Character::GetPosX()
{
    return posX;
}

int Character::GetPosY()
{
    return posY;
}

