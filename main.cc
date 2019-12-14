#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;
SDL_Window * window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *background = NULL;
SDL_Texture * backtext = NULL;

void MelangeTaupe(){
  
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
  if (! sys_Init())
    cout << "erreur" << endl;
  if (!DrawBackGround())
    cout << "erreur" << endl;
   SDL_Event windowEvent; // SDL窗口事件
    while(true) {
        if (SDL_PollEvent(&windowEvent)) { // 对当前待处理事件进行轮询。
            if (SDL_QUIT == windowEvent.type) { // 如果事件为推出SDL，结束循环。
                cout << "SDL quit!!" << endl;
                break;
            }
	    else if(SDL_KEYDOWN  == windowEvent.type ){
	      //
	    }
	    
        }
	SDL_RenderCopy(renderer, backtext, NULL, NULL);
        //显示出来
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(backtext);
    SDL_FreeSurface(background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); // 推出SDL窗体
    SDL_Quit(); // SDL推出
  
  return 0;
  
}
