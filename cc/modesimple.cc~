#include "modesimple.hh"

void Modesimple::Move(SDL_Texture* texture,SDL_Texture* bombe,int time){
  static int Game_counter = 0;
  Game_counter++;
  Draw(texture,bombe,time);
  if(Game_counter>20){
    ChangeFocusTaupe();
    ChangeFocusBombe();
    Draw(texture,bombe,time);
  }
}
