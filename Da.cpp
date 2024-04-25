#include "Da.h"

using namespace std;

void Da::Reset()
{
    PosX = rand() % ( SCREEN_WIDTH + DA_POSITION_RANGE ) + SCREEN_WIDTH;
    PosY = 250;
    wait = true;
}

Da::Da()
{
    PosX = 0;
    PosY = 0;
    d_Width = 0;
    d_Height = 0;
    Reset();

    DaTexture = nullptr;
}

Da::~Da()
{
    PosX = 0;
    PosY = 0;
    d_Width = 0;
    d_Height = 0;

    if ( DaTexture != nullptr )
    {
        DaTexture = nullptr;
    }
}

void Da::LoadFromFile( string path, SDL_Renderer* g_Renderer )
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
            d_Width = tmpSurface->w;
            d_Height = tmpSurface->h;
         }
         SDL_FreeSurface ( tmpSurface );
     }
     DaTexture = tmpTexture;
 }

 void Da::Move( const int& acceleration )
{
    if ( wait == false )
    {
        return;
    }
    PosX += -( DA_SPEED + acceleration );
    PosY = 250;
    if ( (PosX + MAX_DA_WIDTH < 0) )
    {
       Reset();
    }
}

void Da::Render( SDL_Renderer* g_Renderer, SDL_Rect* currentClip)
{
     SDL_Rect renderSpace = { PosX, PosY, d_Width, d_Height };
      if ( currentClip != nullptr )
      {
          renderSpace.w = currentClip->w;
          renderSpace.h = currentClip->h;
      }
      SDL_RenderCopy( g_Renderer, DaTexture, currentClip, &renderSpace);
}

int Da::Speed( const int& acceleration )
{
   return DA_SPEED + acceleration;
}

int Da::GetPosX()
{
    return PosX;
}

int Da::GetPosY()
{
    return PosY;
}

int Da::GetWidth()
{
    return d_Width;
}

int Da::GetHeight()
{
    return d_Height;
}












