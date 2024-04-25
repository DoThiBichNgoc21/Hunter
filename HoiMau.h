#ifndef HOIMAU_H_
#define HOIMAU_H_

#include "BaseObject.h"

#define APPLE_POSITION_RANGE 250

using namespace std;

class Apple
{
public:
    Apple();
    ~Apple();

    void LoadFromFile(string path, SDL_Renderer* g_Renderer );
    void Move( const int& acceleration );
    void Render( SDL_Renderer* g_Renderer, SDL_Rect* currentClip = nullptr );

    int Speed( const int& acceleration );
    int GetPosX();
    int GetPosY();
    int GetWidth();
    int GetHeight();

private:
    int PosX, PosY;
    int e_Width, e_Height;
    SDL_Texture *AppleTexture;
};
#endif // HOIMAU_H_
