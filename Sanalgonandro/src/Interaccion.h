#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "EnemigoLv1.h"
#include "Llave.h"
#include "EnemigoBolas.h"
#include "Puerta.h"
#include"Vida.h"

class Interaccion {
public:
	Interaccion();
	virtual ~Interaccion();
	static void rebote(Hombre &h, Pared p);
	static bool rebote(Esfera &e, Pared p);
	//static void rebote(Hombre &h, Caja c);
	//static bool rebote(Esfera &esfera1, Esfera &esfera2);
	static void rebote(Esfera &esfera1, Esfera &esfera2);
	static bool Colision(Pared p, Hombre h);
	static bool Choque(Hombre h, Enemigo1 e);
	static bool Choque(Hombre h, Llave l);
	static bool Choque(Hombre h, EnemigoBolas b);

	//static bool Choque(Hombre h, Puerta p);

	static bool colision(EnemigoBolas e, Hombre h);
	static bool colision(Vida v, Hombre h);
};