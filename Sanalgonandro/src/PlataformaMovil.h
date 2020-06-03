#pragma once

#include "Pared.h"
#include "Animado.h"

class PlatMovil : public Pared, public Animado {

protected:
	int mov = 0;
	Vector2D origen;
public:
	PlatMovil(float x1, float y1, float x2, float y2);
	void dibuja();
	void Mueve(float t);
};
