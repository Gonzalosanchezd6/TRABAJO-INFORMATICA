#pragma once
#define MAX_DISPAROS 1
#include "Disparo.h"
#include"Lista.h"


class ListaDisparos : public Lista<Disparo, MAX_DISPAROS> {
public:
	ListaDisparos() :Lista() {}
	virtual ~ListaDisparos();
	void Dibuja();
	bool GetEsp(Disparo* d) { return d->GetEsp(); }
};