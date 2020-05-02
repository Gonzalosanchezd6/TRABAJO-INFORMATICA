#pragma once

#define MAX_PLATAFORMAS 200

#include "Pared.h"
#include "Hombre.h"

class ListaPlataformas {
public:
	ListaPlataformas();
	virtual ~ListaPlataformas();
	bool Agregar(Pared* p);
	void Dibuja();
	Pared* Colision(Hombre& h);
private:
	Pared* lista[MAX_PLATAFORMAS];
	int numero;
};
