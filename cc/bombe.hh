#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Defines.hh"
#include "role.hh"

class Bombe:public Role{
public:
  Bombe():Role(0,0,1,NULL){}
  Bombe(int x,int y,int niveau,SDL_Texture* texture):Role(x,y,niveau,texture){}
  ~Bombe();

  void DrawToRenderer(SDL_Renderer* renderer,SDL_Texture* texture);
private:
  SDL_Texture* texture=NULL;
};
