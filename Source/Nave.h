#ifndef __NVAE_H__
#define __NVAE_H__
#include "Sprite.h"


class Nave{
	int  x;
	int  y;
	int  w;
	int  h;
	int posicionaActual;
	int posicionFinal;
	int posisiconBrinco;
	int stepsActual;
	int stepsFinal;


	Sprite * sprite;
	
public:
	Nave(SDL_Surface* screen, char *rutaImagen,int x, int y);
	

	~Nave();
	 void Pintar();

	 void Mover(int posisicon);
	 void Moverl(int posicion);
	 int obtenerX();
	 int obtenerY();
	 int obtenerW();
	 int obtenerH();
	 void Movera(int posicion);
	 void Moverab(int posicion);
	 void ponerEn(int x ,int y);
	 void Mover( int brinco, int puntoFinal);
	 void SetStep(int stepsFinal);
	 void IncrementarStep();
	 int ObtenerStepActual();
	 bool  IsRunningAnimacion();
	 void TerminarAnimacion();// Fuerza a aterminar la animacion de la nave el step
	 void Actualizar();

};

#endif

