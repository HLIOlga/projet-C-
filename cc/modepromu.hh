#pragma once

#include "game.hh"
#include "modesimple.hh"

class Modepromu:public Modesimple{
public:
  Modepromu(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font):Modesimple(renderer,texture,bombe,Font){}
  ~Modepromu();
  void Move(SDL_Texture* texture,SDL_Texture* bombe,int time);
private:
  //Game game;
};
