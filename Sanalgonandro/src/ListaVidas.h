#pragma once
#include"Vida.h"
#include"Lista.h"
#define MAX_VIDAS 5


class ListaVidas: public Lista<Vida,MAX_VIDAS>{

public:
	ListaVidas():Lista(){}
	~ListaVidas();
	void setpos(int i);
	void Eliminar(int n);
	void posIni() { for (int i = 0; i < num(); i++) operator[](i)->SetPos((-20 + i * 3), 40); }
	Vector2D posVida1() { return lista[0]->GetPos(); }
};

