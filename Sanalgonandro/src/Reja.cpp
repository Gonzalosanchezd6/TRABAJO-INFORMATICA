#include "Reja.h"
#include "glut.h"

Reja::~Reja() {

}


void Reja::SetRadio(float r) {
	radio = r;
}

void Reja::Dibuja() {
	reja->setPos(posicion.x, posicion.y);
	reja->draw();
}