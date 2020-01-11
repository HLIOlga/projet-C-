#include "game.hh"

class Modesimple:public Game{
public:
  Modesimple(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font):Game(renderer,texture,bombe,Font){}
  ~Modesimple();
  void Move(SDL_Texture* texture,SDL_Texture* bombe,int time);
private:
  //Game game;
};
