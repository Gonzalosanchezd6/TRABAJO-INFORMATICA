#pragma once
#include "Pared.h"

class Caja {
private:
	friend class Interaccion;

	Pared inferior1;
	Pared inferior2;
	Pared plataforma1;
	Pared plataforma2;
	Pared plataforma3;
	Pared plataforma4;
public:
	Caja();
	virtual ~Caja();
	void Dibuja();
};