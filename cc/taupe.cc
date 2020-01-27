#include "taupe.hh"

//destructeur de la class Taupe pour free texture
Taupe::~Taupe(){
  SDL_DestroyTexture(texture);
}

//pour mettre à jour le texture afin d'affichier le bombe sur le screen
void Taupe::DrawToRenderer(SDL_Renderer* renderer,SDL_Texture* texture){
  int width = 0, height = 0;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  SDL_Rect rect = {position_x,position_y,TAUPE_WIDTH,TAUPE_HEIGHT};
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

//le surcharge d'opérateur + pour calcul les notes
int operator +(int x,Taupe& taupe){
  int str;
  str= x + taupe.note;
  return str;
}
