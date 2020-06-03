#include "Llave.h"
#include "ETSIDI.h"
#include "glut.h"
 


Llave::~Llave() {

}

void Llave::SetLlave(float r1, float r2) {
	rad_int = r1;
	rad_ext = r2;
}

void Llave::Dibuja() {

	llave->setPos(posicion.x, posicion.y);
	llave->draw();
}

bool operator==(const Llave& l1, const Llave& l2) {
	if (l1.rad_ext == l2.rad_ext && l1.rad_int == l2.rad_int && l1.posicion == l2.posicion) {
		return true;
	}
	return false;
}
