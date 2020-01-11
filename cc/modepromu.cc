#include "modepromu.hh"

void Modepromu::Move(SDL_Texture* texture,SDL_Texture* bombe,int time){
  static int Game_counter = 0;
  Game_counter++;
  Draw(texture,bombe,time);

  if(Game_counter>(60-level*5)){
    ChangeFocusTaupe();
    ChangeFocusBombe();
    sleep(0.1);
    Draw(texture,bombe,time);
    Game_counter=0;
  }
  
}
