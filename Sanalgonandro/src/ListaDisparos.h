#pragma once
#define MAX_DISPAROS 10
#include "Disparo.h"
#include"Pared.h"
#include"EnemigoLv1.h"

class ListaDisparos {
public:
	ListaDisparos();
	virtual ~ListaDisparos();
	bool agregar(Disparo* d);
	void destruirContenido();
	void Eliminar(Disparo* d);
	void Eliminar(int index);
	void mueve(float t);
	void dibuja();
	Disparo* colision(Pared p);
	Disparo* colision(Enemigo1 e);
	int num() { return numero; }

private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
};