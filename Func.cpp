#include "Func.h"

using namespace std;

//kiem tra loi thuoc linh vuc nao de de dang fix
void LogError( string error, int error_code )
{
    if ( error_code == SDL_ERROR )
    {
        cout << error << SDL_GetError() << endl;
    }
    if ( error_code == IMAGE_ERROR )
    {
        cout << error << IMG_GetError() << endl;
    }
    if ( error_code == MIXER_ERROR )
    {
        cout << error << Mix_GetError() << endl;
    }
    if ( error_code == TTF_ERROR )
    {
        cout << error << TTF_GetError() << endl;
    }
}
