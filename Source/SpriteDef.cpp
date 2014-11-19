//este es el bueno que esta en suoruce

#include "SpriteDef.h"
#include "config.h"

SpriteDef::SpriteDef(){
	modulos[0].id=0;
	modulos[0].x=0;
	modulos[0].y=0;
	modulos[0].w=64;
	modulos[0].h=64;

	modulos[1].id=1;
	modulos[1].x=0;
	modulos[1].y=0;
	modulos[1].w=WIDTH_SCREEN;
	modulos[1].h=HEIGHT_SCREEN;

	modulos[2].id=2;
	modulos[2].x=0;
	modulos[2].y=0;
	modulos[2].w=54;
	modulos[2].h=61;

	//texto nombre
	modulos[3].id=3;
	modulos[3].x=18;
	modulos[3].y=37;
	modulos[3].w=617;
	modulos[3].h=86;

	//texto nombre inicil
	modulos[4].id=4;
	modulos[4].x=92;
	modulos[4].y=141;
	modulos[4].w=128;
	modulos[4].h=42;

	//texto nombresalir
	modulos[5].id=5;
	modulos[5].x=93;
	modulos[5].y=187;
	modulos[5].w=100;
	modulos[5].h=39;
	
//texto nombrealumno
	modulos[6].id=6;
	modulos[6].x=86;
	modulos[6].y=327;
	modulos[6].w=350;
	modulos[6].h=39;
		
//texto nombrealumno
	modulos[7].id=7;
	modulos[7].x=99;
	modulos[7].y=238;
	modulos[7].w=121;
	modulos[7].h=38;

		
//texto nombrealumno
	modulos[8].id=6;
	modulos[8].x=96;
	modulos[8].y=279;
	modulos[8].w=95;
	modulos[8].h=34;

}

