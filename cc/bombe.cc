#include "bombe.hh"

//destructeur de la class bombe pour free texture
Bombe::~Bombe(){
  SDL_DestroyTexture(texture);
}

//pour mettre à jour le texture afin d'affichier le bombe sur le screen
void Bombe::DrawToRenderer(SDL_Renderer* renderer,SDL_Texture* texture){
  int width = 0, height = 0;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  SDL_Rect rect = {position_x,position_y,TAUPE_WIDTH,TAUPE_HEIGHT};
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

//le surcharge d'opérateur + pour calcul les notes
int operator +(int x,Bombe& bombe){
  int str;
  str= x + bombe.note;
  return str;
}
