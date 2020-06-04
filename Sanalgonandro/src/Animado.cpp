////////// clase base para personaje y enemigos///////////
#include"Animado.h"
Animado::Animado(){
	posicion.x = posicion.y = vidas = velocidad.x = velocidad.y = 0;
}
Animado::Animado( float x , float y , int nvida, float vx , float vy ){
	SetPos(x,y);
	SetVel(vx, vy);
	vidas = nvida;
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