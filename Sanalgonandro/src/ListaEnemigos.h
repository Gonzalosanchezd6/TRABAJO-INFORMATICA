#pragma once
#include"EnemigoLv1.h"
#include"Hombre.h"
#include "ListaPlataformas.h"
#define MAX_ENEMIG 10

class ListaEnemigos{
	Enemigo1* lista[MAX_ENEMIG];
	int numero;

public:
	ListaEnemigos();
	~ListaEnemigos();

	bool agregar(Enemigo1* e);
	void destruirContenido();
	void Eliminar(Enemigo1* e);
	void Eliminar(int index);
	void Mueve(float t);
	void Dibuja();
	int num() { return numero; }
	Enemigo1* Choque(Hombre h);
	Enemigo1* colision(ListaPlataformas l);
	Enemigo1* ListaEnemigos::operator[](int i);

};

