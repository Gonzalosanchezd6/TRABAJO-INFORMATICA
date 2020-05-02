#pragma once
#include "Vector2D.h"

class Disparo {
private:
	float radio;
	float origen;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Disparo();
	virtual ~Disparo();
	void Dibuja();
	void Mueve(float t);
	void SetPos(float ix, float iy);
};