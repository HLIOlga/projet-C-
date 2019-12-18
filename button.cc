#include "button.hh"

Button::Button( int x, int y, int w, int h )
{
    //Set the button's attributes
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    //Set the default sprite
    //clip = &clips[ CLIP_MOUSEOUT ];
}

bool Button::PutButton(const std::string s,SDL_Renderer* _renderer){
  button = IMG_Load(s.c_str());
  Uint32 color_key=SDL_MapRGB(button->format,255,255,255);
  SDL_SetColorKey(button,SDL_TRUE,color_key);
  if (button==NULL)    return false;
  text=SDL_CreateTextureFromSurface(_renderer,button);
  SDL_RenderCopy(_renderer,text,NULL,&box);
  SDL_RenderPresent(_renderer);
  return true;
}

bool Button::isOnButton(int x,int y){
  if (x>=box.x && x<= (box.x+box.w))
    if (y>=box.y && y<=(box.y+box.h))    return true;
  return false;
}
