#pragma once
#include"EnemigoLv1.h"
#include "ListaPlataformas.h"
#include"Lista.h"
#define MAX_ENEMIG 10

class ListaEnemigos: public Lista<Enemigo1,MAX_ENEMIG>{
	//Enemigo1* lista[MAX_ENEMIG];
	//int numero;

public:
	ListaEnemigos() :Lista() {}
	~ListaEnemigos();
	void Dibuja();
	Enemigo1* colision(ListaPlataformas l);


};

