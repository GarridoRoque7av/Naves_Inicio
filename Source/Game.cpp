#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include "config.h"

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
	nave= new Nave(screen, "../Data/nave.jpg",(WIDTH_SCREEN/2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/);

	//nave->CargarImagen("../Data/minave.bmp");
	enemigo = new Nave (screen,"../Data/enemigo.bmp",0,0);
	//emigoParabola=-10.0f;
	enemigo->SetStep(4);

}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	
	int salirJuego = false;
	int opc = 1;

	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
				Iniciando();
			
			//printf("\n1. ESTADO_INICIANDO");
			
			estado= ESTADO_MENU;
				break;
	case Estado::ESTADO_MENU:	//MENU
		SDL_FillRect(screen, NULL,0x000000);
				keys=SDL_GetKeyState(NULL);
				MoverEnemigo();
				enemigo->Actualizar();
				if(keys[SDLK_RIGHT]&& !esLimitePantalla(nave,BORDE_DERECHO)){

					nave->Mover(1);
				};

				if(keys[SDLK_LEFT]&& !esLimitePantalla(nave,BORDE_IZQUIERDO)){
					nave->Moverl(1);
				};

				if(keys[SDLK_UP]&& !esLimitePantalla(nave,BORDE_SUPERIOR)){
					nave->Movera(1);

					
				};
				if(keys[SDLK_DOWN]&& !esLimitePantalla(nave,BORDE_INFERIOR)){
					nave->Moverab(1);
				};
						nave->Pintar();
				enemigo -> Pintar();
		

			/*	printf("\n2. ESTADO_MENU");

				if(opc == 1)
					estado= ESTADO_JUGANDO;
				else
					estado= ESTADO_FINALIZANDO;*/
				
				break;
		case Estado::ESTADO_JUGANDO: //JUGANDO
				
			/*
				printf("\n3. ESTADO_JUGANDO");
				estado= ESTADO_TERMINANDO;*/
				
				break;
		case Estado::ESTADO_TERMINANDO: //TERMINADO
			
		/*		printf("\n4. ESTADO_TERMINADO");
				opc =2;
				estado=ESTADO_MENU;*/
				
				break;
		case Estado::ESTADO_FINALIZANDO: //SALIR
				
				/*printf("\n5. ESTADO_FINALIZADO");
				getchar();
				opc =1;
				salirJuego = true;*/
			break;
		}
	
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT){salirJuego=true;}
			if(event.type == SDL_KEYDOWN) { }

		};

		//Este codigo esta provicionalmente aqui
		SDL_Flip(screen);

    }

	return true;

}

bool CGame::esLimitePantalla(Nave*objeto, int bandera)
{
	if (bandera & BORDE_IZQUIERDO)
	if(objeto->obtenerX() <=0)
		return true;
		if (bandera & BORDE_SUPERIOR)
	if(objeto ->obtenerY() <=0)
		return true;
				if (bandera & BORDE_DERECHO)
	if (objeto->obtenerX()>=(WIDTH_SCREEN-objeto->obtenerW()))
		return true;
				if (bandera & BORDE_INFERIOR)
	if(objeto ->obtenerY()>=(HEIGHT_SCREEN-objeto->obtenerH()))
		return true;
	return false;



}


void CGame::MoverEnemigo(){

// if (!esLimitePantalla(enemigo,BORDE_DERECHO))

	switch(enemigo-> ObtenerStepActual()){
	case 0:		

			if(!enemigo->IsRunningAnimacion())
				enemigo->Mover(1,WIDTH_SCREEN-enemigo->obtenerW());
				//enemigo->IncrementarStep();
			
		break;

	case 1:
		enemigo->IncrementarStep();
		break;
	case 2:
			if(!enemigo->IsRunningAnimacion())
				enemigo->Mover(-1,WIDTH_SCREEN-enemigo->obtenerW());
			//	enemigo->IncrementarStep();
		
	

		break;

	case 3:
		enemigo->IncrementarStep();

		break;



	
/*	enemigo->ponerEn(enemigoParabola,enemigoParabola*enemigoParabola);
	enemigoParabola+=.001f;*/
	}


}
