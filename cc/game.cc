#include "game.hh"
#include "position.hh"
#include <string>
#include <iostream>

Game::Game(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font):renderer(renderer),texture(texture),bombe(bombe),Font(Font){
  Score	= 0;
  level = 1;
}

void Game::Init(){
  srand((unsigned int)time(0));
  int m=rand()%17;
  int n=rand()%17;
  int t=rand()%17;
  int i=rand()%17;
  FocusTaupe = Taupe(position_X[m],position_Y[m], 1, texture);
  NextTaupe  = Taupe(position_X[n],position_Y[n], 1, texture);
  FocusBombe = Bombe(position_X[t],position_Y[t], -1, bombe);
  NextBombe = Bombe(position_X[i],position_Y[i], -1, bombe);
}

void Game::ChangeFocusTaupe(){
  srand((unsigned int)time(0));
  int m=rand()%17;
  FocusTaupe.~Taupe();
  FocusTaupe = Taupe(NextTaupe);
  NextTaupe.~Taupe();
  NextTaupe = Taupe(position_X[m],position_Y[m], 1, texture);
}

void Game::ChangeFocusBombe(){
  srand((unsigned int)time(0));
  int m=rand()%17;
  FocusBombe.~Bombe();
  FocusBombe = Bombe(NextBombe);
  NextBombe.~Bombe();
  NextBombe = Bombe(position_X[m],position_Y[m], -1, bombe);
}

bool Game::HitTaupe(int x,int y){
  if(((FocusTaupe.position_x<x)&&(x<FocusTaupe.position_x+TAUPE_WIDTH)&&(FocusTaupe.position_y <y)&&(y<FocusTaupe.position_y+TAUPE_HEIGHT)) && FocusTaupe.present==1){
    Score+=FocusTaupe.note;
    return true;
  }
  else return false;
}

bool Game::HitBombe(int x,int y){
  if(((FocusBombe.position_x<x)&&(x<FocusBombe.position_x+BOMBE_WIDTH)&&(FocusBombe.position_y <y)&&(y<FocusBombe.position_y+BOMBE_HEIGHT)) && FocusBombe.present==1){
    Score+=FocusBombe.note;
    return true;
  }
  else return false;
}

bool Game::Pass(int time){
  if(time != 0 && Score == 3){
    Score=0;
    level++;
    return true;
  }
  else return false;
}

void Game::Draw_text(std::string message, int x, int y){
  SDL_Color color = { 255, 255, 255 };
  SDL_Surface* surface = TTF_RenderText_Blended(Font, message.c_str(), color);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_FreeSurface(surface);

  int width = 0, height = 0;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  SDL_Rect rect = {x, y, width, height};
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Game::Draw(SDL_Texture* texture,SDL_Texture* bombe,int Time){
  srand((unsigned int)time(0));
  int type=rand()%100;
  if(type%2==0){
    FocusTaupe.DrawToRenderer(renderer,texture);
    FocusBombe.present=0;
    FocusTaupe.present=1;
  }
  else{
    FocusBombe.DrawToRenderer(renderer,bombe);
    FocusTaupe.present=0;
    FocusBombe.present=1;
  }
  string cur_score;
  cur_score = "CURRENT SCORE:" + std::to_string(Score);
  Draw_text(cur_score, SCORE_POSITION_X, SCORE_POSITION_Y);

  string cur_time;
  cur_time = "CURRENT TIME:" + std::to_string(Time);
  Draw_text(cur_time,TIME_POSITION_X, TIME_POSITION_Y);

  string cur_level;
  cur_level = "CURRENT level:" + std::to_string(level);
  Draw_text(cur_level, LEVEL_POSITION_X, LEVEL_POSITION_Y);
}

Game::~Game(void){
  TTF_CloseFont(Font);
  SDL_DestroyTexture(texture);
  SDL_DestroyTexture(bombe);
  SDL_DestroyRenderer(renderer);
}
