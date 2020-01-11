#include "game.hh"

class Modepromu:public Game{
public:
  Modepromu(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font):Game(renderer,texture,bombe,Font){}
  ~Modepromu();
  void Move(SDL_Texture* texture,SDL_Texture* bombe,int time);

private:
  //Game game;
};
