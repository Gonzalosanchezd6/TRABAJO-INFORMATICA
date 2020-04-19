#include "Caja.h"
#include "glut.h"

Caja::Caja() {
	derecha.SetPos(10, 15, 10, 0);
	izquierda.SetPos(-10, 0, -10, 15);
	superior.SetPos(-10, 15, 10, 15);
	inferior.SetPos(-10, 0, 10, 0);
	inferior.SetColor(0, 100, 0);
	derecha.SetColor(0, 150, 0);
	izquierda.SetColor(0, 150, 0);
	superior.SetColor(0, 100, 0);
}

Caja::~Caja() {
	//Monti tio bueno
}

void Caja::Dibuja() {
	inferior.Dibuja();
	superior.Dibuja();
	izquierda.Dibuja();
	derecha.Dibuja();
}