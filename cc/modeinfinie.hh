#include "game.hh"

class Modeinfinie:public Game{
public:
  Modeinfinie(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font):Game(renderer,texture,bombe,Font){}
  ~Modeinfinie();
  void Move(SDL_Texture* texture,SDL_Texture* bombe,int time);
private:
};
