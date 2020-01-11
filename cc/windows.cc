#include "windows.hh"
#include "Defines.hh"

Window::Window(void){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    exit(1);
  }

  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

  TTF_Init();
  Font = TTF_OpenFont("sans.ttf", 20);

  win = SDL_CreateWindow(WINDOW_CAPTION, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  srand((unsigned int)time(0));

  LoadResouceFile();

  Update();
  Refresh();
}

void Window::Init(){
  switch(mode){
  case 'S':
    Time=60;
    simplegame = new Modesimple(renderer, taupe, bombe,Font);
    simplegame->Init();
    break;
  case 'I':
    Time = -1;
    infiniegame = new Modeinfinie(renderer, taupe, bombe,Font);
    infiniegame->Init();
    break;
  case 'P':
    Time=60;
    promugame = new Modepromu(renderer, taupe, bombe,Font);
    promugame->Init();
    break;
  }
}

void Window::ResetGame(){
  // do something
}

void Window::Start(){
  SDL_Event event;
  while(!quit){
    if (SDL_PollEvent(&event)){
      switch (event.type){
      case SDL_QUIT:
	cout<<"QUIT 1"<<endl;
	quit=true;
	break;
      case SDL_MOUSEBUTTONDOWN:
	if (event.button.button==SDL_BUTTON_LEFT){
	  GameModeChoix(event);
	  if ((PLAY_POSITION_x<event.button.x)&&(event.button.x<PLAY_POSITION_x+PLAY_WIDTH)&&(PLAY_POSITION_y <event.button.y)&&(event.button.y<PLAY_POSITION_y+PLAY_HEIGHT)){
	    cout << "is on the play button!"  << endl;
	    gameRunning=true;
	    
	    Init();	    
	    GameBegin();
	  }
	}
	break;
      }
    }
  }
}

void Window::GameModeChoix(SDL_Event event){
  if ((MODE_S_POSITION_x<event.button.x)&&(event.button.x<MODE_S_POSITION_x+MODE_S_WIDTH)
      &&(MODE_S_POSITION_y <event.button.y)&&(event.button.y<MODE_S_POSITION_y+MODE_S_HEIGHT)){
    mode='S';
    cout<<"MODE SIMPLE"<<endl;
  }
  if ((MODE_I_POSITION_x<event.button.x)&&(event.button.x<MODE_I_POSITION_x+MODE_I_WIDTH)
      &&(MODE_I_POSITION_y <event.button.y)&&(event.button.y<MODE_I_POSITION_y+MODE_I_HEIGHT)){
    mode='I';
    cout<<"MODE INFINIE"<<endl;
  }
  if ((MODE_P_POSITION_x<event.button.x)&&(event.button.x<MODE_P_POSITION_x+MODE_P_WIDTH)
      &&(MODE_P_POSITION_y <event.button.y)&&(event.button.y<MODE_P_POSITION_y+MODE_P_HEIGHT)){
    mode='P';
    cout<<"MODE PROMU"<<endl;
  }
}

void Window::Timecounter(){
  static int Time_counter=0;
  Time_counter++;
  if(Time_counter==50) {
    Time--;
    Time_counter=0;
  }
}

void Window::GameBegin(){
  SDL_Event event; 
  while(gameRunning){
    Timecounter();
    if(Time>0){
      if (SDL_PollEvent(&event)){
	switch (event.type){
	case SDL_QUIT:
	  cout<< "QUIT 2"<<endl;
	  Time=0;
	  quit=true;
	  break;
	case SDL_MOUSEBUTTONDOWN:
	  if (event.button.button==SDL_BUTTON_LEFT){
	    switch(mode){
	    case 'S':
	      ModeSInit(event);
	      break;
	    case 'P':
	      ModePInit(event);
	      break;
	    }
	  }
	  break;
	}
      }
    }
    else if (Time==0) 
      gameRunning = false;
    else {
      if (SDL_PollEvent(&event)){
	switch (event.type){
	case SDL_QUIT:
	  cout<< "QUIT 2"<<endl;
	  Time=0;
	  quit=true;
	  break;
	case SDL_MOUSEBUTTONDOWN:
	  if (event.button.button==SDL_BUTTON_LEFT){
	    ModeIInit(event);
	    }
	  break;
	}
      }
    }
    Update();
    Refresh();
  }
}

void Window::ModeSInit(SDL_Event event){
  simplegame->HitTaupe(event.button.x,event.button.y);
  simplegame->HitBombe(event.button.x,event.button.y);
  for(int i=0;i<13;i++){
    if(simplegame->Hittaupe[i]==1)
      cout << "Hit efficace!"  << endl;
    if(simplegame->Hitbombe[i]==1)
      cout << "Hit Bombe"  << endl;
  }
}

void Window::ModeIInit(SDL_Event event){
  infiniegame->HitTaupe(event.button.x,event.button.y);
  infiniegame->HitBombe(event.button.x,event.button.y);
  for(int i=0;i<13;i++){
    if(infiniegame->Hittaupe[i]==1)
      cout << "Hit efficace!"  << endl;
    if(infiniegame->Hitbombe[i]==1){
      cout << "Hit Bombe"  << endl;
      gameRunning = false;
      Time =0;
    }
  }
}

void Window::ModePInit(SDL_Event event){
  promugame->HitTaupe(event.button.x,event.button.y);
  promugame->HitBombe(event.button.x,event.button.y);
  for(int i=0;i<13;i++){
    if(promugame->Hittaupe[i]==1)
      cout << "Hit efficace!"  << endl;
    if(promugame->Hitbombe[i]==1)
      cout << "Hit Bombe"  << endl;
  }
  if(promugame->Pass(Time)){
    cout<<"passer"<<endl;
    Time=60;
  }
  if(promugame->level == 13){
    cout << "Passer tout "  << endl;
    gameRunning = false;
    Time=0;
  }
}

void Window::Refresh(){
  SDL_RenderPresent(renderer);
}

void Window::BeginWindow(){
  
  int width = 0, height = 0;
  
  SDL_QueryTexture(windows, NULL, NULL, &width, &height);
  SDL_Rect rect3 = {WINDOWS_POSITION_x, WINDOWS_POSITION_y, width, height};
  SDL_RenderCopy(renderer, windows, NULL, &rect3);

  SDL_QueryTexture(mode_s, NULL, NULL, &width, &height);
  SDL_Rect rect5 = {MODE_S_POSITION_x, MODE_S_POSITION_y, width, height};
  SDL_RenderCopy(renderer, mode_s, NULL, &rect5);
  Draw_text("MODE SIMPLE",MODE_S_POSITION_x+50, MODE_S_POSITION_y+160);
  
  SDL_QueryTexture(mode_i, NULL, NULL, &width, &height);
  SDL_Rect rect6 = {MODE_I_POSITION_x,MODE_I_POSITION_y, width, height};
  SDL_RenderCopy(renderer, mode_i, NULL, &rect6);
  Draw_text("MODE INFINIE",MODE_I_POSITION_x+50, MODE_I_POSITION_y+160);

  SDL_QueryTexture(mode_p, NULL, NULL, &width, &height);
  SDL_Rect rect7 = {MODE_P_POSITION_x, MODE_P_POSITION_y, width, height};
  SDL_RenderCopy(renderer, mode_p, NULL, &rect7);
  Draw_text("MODE PROMU",MODE_P_POSITION_x+50, MODE_P_POSITION_y+160);

  SDL_QueryTexture(play, NULL, NULL, &width, &height);
  SDL_Rect rect = {PLAY_POSITION_x, PLAY_POSITION_y, PLAY_WIDTH,PLAY_HEIGHT};
  SDL_RenderCopy(renderer, play, NULL, &rect);
}

void Window::Update(){
  SDL_RenderClear(renderer);
   int width = 0, height = 0;
  
  if(!gameRunning){
    if(Time==60 || Time == -1){
      BeginWindow();
    }
    if(Time==0){
      SDL_QueryTexture(gameover, NULL, NULL, &width, &height);
      SDL_Rect rect4 = {WINFIN_POSITION_x,WINFIN_POSITION_y, width, height};
      SDL_RenderCopy(renderer, gameover, NULL, &rect4);
    }
  }
  else{
    SDL_QueryTexture(windows, NULL, NULL, &width, &height);
    SDL_Rect rect2 = {WINDOWS_POSITION_x, WINDOWS_POSITION_y, width, height};
    SDL_RenderCopy(renderer, windows, NULL, &rect2);

    switch(mode){
    case 'S':
      simplegame->Move(taupe,bombe,Time);
      break;
    case 'I':
      infiniegame->Move(taupe,bombe,abs(Time));
      break;
    case 'P':
      promugame->Move(taupe,bombe,Time);
      break;
    }
  }
}

void Window::LoadResouceFile(){
  play = Load_image("play.jpg");
  taupe = Load_image("mole.png");
  bombe = Load_image("bombe.jpg");
  windows = Load_image("windows.jpeg");
  gameover = Load_image("gameover.png");
  mode_s = Load_image("rect.png");
  mode_i = Load_image("rect.png");
  mode_p = Load_image("rect.png");
}


SDL_Texture* Window::Load_image(std::string FilePath){
  SDL_Surface* picture = nullptr;

  picture = IMG_Load(FilePath.c_str());

  Uint32 colorkey = SDL_MapRGB(picture->format, 255, 255, 255);
  SDL_SetColorKey(picture, SDL_TRUE, colorkey);

  SDL_Texture* result = SDL_CreateTextureFromSurface(renderer, picture);
  SDL_FreeSurface(picture);

  return result;
}

void Window::Draw_text(std::string message,int x,int y){
  SDL_Color color = { 0, 0, 0 };
  SDL_Surface* surface = TTF_RenderText_Blended(Font, message.c_str(), color);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_FreeSurface(surface);
  
  int width = 0, height = 0;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  SDL_Rect rect = {x, y, width, height};
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

Window::~Window(void){
  TTF_CloseFont(Font);
  TTF_Quit();
  SDL_DestroyTexture(play);
  SDL_DestroyTexture(taupe);
  SDL_DestroyTexture(windows);
  SDL_DestroyTexture(bombe);
  SDL_DestroyTexture(gameover);
  SDL_DestroyTexture(mode_s);
  SDL_DestroyTexture(mode_i);
  SDL_DestroyTexture(mode_p);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();

}
