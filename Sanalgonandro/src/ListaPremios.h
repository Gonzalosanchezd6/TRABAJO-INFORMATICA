#pragma once
#define MAX_PREMIOS 100
//#include "Llave.h"
//#include "Hombre.h"
#include"Lista.h"
#include "Premios.h"

class ListaPremios :public Lista<Premio, MAX_PREMIOS> {
private:
	Premio* lista[MAX_PREMIOS];
	int num_premio;

public:
	ListaPremios();
	virtual ~ListaPremios();

	bool agregar(Premio* l);
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(Premio* l);
	//void Mueve(float t);
	void Dibuja();

	Premio* colision(Hombre& h);
};
