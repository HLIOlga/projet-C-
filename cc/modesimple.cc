#include "modesimple.hh"

void Modesimple::Move(SDL_Texture* texture,SDL_Texture* bombe,int time){
  static int Game_counter = 0;
  Game_counter++;
  Draw(texture,bombe,time);
  if(Game_counter>20){
    ChangeFocusTaupe();
    ChangeFocusBombe();
    sleep(0.1);
    Draw(texture,bombe,time);
  }
}
