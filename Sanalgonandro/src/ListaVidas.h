#pragma once
#include"Vida.h"


#define MAX_VIDAS 20


class ListaVidas{
	Vida* lista[MAX_VIDAS];
	int numero;

public:
	ListaVidas();
	~ListaVidas();
	
	bool Agregar(Vida* v);
	void Dibuja();
	void Mueve(float t);
	//Vida* Colision(Hombre& h);
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(Vida* v);
	int nVidas() { return numero; }
	void setpos(int i);

};

