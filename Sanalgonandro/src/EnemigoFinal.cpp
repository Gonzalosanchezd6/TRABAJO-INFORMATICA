#include "EnemigoFinal.h"
#include "glut.h"

EnemigoFinal::EnemigoFinal() {

}

EnemigoFinal::EnemigoFinal(float x, float y, float vx, float vy) : Enemigo1(x, y, vx, vy) {
	tamaño = 6.0;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;
	tipo = true;

	vidas = 5;

	enemigofinal = new ETSIDI::Sprite("imagenes/demoniotasmania.png", 2, 2, 5, 5);
}

EnemigoFinal::~EnemigoFinal() {

}

void EnemigoFinal::Dibuja() {

	enemigofinal->setPos(posicion.x, posicion.y);
	enemigofinal->draw();

}

void EnemigoFinal::Mueve(float t) {
	Animado::Mueve(t);
	enemigofinal->loop();
}



float EnemigoFinal::GetTam() {
	return tamaño;
}