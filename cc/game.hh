#pragma once

#include <time.h>
#include <vector>
#include <SDL_ttf.h>
#include "taupe.hh"
#include "bombe.hh"

using namespace std;

class Game{
public:
  Game(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font);
  ~Game(void);
  void Init();
  void Draw(SDL_Texture* texture,SDL_Texture* bombe,int Time);
  void Draw_text(std::string message, int x, int y);
  void ChangeFocusTaupe();
  void ChangeFocusBombe();
  virtual void Move(SDL_Texture* texture,SDL_Texture* bombe,int time) = 0;
  bool HitTaupe(int x,int y);
  bool HitBombe(int x,int y);
  bool Pass(int time);
  
  int level;
private:
  //vector<Taupe> gametaupe;
  SDL_Renderer* renderer;
  SDL_Texture* texture;
  SDL_Texture* bombe;
  TTF_Font* Font;
  Taupe FocusTaupe;
  Taupe NextTaupe;
  Bombe FocusBombe;
  Bombe NextBombe;

  int Score;
};
