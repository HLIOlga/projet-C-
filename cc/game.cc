#include "game.hh"
#include "position.hh"
#include <string>
#include <iostream>

using namespace std;

//constructeur de la class de Game
Game::Game(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* bombe,TTF_Font* Font):renderer(renderer),texture(texture),bombe(bombe),Font(Font){
  Score	= 0;
  level = 1;
}

//initialisation du jeu, pour creer les taupe et bombe aléatoire
void Game::Init(){
  srand((unsigned int)time(0));
  int m=rand()%17;
  int n=rand()%17;
  int t=rand()%17;
  int i=rand()%17;

  //on définir les positions dans un tableau,en utilisant le nombre aléatoire pour présenter les taupe et les bombes dans différente position
  FocusTaupe.push_back(Taupe(position_X[m],position_Y[m], 1, texture));
  NextTaupe.push_back(Taupe(position_X[n],position_Y[n], 1, texture));
  FocusBombe.push_back(Bombe(position_X[t],position_Y[t], -1, bombe));
  NextBombe.push_back(Bombe(position_X[i],position_Y[i], -1, bombe));
}

//pour mettre à jour le vector de la taupe
void Game::ChangeFocusTaupe(){
  srand((unsigned int)time(0));
  int m;
  FocusTaupe.assign(NextTaupe.begin(), NextTaupe.end());
  NextTaupe.clear();
  //pour réaliser la situation que les taupes peuvent présenter en même temps,et en maximal il y aura quatre taupes presents en même temps
  int nombre=rand()%3+1;
  for(int i=0;i<nombre;i++){
    m=rand()%17;
    NextTaupe.push_back(Taupe(position_X[m],position_Y[m], 1, texture));
  }
}

//pour mettre à jour le vector de la bombe
void Game::ChangeFocusBombe(){
  srand((unsigned int)time(0));
  int m;
  FocusBombe.assign(NextBombe.begin(), NextBombe.end());
  NextBombe.clear();
  //pour réaliser la situation que  en maximal il y aura un bombe presents en même temps
  for(int i=0;i<1;i++){
    m=rand()%17;
    NextBombe.push_back(Bombe(position_X[m],position_Y[m], -1, bombe));
  }
}

//pour juger si on frappe la taupe
void Game::HitTaupe(int x,int y){
  static int counter_taupe = 0;
  //en utilisant le boucle for et iterateur
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

//pour juger si on frappe la bombe
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

//pour définir la condition de passer un niveau du jeu
bool Game::Pass(int time){
  if(time != 0 && Score == 3){
    Score=0;
    level++;
    return true;
  }
  else return false;
}

//pour présenter les text dans la fenêtre
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

//pour pésenter les changements du chaque action du joueur
void Game::DrawHit(SDL_Texture* texture,SDL_Texture* taupefuite,SDL_Texture* bombe,int Time){
  int i=0,j=0;
  //si le joueur a frappé sur la bombe; il va affichier le smoke
  for(auto& iterbombe:FocusBombe){
    if(iterbombe.present==1 && Hitbombe[j]==1)
      iterbombe.DrawToRenderer(renderer,bombe);
    j++;
  }

  //si le joueur a frappé sur la taupe,il va affichier la figure que le taupe frappée; sinon il va affichier la figure que la taupe fuite
  for(auto& itertaupe:FocusTaupe){
    if(itertaupe.present==1 && Hittaupe[i]==1)
      itertaupe.DrawToRenderer(renderer,texture);
    if(itertaupe.present==1 && Hittaupe[i]==0)
      itertaupe.DrawToRenderer(renderer,taupefuite);
    i++;
  }

  //affichier la note du joueur
  string cur_score;
  cur_score = "CURRENT SCORE:" + std::to_string(Score);
  Draw_text(cur_score, SCORE_POSITION_X, SCORE_POSITION_Y);

  //affichier le temps reste du joueur
  string cur_time;
  cur_time = "CURRENT TIME:" + std::to_string(Time);
  Draw_text(cur_time,TIME_POSITION_X, TIME_POSITION_Y);

  //affichier le niveau du joueur
  string cur_level;
  cur_level = "CURRENT level:" + std::to_string(level);
  Draw_text(cur_level, LEVEL_POSITION_X, LEVEL_POSITION_Y);
}

//pour pésenter les changements du taupe et bombe
void Game::Draw(SDL_Texture* texture,SDL_Texture* bombe,int Time){
  srand((unsigned int)time(0));
  //pour différentier la possibilité de la pésence de la taupe et la bombe
  int type=rand()%12;
  //si la nombre aléatoire est inférieur à 10, il va présenter le taupe;
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
  //sinon il va presenter la bombe
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
  
  //affichier la note du joueur
  string cur_score;
  cur_score = "CURRENT SCORE:" + std::to_string(Score);
  Draw_text(cur_score, SCORE_POSITION_X, SCORE_POSITION_Y);

  //affichier le temps reste du joueur
  string cur_time;
  cur_time = "CURRENT TIME:" + std::to_string(Time);
  Draw_text(cur_time,TIME_POSITION_X, TIME_POSITION_Y);

  //affichier le niveau du joueur
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
