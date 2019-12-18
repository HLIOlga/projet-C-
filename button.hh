#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

//The button
class Button{
  private:
  //The attributes of the button
  SDL_Rect box;
  
  //The part of the button sprite sheet that will be shown
  //SDL_Rect* clip;
  SDL_Surface* button=NULL;
  SDL_Texture* text=NULL;
    
  public:
  //Initialize the variables
  Button( int x, int y, int w, int h );
  bool PutButton(const std::string s,SDL_Renderer* _renderer);
  bool isOnButton(int x,int y);

  //Handles events and set the button's sprite region
  void handle_events();

  //Shows the button on the screen
  void show();
};
