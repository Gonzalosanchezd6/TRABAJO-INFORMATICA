#pragma once
#include"EnemigoLv1.h"
#include"Hombre.h"
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
	void mueve(float t);
	void dibuja();
	Enemigo1* Choque(Hombre h);
	

};

