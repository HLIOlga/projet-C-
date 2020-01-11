#pragma once

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "game.hh"
#include "modesimple.hh"
#include "modeinfinie.hh"
#include "modepromu.hh"

using namespace std;

class Window{
public:
	Window(void);
	~Window(void);

	void Start();
        void BeginWindow();
        void Timecounter();
        void GameBegin();
	void Refresh();		      
	void Update();  
	void LoadResouceFile(); 
	SDL_Texture* Load_image(std::string FilePath);
	void Init();
	void ResetGame();
	//SDL_Texture* Draw_text(std::string message);
        void Draw_text(std::string message,int x,int y);
        void GameModeChoix(SDL_Event event);
        void ModeSInit(SDL_Event event);
        void ModeIInit(SDL_Event event);
        void ModePInit(SDL_Event event);

protected:
	SDL_Window * win=NULL;
	SDL_Renderer* renderer=NULL; 
	SDL_Texture* taupe=NULL;
        SDL_Texture* bombe=NULL;
	SDL_Texture* play=NULL;
	SDL_Texture* windows=NULL;
	SDL_Texture* gameover=NULL;
        SDL_Texture* mode_s=NULL;
        SDL_Texture* mode_i=NULL;
        SDL_Texture* mode_p=NULL;

	TTF_Font* Font=NULL;
        bool gameRunning = false;
        bool quit=false;
        int Time = 60;
        char mode;
	Modesimple* simplegame;
        Modeinfinie* infiniegame;
        Modepromu* promugame;
};
