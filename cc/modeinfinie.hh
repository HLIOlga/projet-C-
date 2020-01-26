#pragma once

#include "game.hh"
#include "modesimple.hh"

class Modeinfinie:public Modesimple{
public:
  Modeinfinie(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font):Modesimple(renderer,texture,bombe,Font){}
  ~Modeinfinie();
  void Move(SDL_Texture* texture,SDL_Texture* bombe,int time);
private:
};
