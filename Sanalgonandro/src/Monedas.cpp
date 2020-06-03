#include "Monedas.h"
#include "glut.h"

Monedas::~Monedas() {

}


void Monedas::SetRadio(float r) {
	radio = r;
}

void Monedas::Dibuja() {
	moneda->setPos(posicion.x, posicion.y);
	moneda->draw();
}