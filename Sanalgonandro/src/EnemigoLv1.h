#pragma once
#include "Vector2D.h"

class Enemigo1 {
private:
	friend class Interaccion;
	float tamaño;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Enemigo1();
	Enemigo1(float x, float y);
	virtual ~Enemigo1();
	void SetPos(float ix, float iy);
	void Dibuja();
	void Mueve(float t);
	void SetVel(float vx, float vy);
	Vector2D GetPos() { return posicion; }
};
