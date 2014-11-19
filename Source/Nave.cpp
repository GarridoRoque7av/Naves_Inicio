#include "Nave.h"
#include "Config.h"



Nave::Nave(SDL_Surface* screen, char * rutaImagen,  int x, int y, int module){

	moduleUsing=module;
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	sprite->borrarFondo();
	w =  sprite->WidthModule(moduleUsing);
	h = sprite->HeightModule(moduleUsing);
	this ->x=x;
	this ->y=y;
	stepsActual=0;
	posisiconBrinco=0;
	posicionaActual=0;
}


Nave::~Nave()
{
	delete sprite;
}


void Nave::Pintar()
{
	sprite->PintarModulo(moduleUsing,x,y);


}

void Nave::Pintar(int module, int x, int y )
{
	sprite->PintarModulo(module,x,y);


}

void Nave::resetPosition()
{
	x=(WIDTH_SCREEN/2);
	y=(HEIGHT_SCREEN-80);
}

void Nave::Mover(int posicion){

	x += posicion;

}

void Nave::Moverl(int posicion){

	x -= posicion;
	
}

void Nave::Movera(int posicion){
	y -=posicion;
	
}
void Nave::Moverab(int posicion){

	y+=posicion;


}

int Nave::obtenerX(){ return x;}

int Nave::obtenerY(){ return y;}

int Nave::obtenerW(){ return w;}

int Nave::obtenerH(){ return h;}


void Nave::ponerEn(int x, int y){



	this->x=x;
	this->y=y;
}

void Nave::Mover(int brinco, int puntoFinal){
		if(posisiconBrinco<=0){
	posisiconBrinco=brinco;
	posicionFinal=puntoFinal;
		}

}

void Nave::Actualizar(){
	if(posisiconBrinco!=0){
		
		if(posicionaActual<=posicionFinal){
			Mover(posisiconBrinco);
			posicionaActual++;
		}
		
		else{
			TerminarAnimacion();

		}

	}

}

void Nave::SetStep(int stepsFinal){



	this->stepsFinal=stepsFinal;


}
void Nave:: IncrementarStep(){ 
	stepsActual++;
	if(stepsActual>=stepsFinal)
		stepsActual=0;
}
int Nave::ObtenerStepActual(){ 
	
	
	return stepsActual;


}
bool Nave::IsRunningAnimacion(){



	if( posisiconBrinco==0)
		return false;
	else 
		return true;



}

void Nave::TerminarAnimacion(){
	posisiconBrinco=0;
	posicionaActual=0;
	posicionFinal=0;
	IncrementarStep();
}
