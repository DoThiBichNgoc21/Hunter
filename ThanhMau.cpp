#include "ThanhMau.h"

using namespace std;

HealthBar::HealthBar()
{
    PosX = 520;
    PosY = 35;
}

void HealthBar::Render(SDL_Rect* currentClip, SDL_Renderer* g_Renderer, BaseObject g_HealthBarTexture )
{
    g_HealthBarTexture.Render(PosX, PosY, g_Renderer, currentClip );
}

int HealthBar::GetPosX()
{
    return PosX;
}

int HealthBar::GetPosY()
{
    return PosY;
}
