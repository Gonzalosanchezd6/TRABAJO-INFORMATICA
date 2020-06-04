#include "PremioVida.h"
#include "ETSIDI.h"
#include "glut.h"



PremioVida::~PremioVida() {

}

void PremioVida::Dibuja() {

	premioVida->setPos(posicion.x, posicion.y);
	premioVida->draw();
}