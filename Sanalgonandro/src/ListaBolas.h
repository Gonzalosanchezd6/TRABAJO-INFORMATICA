#pragma once
#include "EnemigoBolas.h"
#include "Interaccion.h"

#define MAX_BOLAS 10000


class ListaBolas {
private:
	EnemigoBolas* lista[MAX_BOLAS];
	int numero;
public:
	ListaBolas();
	virtual ~ListaBolas();

	bool agregar(EnemigoBolas* e);
	void dibuja();
	void mueve(float t);


	void destruirContenido();
	void eliminar(int index);
	void eliminar(EnemigoBolas* e);

	EnemigoBolas* colision(Hombre& h);
	EnemigoBolas* operator [](int i);

	int getNumero() { return numero; }
};
