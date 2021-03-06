#pragma once
#include "EnemigoBolas.h"
#include"ListaPlataformas.h"
#define MAX_BOLAS 100


class ListaBolas {
private:
	EnemigoBolas* lista[MAX_BOLAS];
	int numero;
	float random = 0;
public:
	ListaBolas();
	virtual ~ListaBolas();
	bool agregar(EnemigoBolas* e);
	void Dibuja();
	void Mueve(float t);
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(EnemigoBolas* e);
	int num() { return numero; }
	EnemigoBolas* colision(Hombre& h);
	EnemigoBolas* operator [](int i);
	EnemigoBolas* colision(ListaPlataformas& p);
	bool Crear(float t);

};



