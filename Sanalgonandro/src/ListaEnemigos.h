#pragma once
#include"EnemigoLv1.h"
#include "ListaPlataformas.h"
#include"Lista.h"
#define MAX_ENEMIG 10

class ListaEnemigos : public Lista<Enemigo1, MAX_ENEMIG> {
public:
	ListaEnemigos() :Lista() {}
	~ListaEnemigos();
	void Dibuja();
	Enemigo1* colision(ListaPlataformas l);
	int GetVidas(Enemigo1* e) { return e->GetVidas(); }
	void restarVida(Enemigo1* e) { e->restarVida(); }
};

