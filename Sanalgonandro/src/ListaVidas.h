#pragma once
#include"Vida.h"
#define MAX_VIDAS 20


//class ListaVidas: public Lista<Vida,MAX_VIDAS>{
class ListaVidas{
	Vida* lista[MAX_VIDAS];
	int numero;
public:
	ListaVidas():numero(0){}
	~ListaVidas();
	bool agregar(Vida* v);
	void Dibuja();
	void Mueve(float t);
	//Vida* Colision(Hombre& h);
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(Vida* v);
	int num() { return numero; }
	void setpos(int i);

};

