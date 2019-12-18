#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "button.hh"

using namespace std;
SDL_Window * window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *background = NULL;
SDL_Texture * backtext = NULL;
Button playbutton(357,196,207,126);

void MelangeTaupe(){
  
}

void Destroy(){
    SDL_DestroyTexture(backtext);
    SDL_FreeSurface(background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
void halt(){
    cerr<<SDL_GetError()<<endl;
    Destroy();
    exit(-1);
}

bool sys_Init(){
  if(SDL_Init(SDL_INIT_VIDEO)<0)
    return false;
  window = SDL_CreateWindow("Jeu de Taupe",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 920, 518, 0);
  if (window == NULL){
    cout << "SDL could not create window with error: " << SDL_GetError() << endl;
    return false;
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer==NULL)
    return false;
  return true;
}
bool DrawBackGround(){
   background =IMG_Load("windows.jpeg");
   if (background==NULL)
     return false;
   backtext = SDL_CreateTextureFromSurface(renderer,background);
   if (backtext==NULL)
     return false;
   SDL_RenderClear(renderer);
   SDL_RenderCopy(renderer,backtext,NULL,NULL);
   SDL_RenderPresent(renderer);
   return true;
}

int main(int argc, char* argv[]){
  if (!sys_Init())       halt();
  if (!DrawBackGround())  halt();
  if (!playbutton.PutButton("play.jpg",renderer))       halt();
  SDL_Event windowEvent; // SDL窗口事件
  bool quit=false;
  while(!quit) {
    if (SDL_PollEvent(&windowEvent)) { // 对当前待处理事件进行轮询。
      switch (windowEvent.type) {
      case SDL_QUIT:       
	cout << "SDL quit!!" << endl;
	quit = true;
	break;
      case SDL_MOUSEBUTTONDOWN:
	if (windowEvent.button.button==SDL_BUTTON_LEFT)
	  if (playbutton.isOnButton(windowEvent.button.x,windowEvent.button.y))
	    cout << "is on the play button!"  << endl;
	break;
      }
    }
  }
  
  Destroy();
  
  return 0;
  
}
