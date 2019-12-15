#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;
SDL_Window * window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *background = NULL, *playbutton = NULL;
SDL_Texture * backtext = NULL, *playtext = NULL;
SDL_Rect PlayRect={357,196,207,126};

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

bool PutButton(){
  DrawBackGround();
  playbutton = IMG_Load("play.jpg");
  Uint32 color_key=SDL_MapRGB(playbutton->format,255,255,255);
  SDL_SetColorKey(playbutton,SDL_TRUE,color_key);
  if (playbutton==NULL)    return false;
  playtext=SDL_CreateTextureFromSurface(renderer,playbutton);
  if (backtext==NULL)     return false;
  SDL_RenderCopy(renderer,playtext,NULL,&PlayRect);
  SDL_RenderPresent(renderer);
  return true;
}

bool isOnButton(Uint32 x,Uint32 y){
  if (x>=357&&x<=564)
    if (y>=196&&y<=322)    return true;
  return false;
}

int main(int argc, char* argv[]){
  if (! sys_Init())       halt();
  if (!DrawBackGround())  halt();
  if (!PutButton())        halt();
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
	  if (isOnButton(windowEvent.button.x,windowEvent.button.y))
	    cout << "is on the play button!"  << endl;
	break;
      }
    }
  }
  
  Destroy();
  
  return 0;
  
}
