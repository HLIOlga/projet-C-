#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

void MelangeTaupe(){
  
}


int main(void){
  if(SDL_Init(SDL_INIT_VIDEO)<0)
    cout<<"erreur"<<endl;
 
  SDL_Window * window = SDL_CreateWindow("Jeu de Taupe",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 920, 518, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Surface *image =IMG_Load("windows.jpeg");
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
  //SDL_Surface *SDL_DisplayFormat(SDL_Surface *surface);
  
  if (NULL == window) {
        cout << "SDL could not create window with error: " << SDL_GetError() << endl;
    }

    SDL_Event windowEvent; // SDL窗口事件
    while(true) {
        if (SDL_PollEvent(&windowEvent)) { // 对当前待处理事件进行轮询。
            if (SDL_QUIT == windowEvent.type) { // 如果事件为推出SDL，结束循环。
                cout << "SDL quit!!" << endl;
                break;
            }
        }
	SDL_RenderCopy(renderer, texture, NULL, NULL);
        //显示出来
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window); // 推出SDL窗体
    SDL_Quit(); // SDL推出
  
  return 0;
  
}
