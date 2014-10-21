#include <SDL.h>
#include "SpriteDef.h"


#ifndef __SPRITE_H__
#define __SPRITE_H__


class Sprite{
	SDL_Surface *image;
	SDL_Surface *screen;
	SpriteDef spriteDef;

public:
	void CargarImagen(char * ruta);
	//void PintarModulo(int id, int x, int y, int w, int h);
	void PintarModulo(int id, int x, int y);

	Sprite(SDL_Surface * screen);
	~Sprite();
	int WidthModule(int id);
	int HeightModule(int id);

};

#endif