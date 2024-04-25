#include "Botton.h"


Button::Button()
{
    position.x = 0;
    position.y = 0;

    currentSprite = BUTTON_MOUSE_OUT;
}

Button::Button( int x, int y)
{
    position.x = x;
    position.y = y;

    currentSprite = BUTTON_MOUSE_OUT;
}

void Button::SetPosition(int x, int y)   //Dat vi tri
{
    position.x = x;
    position.y = y;

}

 bool Button::IsInside(SDL_Event *e, int size)   //Kiểm tra con trỏ chuột có nằm trong vùng nút hay không
 {
    if ( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        int x, y, button_height, button_width;
        if ( size == SMALL_BUTTON )
        {
            button_height = SMALL_BUTTON_HEIGHT;
            button_width = SMALL_BUTTON_WIDTH;
        }
        else
        {
            button_height = COMMON_BUTTON_HEIGHT;
            button_width = COMMON_BUTTON_WIDTH;
        }
        SDL_GetMouseState(&x, &y);    //Lấy vị trí hiện tại của con trỏ chuột
        bool inside = true;
        if ( x < position.x ) inside = false;                                //Kiểm tra vị trí hiện tại của con trỏ chuột
        else if ( x > position.x + button_width ) inside = false;
        else if ( y < position.y ) inside = false;
        else if ( y > position.y + button_height ) inside = false;
        return inside;
    }
    return false;
 }

  void Button::Render(SDL_Rect* currentClip, SDL_Renderer* g_Renderer, BaseObject g_ButtonTexture)    //Vẽ nút lên màn
  {
      g_ButtonTexture.Render( position.x, position.y, g_Renderer, currentClip );
  }








