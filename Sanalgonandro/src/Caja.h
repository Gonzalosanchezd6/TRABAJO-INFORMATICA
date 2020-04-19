#pragma once
#include "Pared.h"

class Caja {
private:
	friend class Interaccion;

	Pared superior;
	Pared derecha;
	Pared inferior;
	Pared izquierda;
public:
	Caja();
	virtual ~Caja();
	void Dibuja();
};