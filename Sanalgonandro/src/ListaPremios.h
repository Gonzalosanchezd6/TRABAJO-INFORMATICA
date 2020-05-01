#pragma once
#define MAX_LLAVES 3
#include "Llave.h"
#include "Hombre.h"

class ListaPremios {
private:
	Llave* lista[MAX_LLAVES];
	int num_llave;

public:
	ListaPremios();
	virtual ~ListaPremios();

	bool agregar(Llave* l);
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(Llave* l);
	//void Mueve(float t);
	void Dibuja();

	Llave* colision(Hombre& h);
};
