#pragma once

#include "Vector2D.h"


class Bloque {
private:
	float lado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Bloque();
	virtual ~Bloque();
	void Dibuja();
	void Mueve(float t);
	void SetPos(float ix, float iy);
	void SetVel(float vx, float vy);
};


