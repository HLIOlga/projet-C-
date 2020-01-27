#include "bombe.hh"

Bombe::~Bombe(){
  SDL_DestroyTexture(texture);
}

void Bombe::DrawToRenderer(SDL_Renderer* renderer,SDL_Texture* texture){
  int width = 0, height = 0;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  SDL_Rect rect = {position_x,position_y,TAUPE_WIDTH,TAUPE_HEIGHT};
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

int operator +(int x,Bombe& bombe){
  int str;
  str= x + bombe.note;
  return str;
}
