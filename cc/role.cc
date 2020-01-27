#include "role.hh"

//le constructeur de la class de Role,pour initialiser les positions et la note
Role::Role(int x,int y,int niveau,SDL_Texture* texture){
  position_x=x;
  position_y=y;
  note=niveau;
}

//destructeur de la class Role pour free texture
Role::~Role(){
  SDL_DestroyTexture(texture);
}
