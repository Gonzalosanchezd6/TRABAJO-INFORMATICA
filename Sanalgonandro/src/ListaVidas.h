#pragma once
#include"Vida.h"
#include"Lista.h"
#define MAX_VIDAS 20


class ListaVidas: public Lista<Vida,MAX_VIDAS>{

public:
	ListaVidas():Lista(){}
	~ListaVidas();
	void setpos(int i);
	void Eliminar(int n);
};

