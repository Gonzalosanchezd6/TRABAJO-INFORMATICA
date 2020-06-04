#pragma once
#define MAX_PREMIOS 100
#include"Lista.h"
#include "Premios.h"

class ListaPremios :public Lista<Premio, MAX_PREMIOS> {
private:
	int num_llaves;
	int num_monedas;
	int num_disp_espec;
	int num_vidas;

public:
	ListaPremios():Lista(), num_llaves(0), num_monedas(0), num_disp_espec(0), num_vidas(0) {}
	virtual ~ListaPremios();
	void Eliminar(Premio* l);
	Premio* colision(Hombre& h);
	void reset(int n_llave, int n_moneda);
	Premio* buscar(Premio::objetos o);
	void SetLibertad(Premio* p, bool lib);
	int GetNumPrem(Premio::objetos o);

	void reiniciar();
};
