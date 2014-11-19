#include <SDL.h>
#include <SDL_image.h>
#include "Nave.h"




class CGame
{
public:

	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO,
	};

	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();


private:
	void Iniciando();
	void MoverEnemigo();
	bool esLimitePantalla(Nave*objeto, int bandera);
	bool isPointInRect(int x, int y,Nave*enemigo);
	bool checkCollision(Nave*objeto, Nave*enemigo);
	bool estaSeleccionado;
	int opcion;
	
Uint8*keys;
SDL_Event event;
SDL_Surface *screen;
Nave  *nave;
//Nave *enemigo;
Nave**enemigoArreglo;
Nave *menu;
Nave *texto;
Nave *fondo;
Nave * textonombre;
Nave * texnoinicio;
Nave * textosalir;
Nave * textoalumno;
Nave* tecxtoamarilloinicio;
Nave * textoamarillosalir;
Nave * fondojuego;





	Estado estado;
	float  enemigoParabola;
	unsigned int frames;
	unsigned int tiempoFrameInicio;
	unsigned int tiempoFrameFinal;

};