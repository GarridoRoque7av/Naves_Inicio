#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Config.h"




CGame::CGame(){
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);

}
void CGame::Iniciando()
{

	if (SDL_Init( SDL_INIT_VIDEO )<0){

printf("Error %s ", SDL_GetError());

exit(EXIT_FAILURE);


}

screen = SDL_SetVideoMode( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_SWSURFACE );
if (screen == NULL){

printf("Error %s ", SDL_GetError());

exit(EXIT_FAILURE);

}

SDL_WM_SetCaption( "Mi primer Juego", NULL );


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
			case Estado::ESTADO_INICIANDO: //INICIALIZAR
			//	CGame::Iniciando();
					Iniciando();
				{

			//	nave= SDL_LoadBMP("../Data/Minave.bmp");	
				nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
				SDL_Rect fuente;
				fuente.x = 90;
				fuente.y = 152;
				fuente.w = 242;
				fuente.h = 76;
				SDL_Rect destino;
				destino.x =100;
				destino.y =100;
				destino.w =100;
				destino.h =100;
				SDL_BlitSurface(nave, &fuente, screen, &destino);
				SDL_FreeSurface(nave);



				}

			break;
			case Estado::ESTADO_MENU: //MENU
			break;
			case Estado::ESTADO_JUGANDO:	//JUGAR	
			break;	
			case Estado::ESTADO_TERMINANDO: //SALIR
		
			break;
		    case Estado::ESTADO_FINALIZANDO:	//FINALIZAR	
						salirJuego = true;
			break;

		};
		//Este codigo estara provicionalmente aqui.

SDL_Flip(screen);
		

    }
	return true;
}
