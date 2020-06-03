#pragma once
#include "Animado.h"

class Bonus: public Animado{
private:
	float lado;
public:
	Bonus();
	virtual ~Bonus();
	void Dibuja();
};