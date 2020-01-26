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

void Modesimple::HitMove(SDL_Texture* texture,SDL_Texture* taupefuite,SDL_Texture* bombe,SDL_Texture* taupehit,SDL_Texture* smoke,int time){
  static int Game_counter2 = 0;
  Game_counter2++;
  DrawHit(taupehit,taupefuite,smoke,time);
}
