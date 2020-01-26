#pragma once

#include "game.hh"

class Modesimple:public Game{
public:
  Modesimple(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font):Game(renderer,texture,bombe,Font){}
  ~Modesimple();
  void Move(SDL_Texture* texture,SDL_Texture* bombe,int time);
  //void HitMove(SDL_Texture* texture,SDL_Texture* taupefuite,SDL_Texture* bombe,int time);
  void HitMove(SDL_Texture* texture,SDL_Texture* taupefuite,SDL_Texture* bombe,SDL_Texture* taupehit,SDL_Texture* smoke,int time);
private:
  //Game game;
};
