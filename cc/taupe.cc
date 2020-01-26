#include "taupe.hh"

Taupe::~Taupe(){
  SDL_DestroyTexture(texture);
}

void Taupe::DrawToRenderer(SDL_Renderer* renderer,SDL_Texture* texture){
  int width = 0, height = 0;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  SDL_Rect rect = {position_x,position_y,TAUPE_WIDTH,TAUPE_HEIGHT};
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

int operator +(int x,Taupe& taupe){
  int str;
  str= x + taupe.note;
  return str;
}
