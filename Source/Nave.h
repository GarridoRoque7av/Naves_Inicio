#ifndef __NVAE_H__
#define __NVAE_H__
#include "Sprite.h"


class Nave{
	int  x;
	int  y;

	Sprite * sprite;
	
public:
	Nave(SDL_Surface* screen, char *rutaImagen);
	

	~Nave();
	 void Pintar();

	 void Mover(int posisicon);
	 void Moverl(int posicion);

};

#endif

