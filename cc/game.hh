#pragma once

#include <time.h>
#include <vector>
#include <SDL_ttf.h>
#include <unistd.h>
#include "taupe.hh"
#include "bombe.hh"

using namespace std;

class Game{
public:
  Game(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font);
  ~Game(void);
  void Init();
  void Draw(SDL_Texture* texture,SDL_Texture* bombe,int Time);
  void DrawHit(SDL_Texture* texture,SDL_Texture* taupefuite,SDL_Texture* bombe,int Time);
  void Draw_text(std::string message, int x, int y);
  void ChangeFocusTaupe();
  void ChangeFocusBombe();
  virtual void Move(SDL_Texture* texture,SDL_Texture* bombe,int time) = 0;
  void HitTaupe(int x,int y);
  void HitBombe(int x,int y);
  bool Pass(int time);
  
  int level;
  int Hittaupe[13];
  int Hitbombe[13];
  vector<Taupe> FocusTaupe;
  vector<Taupe> NextTaupe;
  vector<Bombe> FocusBombe;
  vector<Bombe> NextBombe;

private:
  SDL_Renderer* renderer;
  SDL_Texture* texture;
  SDL_Texture* bombe;
  TTF_Font* Font;
  
  int Score;
};

