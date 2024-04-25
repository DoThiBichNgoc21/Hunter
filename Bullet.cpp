#include "Bullet.h"

using namespace std;

void Bullet::reset()
{
    PosX = 0;
    PosY = SCREEN_HEIGHT;
    time = 0;
    wait = true;
}
Bullet::Bullet()
{
    reset();
    b_Width = SCREEN_WIDTH - 280;
    b_Height = 23;
}

void Bullet::LoadFromFile( string path, SDL_Renderer* g_Renderer )
{
     SDL_Texture* tmpTexture = nullptr;
     SDL_Surface* tmpSurface = IMG_Load( path.c_str() );
     if ( tmpSurface == nullptr )
     {
        LogError("Khong the load img ", IMAGE_ERROR);
     }
     else
     {
         SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 0, 255, 255 ) );
         tmpTexture = SDL_CreateTextureFromSurface( g_Renderer, tmpSurface);
         if ( tmpTexture == nullptr )
         {
            LogError("Khong the tao ket cau tu be mat", SDL_ERROR);
         }
         SDL_FreeSurface ( tmpSurface );
     }
     BulletTexture = tmpTexture;
}

void Bullet::Move( Character ech )
{
    if( wait == true )
    {
        return;
    }
    if ( time >= 20 )
    {
        reset();
        return;
    }
    time++;
    PosX = ech.GetPosX() + 50;
    PosY = ech.GetPosY() + 25;
}

void Bullet::Render( SDL_Renderer* g_Renderer, SDL_Rect* currentClip )
{
    SDL_Rect renderSpace = { PosX, PosY, b_Width, b_Height };
    SDL_RenderCopy( g_Renderer, BulletTexture, currentClip, &renderSpace );
}

void Bullet::Start()
{
    wait = false;
    time = 0;
}

int Bullet::GetPosX()
{
    return PosX;
}

int Bullet::GetPosY()
{
    return PosY;
}

int Bullet::GetWidth()
{
    return b_Width;
}

int Bullet::GetHeight()
{
    return b_Height;
}
