#include "sprite.h"
#include "SDL.h"


void Sprite::CargarImagen(char * ruta){
		image= SDL_LoadBMP(ruta);
	}

Sprite::Sprite(SDL_Surface * screen){
	this->screen = screen;

};

Sprite::~Sprite(){
	SDL_FreeSurface(image);
};

//void Sprite::PintarModulo(int id, int x, int y, int w, int h){
//	SDL_Rect src;
	//src.x= x;
	//src.y=y;
	//src.w=w;
	//src.h=h;

	//SDL_BlitSurface(image,&src, screen, NULL);
//};



void  Sprite::PintarModulo(int id, int x ,int y){
		SDL_Rect src;
		src.x= spriteDef.modulos[id].x;
        src.y=spriteDef.modulos[id].y;;
	    src.w=spriteDef.modulos[id].w;
     	src.h=spriteDef.modulos[id].h;;
			SDL_Rect dest;

			dest.x=x;
			dest.y=y;

	SDL_BlitSurface(image,&src, screen, &dest);

}
	int Sprite::WidthModule(int id)
	{
		return spriteDef.modulos[id].w;
	
	}

	int Sprite::HeightModule(int id ){
	return spriteDef.modulos[id].h;
	

	
	
	
	}

