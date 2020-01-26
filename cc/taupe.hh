#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Defines.hh"
#include "role.hh"

class Taupe:public Role{
public:
  Taupe():Role(0,0,1,NULL){}
  Taupe(int x,int y,int niveau,SDL_Texture* texture):Role(x,y,niveau,texture){}
  Taupe(const Taupe& taupe):Role(taupe.position_x,taupe.position_y,taupe.note,NULL){}
  ~Taupe();
  friend int operator +(int x,Taupe& taupe);

  void DrawToRenderer(SDL_Renderer* renderer,SDL_Texture* texture);
private:
  SDL_Texture* texture=NULL;
};

extern int operator +(int x,Taupe& taupe);
