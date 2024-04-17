#ifndef KETHU_H_
#define KETHU_H_

#include "BaseObject.h"

#define ENEMY_MAX_HEIGHT 300
#define ENEMY_MIN_HEIGHT 370
#define ENEMY_POSITION_RANGE 250

using namespace std;

class Enemy
{
public:
    Enemy( int _type = 0);
    ~Enemy();

    void LoadFromFile ( string path, SDL_Renderer* g_Renderer );
    void Move( const int& acceleration );
    void Render( SDL_Renderer* g_Renderer, SDL_Rect* currentClip = nullptr );

    int GetType();
    int Speed( const int& acceleration );
    int GetPosX();
    int GetPosY();
    int GetWidth();
    int GetHeight();

private:
    int PosX, PosY;
    int e_Width, e_Height;
    int type;

    SDL_Texture *EnemyTexture;
};


#endif // KETHU_H_INCLUDED
