#include "modepromu.hh"

//le changement de la taupe et la bombe va devenir le plus en plus vite au cours du niveau
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

