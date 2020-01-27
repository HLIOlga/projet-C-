#include "modeinfinie.hh"

//le changement de la taupe et la bombe va devenir le plus en plus vite au cours du temps
void Modeinfinie::Move(SDL_Texture* texture,SDL_Texture* bombe,int time){
  static int Game_counter = 0;
  Game_counter++;
  Draw(texture,bombe,time);
  if(time<20){
    if(Game_counter>60){
      ChangeFocusTaupe();
      ChangeFocusBombe();
      Game_counter=0;
    }
  }
  else if (time<40){
    if(Game_counter>40){
      ChangeFocusTaupe();
      ChangeFocusBombe();
      Game_counter=0;
    }
  }
  else if (time<60){
    if(Game_counter>20){
      ChangeFocusTaupe();
      ChangeFocusBombe();
      Game_counter=0;
    }
  }
  else {
    if(Game_counter>10){
      ChangeFocusTaupe();
      ChangeFocusBombe();
      Game_counter=0;
    }
  }
}

