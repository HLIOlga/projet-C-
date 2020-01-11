#include "role.hh"

Role::Role(int x,int y,int niveau,SDL_Texture* texture){
  position_x=x;
  position_y=y;
  note=niveau;
}

Role::~Role(){
  SDL_DestroyTexture(texture);
}
