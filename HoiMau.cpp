#include "HoiMau.h"

using namespace std;

Apple::Apple()
{
    PosX = 0;
    PosY = 0;
    e_Width = 0;
    e_Height = 0;

    PosX = 1000;
    PosY = 250;

    AppleTexture = nullptr;
}

Apple::~Apple()
{
    PosX = 0;
    PosY = 0;
    e_Width = 0;
    e_Height = 0;

    if ( AppleTexture != nullptr )
    {
        AppleTexture = nullptr;
    }
}

void Apple::LoadFromFile(string path, SDL_Renderer* g_Renderer )
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
         if ( tmpSurface == nullptr )
         {
            LogError("Khong the tao ket cau tu be mat", SDL_ERROR);
         }
         else{
            e_Width = tmpSurface->w;
            e_Height = tmpSurface->h;
         }
         SDL_FreeSurface ( tmpSurface );
     }
     AppleTexture = tmpTexture;
}

void Apple::Move( const int& acceleration )
{
    PosX += -( ENEMY_SPEED + acceleration );
    if ( PosX + MAX_ENEMY_WIDTH < 0 )
    {
        PosX = rand() % ( SCREEN_WIDTH + APPLE_POSITION_RANGE ) + SCREEN_WIDTH;
        PosY = 250;
    }
}

void Apple::Render ( SDL_Renderer* g_Renderer, SDL_Rect* currentClip )
{
    SDL_Rect renderSpace = { PosX, PosY, e_Width, e_Height };
    if ( currentClip != nullptr )
    {
        renderSpace.w = currentClip->w;
        renderSpace.h = currentClip->h;
    }
    SDL_RenderCopy( g_Renderer, AppleTexture, currentClip, &renderSpace );
}

 int Apple::Speed( const int& acceleration )
 {
     return ENEMY_SPEED + acceleration;
 }

 int Apple::GetPosX()
 {
     return PosX;
 }

 int Apple::GetPosY()
 {
     return PosY;
 }

 int Apple::GetWidth()
 {
     return e_Width;
 }

 int Apple::GetHeight()
 {
     return e_Height;
 }






