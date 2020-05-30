#pragma once
#define MAX_DISPAROS 10
#include "Disparo.h"
#include"Lista.h"


class ListaDisparos : public Lista<Disparo, MAX_DISPAROS> {
public:
	ListaDisparos() :Lista(){}
	virtual ~ListaDisparos();
	void Dibuja();
};