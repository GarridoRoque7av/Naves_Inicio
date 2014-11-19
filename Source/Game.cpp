#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include "config.h"
#include "sprite.h"
#include "SDL.h"


CGame::CGame(){
	frames = 0;
	tiempoFrameInicio=0;
	estado = Estado::ESTADO_INICIANDO;
	opcion =0;
	estaSeleccionado=true;

	atexit(SDL_Quit);
}

void CGame::Iniciando(){
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);

	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN,HEIGHT_SCREEN,24,SDL_HWSURFACE | SDL_DOUBLEBUF);

	if(screen == NULL){	
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer juego", NULL);
	nave= new Nave(screen, "../Data/minave.bmp",(WIDTH_SCREEN/2),(HEIGHT_SCREEN-80),0);
	menu= new Nave(screen,"../Data/FondeMenu.bmp",0,0,1);	
	textonombre= new Nave(screen,"../Data/texto.bmp",0,0,3);	
	texnoinicio= new Nave(screen,"../Data/texto.bmp",250,120,4);
	textosalir=new Nave(screen,"../Data/texto.bmp",260,160,5);
	textoalumno=new Nave(screen,"../Data/texto.bmp",155,400,6);
	tecxtoamarilloinicio= new Nave(screen,"../Data/texto.bmp",250,120,7);
	textoamarillosalir=new Nave(screen,"../Data/texto.bmp",260,160,8);
	fondojuego =new Nave(screen,"../Data/estrellas.bmp",0,0,1); 

		

	//nave->CargarImagen("../Data/minave.bmp");
	//enemigo = new Nave (screen,"../Data/enemigo.bmp",0,0);
	enemigoArreglo = new Nave*[10];
	for (int i = 0 ; i<10; i++)
	enemigoArreglo[i]= new Nave(screen,"../Data/enemigo.bmp",i*65,0,2);
		

	//emigoParabola=-10.0f;
	//enemigo->SetStep(4);
	for ( int i=0; i<10; i++)

		enemigoArreglo[i]-> SetStep(4);

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
				estado= ESTADO_MENU;
				

				break;
	case Estado::ESTADO_MENU:	//MENU
		keys= SDL_GetKeyState(NULL);
				menu->Pintar();
				textonombre->Pintar();
				if(estaSeleccionado)
				{
					tecxtoamarilloinicio -> Pintar();
					textosalir ->Pintar();

				}
				else 
				{
					texnoinicio ->Pintar();
					textoamarillosalir->Pintar();
				}





				textoalumno->Pintar();

				if(keys[SDLK_UP]){

					estaSeleccionado = true;
					opcion = 0;
				}

				if(keys[SDLK_DOWN]){

					estaSeleccionado = false;
					opcion = 1;
				}

				if(keys[SDLK_RETURN]){

					if(opcion ==0){
						estado=ESTADO_JUGANDO;
					
					}
					else 
					{
						salirJuego= true;


					}

				}



				//estado= ESTADO_JUGANDO;
				break;
		case Estado::ESTADO_JUGANDO: //JUGANDO
				SDL_FillRect(screen, NULL,0x000000);
				fondojuego -> Pintar();
				keys=SDL_GetKeyState(NULL);
			    
					for ( int i=0; i<10; i++)
					{
						enemigoArreglo[i]-> Actualizar();
						checkCollision(nave, enemigoArreglo[i]);
					}

				MoverEnemigo();
				
				if(keys[SDLK_RIGHT]&& !esLimitePantalla(nave,BORDE_DERECHO)){

					nave->Mover(8);
				};

				if(keys[SDLK_LEFT]&& !esLimitePantalla(nave,BORDE_IZQUIERDO)){
					nave->Moverl(8);
				};

				if(keys[SDLK_UP]&& !esLimitePantalla(nave,BORDE_SUPERIOR)){
					nave->Movera(8);

					
				};
				if(keys[SDLK_DOWN]&& !esLimitePantalla(nave,BORDE_INFERIOR)){
					nave->Moverab(8);
				};
						nave->Pintar();
						
			for ( int i=0; i<10; i++)
						enemigoArreglo[i]-> Pintar();
				break;
		case Estado::ESTADO_TERMINANDO: //TERMINADO						
				break;
		case Estado::ESTADO_FINALIZANDO: //SALIR
			break;
		}
	
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT){salirJuego=true;}
			if(event.type == SDL_KEYDOWN) { }

		};

		//Este codigo esta provicionalmente aqui
		SDL_Flip(screen);
		frames++;
		tiempoFrameFinal=SDL_GetTicks();
		while (tiempoFrameFinal < (tiempoFrameInicio + FPS_DELAY))
			tiempoFrameFinal= SDL_GetTicks();
		//printf("Frame:%d  Tiempo:%d TiempoPorFrame:%d FPS:%f\n", frames, tiempoFrameInicio,tiempoFrameFinal-tiempoFrameInicio, 1000.0f/ (float)(tiempoFrameFinal-tiempoFrameInicio));


		tiempoFrameInicio = tiempoFrameFinal;


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

bool CGame::isPointInRect(int x, int y, Nave*enemigo)
{
	if(x>=enemigo->obtenerX() &&
		y>=enemigo->obtenerY() &&
		x<=enemigo->obtenerX()+enemigo->obtenerW() &&
		y<=enemigo->obtenerY()+enemigo->obtenerH())
	{
			return true;
	}
			return false;
}

bool CGame::checkCollision(Nave*nave, Nave*enemigo)
{
	
		if(isPointInRect(nave->obtenerX(),nave->obtenerY(),enemigo) == true ||
			isPointInRect(nave->obtenerX()+nave->obtenerW(),nave->obtenerY(),enemigo) == true ||
			isPointInRect(nave->obtenerX(),nave->obtenerY()+nave->obtenerH(),enemigo) == true ||
			isPointInRect(nave->obtenerX()+nave->obtenerW(),nave->obtenerY()+nave->obtenerH(),enemigo) == true
			)
			{
				printf("Collision detected\n");
				nave->resetPosition();
				nave->Pintar();
				estado=ESTADO_MENU;
				return true;
			}
		return false;
}


void CGame::MoverEnemigo(){



	
/*	enemigo->ponerEn(enemigoParabola,enemigoParabola*enemigoParabola);
	enemigoParabola+=.001f;*/
	
	for ( int i = 0; i<10; i++)
		switch(enemigoArreglo[i]-> ObtenerStepActual()){
	case 0:		
	

			if(!enemigoArreglo[i]->IsRunningAnimacion())
				enemigoArreglo[i]->Mover(1,WIDTH_SCREEN-enemigoArreglo[i]->obtenerW());
				//enemigo->IncrementarStep();
				if (esLimitePantalla(enemigoArreglo[i],BORDE_DERECHO))
			enemigoArreglo[i]->TerminarAnimacion();

			
		break;

	case 1:
		enemigoArreglo[i]->IncrementarStep();
		break;
	case 2:
		

			if(!enemigoArreglo[i]->IsRunningAnimacion())
				enemigoArreglo[i]->Mover(-1,WIDTH_SCREEN-enemigoArreglo[i]->obtenerW());
			//	enemigoArreglo[i]->IncrementarStep();
		if (esLimitePantalla(enemigoArreglo[i],BORDE_IZQUIERDO))
			enemigoArreglo[i]->TerminarAnimacion();
	

		break;

	case 3:
		enemigoArreglo[i]->IncrementarStep();

		break;



	
/*	enemigo->ponerEn(enemigoParabola,enemigoParabola*enemigoParabola);
	enemigoParabola+=.001f;*/
	}



}
