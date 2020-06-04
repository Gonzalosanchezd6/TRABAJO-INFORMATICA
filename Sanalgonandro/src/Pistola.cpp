#include "Pistola.h"
#include "ETSIDI.h"
#include "glut.h"



Pistola::~Pistola() {

}

void Pistola::SetPis(float r) {
	radio = r;
}

void Pistola::Dibuja() {
	pistola->setPos(posicion.x, posicion.y);
	pistola->draw();
}
