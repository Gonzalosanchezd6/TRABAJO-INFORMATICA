////////// clase base para personaje y enemigos///////////
#include"Animado.h"
Animado::Animado(){
}
Animado::Animado( float x , float y , int nvida, float vx , float vy ){
	///TO DO 
	// constructor tipico

}


Animado::~Animado(){
}

void Animado::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}


void Animado::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	vidas.Mueve(t);
}

void Animado::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void Animado::SetAc(float ax, float ay) {

	aceleracion.x = ax;
	aceleracion.y = ay;
}