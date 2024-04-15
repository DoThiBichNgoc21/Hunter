#include "KeThu.h"

using namespace std;

Enemy::Enemy( int _type )
{
    PosX = 0;
    PosY = 0;
    e_Width = 0;
    e_Height = 0;
    type = _type;

    if ( type = IN_AIR_ENEMY )
    {
        PosX = rand() % ( SCREEN_WIDTH + ENEMY_POSITION_RANGE ) + SCREEN_WIDTH;
        PosY = 330;
    }
    else if ( type = ON_GROUND_ENEMY )
    {
        PosX = rand() % ( SCREEN_WIDTH + ENEMY_POSITION_RANGE ) + SCREEN_WIDTH;
        PosY = GROUND - 8;
    }
    EnemyTexture = nullptr;
}

Enemy::~Enemy()
{
    PosX = 0;
    PosY = 0;
    e_Width = 0;
    e_Height = 0;
    type = 0;
    if ( EnemyTexture != nullptr )
    {
        EnemyTexture = nullptr;
    }
}

 void Enemy::LoadFromFile ( string path, SDL_Renderer* g_Renderer )
 {
     SDL_Texture* tmpTexture = nullptr;
     SDL_Surface* tmpSurface = IMG_Load( path.c_str() );
     if ( tmpSurface = nullptr )
     {
        LogError("Khong the load img ", IMAGE_ERROR);
     }
     else
     {
         SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 0, 255, 255 ) );
         tmpTexture = SDL_CreateTextureFromSurface( g_Renderer, tmpSurface);
         if ( tmpSurface = nullptr )
         {
            LogError("Khong the tao ket cau tu be mat", SDL_ERROR);
         }
         else{
            e_Width = tmpSurface->w;
            e_Height = tmpSurface->h;
         }
         SDL_FreeSurface ( tmpSurface );
     }
     EnemyTexture = tmpTexture;
 }

  void Enemy::Move( const int& acceleration )
  {
      PosX += -(ENEMY_SPEED + acceleration);
      if ( PosX + MAX_ENEMY_WIDTH < 0 )
      {
          PosX = rand() % ( SCREEN_WIDTH + ENEMY_POSITION_RANGE ) + SCREEN_WIDTH;
          if ( type = IN_AIR_ENEMY )
          {
              PosY = 330;
          }
      }
  }

  void Enemy::Render( SDL_Renderer* g_Renderer, SDL_Rect* currentClip )
  {
      SDL_Rect renderSpace = { PosX, PosY, e_Width, e_Height };
      if ( currentClip != nullptr )
      {
          renderSpace.w = currentClip->w;
          renderSpace.h = currentClip->h;
      }
      SDL_RenderCopy( g_Renderer, EnemyTexture, currentClip, &renderSpace);
  }

int Enemy::GetType()
   {
       if ( type == IN_AIR_ENEMY )
       {
           return IN_AIR_ENEMY;
       }
       if ( type == IN_AIR_ENEMY )
       {
           return ON_GROUND_ENEMY;
       }
   }

int Enemy::Speed( const int& acceleration )         //acceleration : sự tăng tốc.
{
    return ENEMY_SPEED + acceleration;
}

int Enemy::GetPosX()
{
    return PosX;
}

int Enemy::GetPosY()
{
    return PosY;
}

int Enemy::GetWidth()
{
    return e_Width;
}

int Enemy::GetHeight()
{
    return e_Height;
}
