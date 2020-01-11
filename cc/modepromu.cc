#include "modepromu.hh"

void Modepromu::Move(SDL_Texture* texture,SDL_Texture* bombe,int time){
  static int Game_counter = 0;
  Game_counter++;
  Draw(texture,bombe,time);
  
  switch(level){
  case 1:
    if(Game_counter>60){
      ChangeFocusTaupe();
      ChangeFocusBombe();
      Draw(texture,bombe,time);
      Game_counter=0;
    }
    break;
  case 2:
    if(Game_counter>40){
      ChangeFocusTaupe();
      ChangeFocusBombe();
      Draw(texture,bombe,time);
      Game_counter=0;
    }
    break;
  case 3:
    if(Game_counter>20){
      ChangeFocusTaupe();
      ChangeFocusBombe();
      Draw(texture,bombe,time);
      Game_counter=0;
    }
    break;
  case 4:
    if(Game_counter>10){
      ChangeFocusTaupe();
      ChangeFocusBombe();
      Draw(texture,bombe,time);
      Game_counter=0;
    }
    break;  
  }
}
