#ifndef BULLET_H_
#define BULLET_H_


#include "BaseObject.h"
#include "Func.h"
#include "Ech.h"

class Bullet
{
  public:
      Bullet();

       void reset();
       void LoadFromFile( string path, SDL_Renderer* g_Renderer);
       void Move(Character ech);
       void Render( SDL_Renderer* g_Renderer, SDL_Rect* currentClip = nullptr );
       void Start();
       bool Fire();

       int GetPosX();
       int GetPosY();
       int GetWidth();
       int GetHeight();

  private:
       int PosX;
       int PosY;
       int b_Width;
       int b_Height;
       int time;
       int wait;

       SDL_Texture* BulletTexture;

};

#endif // BULLET_H_
