#include "game.hh"
#include "position.hh"
#include <string>
#include <iostream>

using namespace std;

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
  FocusTaupe.push_back(Taupe(position_X[m],position_Y[m], 1, texture));
  NextTaupe.push_back(Taupe(position_X[n],position_Y[n], 1, texture));
  FocusBombe.push_back(Bombe(position_X[t],position_Y[t], -1, bombe));
  NextBombe.push_back(Bombe(position_X[i],position_Y[i], -1, bombe));
}

void Game::ChangeFocusTaupe(){
  srand((unsigned int)time(0));
  int m;
  FocusTaupe.assign(NextTaupe.begin(), NextTaupe.end());
  NextTaupe.clear();
  for(int i=0;i<level;i++){
    m=rand()%17;
    NextTaupe.push_back(Taupe(position_X[m],position_Y[m], 1, texture));
  }
}

void Game::ChangeFocusBombe(){
  srand((unsigned int)time(0));
  int m;
  FocusBombe.assign(NextBombe.begin(), NextBombe.end());
  NextBombe.clear();
  for(int i=0;i<1;i++){
    m=rand()%17;
    NextBombe.push_back(Bombe(position_X[m],position_Y[m], -1, bombe));
  }
}

void Game::HitTaupe(int x,int y){
  static int counter_taupe = 0;
  for(auto& iter:FocusTaupe){
    if((((iter.position_x<x)&&(x<iter.position_x+TAUPE_WIDTH))&&((iter.position_y <y)&&(y<iter.position_y+TAUPE_HEIGHT))) && iter.present==1){
      Score=Score+iter;
      Hittaupe[counter_taupe]=1;
    }
    else Hittaupe[counter_taupe]=0;
    counter_taupe++;    
  }
  counter_taupe=0;
}

void Game::HitBombe(int x,int y){
  static int counter_bombe = 0;
  for(auto& iter:FocusBombe){
    if((((iter.position_x<x)&&(x<iter.position_x+BOMBE_WIDTH))&&((iter.position_y <y)&&(y<iter.position_y+BOMBE_HEIGHT))) && iter.present==1){
      Score=Score+iter;
      Hitbombe[counter_bombe]=1;
    }
    else Hitbombe[counter_bombe]=0;
    counter_bombe++;
  }
  counter_bombe=0;
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

void Game::DrawHit(SDL_Texture* texture,SDL_Texture* taupefuite,SDL_Texture* bombe,int Time){
  int i=0,j=0;
  for(auto& iterbombe:FocusBombe){
    if(iterbombe.present==1 && Hitbombe[j]==1)
      iterbombe.DrawToRenderer(renderer,bombe);
    j++;
  }

  for(auto& itertaupe:FocusTaupe){
    if(itertaupe.present==1 && Hittaupe[i]==1)
      itertaupe.DrawToRenderer(renderer,texture);
    if(itertaupe.present==1 && Hittaupe[i]==0)
      itertaupe.DrawToRenderer(renderer,taupefuite);
    i++;
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

void Game::Draw(SDL_Texture* texture,SDL_Texture* bombe,int Time){
  srand((unsigned int)time(0));
  int type=rand()%12;
  if(type<10){
    for(auto& iterbombe:FocusBombe){
      iterbombe.present=0;
    }
    
    for(auto& itertaupe:FocusTaupe){
      itertaupe.DrawToRenderer(renderer,texture);
      itertaupe.present=1;
      sleep(0.5);
    }
  }
  else{
    for(auto& iterbombe:FocusBombe){
      iterbombe.DrawToRenderer(renderer,bombe);
      iterbombe.present=1;
      sleep(0.5);
    }
    for(auto& itertaupe:FocusTaupe){
      itertaupe.present=0;
    }
    
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
  FocusTaupe.clear();
  NextTaupe.clear();
  FocusBombe.clear();
  NextBombe.clear();
}
