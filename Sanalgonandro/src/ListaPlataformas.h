#pragma once

#define MAX_PLATAFORMAS 200

#include "Pared.h"
#include "Hombre.h"
#include "EnemigoLv1.h"
#include "ListaBolas.h"

class ListaPlataformas {
public:
	ListaPlataformas();
	virtual ~ListaPlataformas();
	bool Agregar(Pared* p);
	void Dibuja();
	void Mueve(float t);
	Pared* colision(Hombre& h);
	static bool colision(ListaPlataformas l, Enemigo1 e);
	//Pared* colision(Enemigo1& e);
	int getNum() { return numero; }
	Pared* operator [](int i);
private:
	Pared* lista[MAX_PLATAFORMAS];
	int numero;
};
