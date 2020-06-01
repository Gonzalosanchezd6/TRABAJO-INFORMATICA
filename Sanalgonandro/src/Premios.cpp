#include "Premios.h"

Premio::~Premio() {
}

void Premio::SetPos(float x, float y) {
	this->posicion.x = x;
	this->posicion.y = y;
}

bool operator==(const Premio& l1, const Premio& l2) {
	if (l1.posicion == l2.posicion) {
		return true;
	}
	return false;
}