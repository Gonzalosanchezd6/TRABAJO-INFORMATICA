#include "Enemigo2vidas.h"
#include "glut.h"

Enemigo2vidas::Enemigo2vidas() {

}

Enemigo2vidas::Enemigo2vidas(float x, float y, float vx, float vy) : Enemigo1(x, y, vx, vy) {
	tamaño = 2;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;
	tipo = false;

	vidas = 2;

	enemigo2vidas = new ETSIDI::Sprite("imagenes/enemigo2.png", 2, 2, 5, 5);
}

Enemigo2vidas::~Enemigo2vidas() {

}

void Enemigo2vidas::Dibuja() {

	enemigo2vidas->setPos(posicion.x, posicion.y);
	enemigo2vidas->draw();

}

void Enemigo2vidas::Mueve(float t) {
	Animado::Mueve(t);
	enemigo2vidas->loop();
}