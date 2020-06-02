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
	int num_llaves;
	int num_monedas;

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
	void reset(int n_llave, int n_moneda);
	Premio* buscar(Premio::objetos o);
	void SetLibertad(Premio* p, bool lib);
};
