#ifndef DA_H_
#define DA_H_

#include "BaseObject.h"

#define DA_POSITION_RANGE 500

using namespace std;

class Da
{
public:
    Da();
    ~Da();

    void LoadFromFile( string path, SDL_Renderer* g_Renderer );
    void Move( const int& acceleration );
    void Render( SDL_Renderer* g_Renderer, SDL_Rect* currentClip = nullptr );
    void Reset();

    int Speed( const int& acceleration );
    int GetPosX();
    int GetPosY();
    int GetWidth();
    int GetHeight();

private:
    int PosX;
    int PosY;
    int d_Width;
    int d_Height;
    bool wait;

    SDL_Texture *DaTexture;
};
#endif // DA_H_
