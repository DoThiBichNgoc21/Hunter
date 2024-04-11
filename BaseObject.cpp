#include "BaseObject.h"


using namespace std;

BaseObject::BaseObject()
{
    m_Texture = nullptr;

    m_Width = 0;
    m_Height = 0;
}

BaseObject::~BaseObject()
{
    Free();
}

void BaseObject::Free()          //Giai phong bo nho cua texture duoc tao bang SDL
{
    if ( m_Texture != nullptr )
    {
        SDL_DestroyTexture(m_Texture);
        m_Texture = nullptr;
        m_Width = 0;
        m_Height = 0;
    }
}

bool LoadFromRenderedTexture ( string TextureText, TTF_Font* g_Font, SDL_Color textColor, SDL_Renderer* g_Renderer)
{
    Free();

    SDL_Surface* textSurface = TTF_RenderGlyph32_Solid( g_Font, TextureText.c_str(), textColor);
    if( textSurface == nullptr )
    {
        cout << "SDL_ttf Error: " << TTF_GetError() << endl;
    }
    else
    {
        m_Texture = SDL_CreateTextureFromSurface(g_Renderer, textSurface);
        if ( m_Texture == nullptr )
        {
            cout << "SDL Error: " << SDL_GetError() << endl;
        }
        else
        {
             m_Width = textSurface->w;
             m_Height = textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    }
    return mTexture != nullptr;
}

bool BaseObject::LoadFromFile(string path, SDL_Renderer* g_Renderer)
{
    Free();

    SDL_Texture* tempTexture = nullptr;                   //tao con tro tam tho cho texture v� surface
    SDL_Surface* tempSurface = IMG_Load(path.c_str());

    if ( tempSurface == nullptr )
    {
        LogError("can't load image", IMG_ERROR);
    }
    else
    {
        SDL_SetColorKey( tempSurface, SDL_TRUE< SDL_MapRGB(tempSurface->format,0, 255, 255));
        tmpTexture = SDL_CreateTextureFromSurface(g_Renderer, tempSurface);
        if (tempTexture == nullptr)
        {
            LogError("Can not create texture from surface.", SDL_ERROR);
        }
        else
        {
            m_Width = tempSurface->w;
            m_Height = tempSurface->h;
        }
        SDL_FreeSurface(tempSurface);
    }
    m_Texture = tempTexture;
    return m_Texture != nullptr;
}

void BaseObject::Render(int x, int y, SDL_Renderer* g_Renderer, SDL_Rect* clip)
{
    SDL_Rect renderSpace = { x, y, m_Width, m_Height };
    if (clip != nullptr)
    {
        renderSpace.w = clip->w;
        renderSpace.h = clip->h;
    }

    SDL_RenderCopy(g_Renderer, m_Texture, clip, &renderSpace);
}

int BaseObject::GetWidth()
{
    return m_Width;
}

int BaseObject::GetHeight()
{
    return m_Height;
}
