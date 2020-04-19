#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"

class Interaccion {
public:
	Interaccion();
	virtual ~Interaccion();
	static void rebote(Hombre &h, Caja c);
	static bool rebote(Esfera &e, Pared p);
	static void rebote(Esfera &e, Caja c);
	//static bool rebote(Esfera &esfera1, Esfera &esfera2);
	static void rebote(Esfera &esfera1, Esfera &esfera2);
};