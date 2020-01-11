#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Defines.hh"

class Role{
public:
  Role(int x,int y,int niveau,SDL_Texture* texture);
  ~Role();

  virtual void DrawToRenderer(SDL_Renderer* renderer,SDL_Texture* texture) = 0;
  int position_x;
  int position_y;
  int note;
  int present;

private:
  SDL_Texture* texture=NULL;
};
