#include "EnemigoLv1.h"
#include "glut.h"

Enemigo1::Enemigo1() {

}

Enemigo1::Enemigo1(float x, float y, float vx, float vy) {
	tamaño = 4;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;
	tipo = false;

	vidas = 1;

	enemigo = new ETSIDI::Sprite("imagenes/enemigomarvin.png", 2, 2, 5, 5);
}

Enemigo1::~Enemigo1() {

}

void Enemigo1::Dibuja() {

	enemigo->setPos(posicion.x, posicion.y);
	enemigo->draw();

}

void Enemigo1::Mueve(float t) {
	Animado::Mueve(t);
	enemigo->loop();
}



float Enemigo1::GetTam() {
	return tamaño;
}

void Enemigo1::restarVida() {

	vidas--;

}

int Enemigo1::GetVidas() {
	return vidas;
}