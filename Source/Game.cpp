#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include "config.h"
#include "sprite.h"

CGame::CGame(){
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);
}

void CGame::Iniciando(){
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN,HEIGHT_SCREEN,24,SDL_SWSURFACE);

	if(screen == NULL){	
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer juego", NULL);
	nave= new Nave(screen,"../Data/minave.bmp");
	//nave->CargarImagen("../Data/minave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
				Iniciando();
				estado= ESTADO_MENU;
			break; 
		case Estado::ESTADO_MENU:	//MENU	
			SDL_FillRect(screen, NULL, 0XFF000000);

			keys = SDL_GetKeyState(NULL);
				if(keys[SDLK_RIGHT])
				{
					nave->Mover(1);
				}
					keys = SDL_GetKeyState(NULL);
				if(keys[SDLK_LEFT])
				{
					nave->Moverl(1);
				}

				nave-> Pintar();

			//nave->PintarModulo(0,0,0,64,64);
			//nave->PintarModulo(0,0,0);

			break;
		case Estado::ESTADO_JUGANDO: //JUGANDO	
			break;
		case Estado::ESTADO_TERMINANDO: //TERMINADO
			break;
		case Estado::ESTADO_FINALIZANDO: //SALIR
				salirJuego = true;
			break;
		};

		while (SDL_PollEvent(&event))// aqui sdl creara una lista de eventos 
		{
			if(event.type== SDL_QUIT){salirJuego=true;}//si se detecta una 
			if(event.type== SDL_KEYDOWN){}
			}

		//Este codigo esta provicionalmente aqui
		SDL_Flip(screen);
    }
	return true;
}