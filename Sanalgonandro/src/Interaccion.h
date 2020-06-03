#pragma once
#include "Hombre.h"
#include "EnemigoLv1.h"
#include "Premios.h"
#include "EnemigoBolas.h"
#include "Puerta.h"
#include"Vida.h"
#include"Disparo.h"
#include "ListaPlataformas.h"


class Interaccion {
public:
	Interaccion();
	virtual ~Interaccion();
	static void rebote(Hombre &h, Pared p);
	static bool colision(Pared p, Hombre h);
	static bool Choque(Hombre h, Enemigo1 *e);
	static bool Choque(Hombre h, Premio *l);
	static bool Choque(Hombre h, EnemigoBolas *b);
	//static bool Choque(Hombre h, Puerta p);
	static bool colision(Vida v, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Enemigo1 e);
	static bool colision(Pared p, EnemigoBolas b);
	static bool colision(Pared p, Enemigo1 e);
};