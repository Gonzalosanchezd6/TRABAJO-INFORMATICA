#pragma once
#include "Vector2D.h"

class Hombre {
private:
	friend class Interaccion;

	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Hombre();
	virtual ~Hombre();
	void SetAltura(float r);
	void SetPos(float ix, float iy);
	void Dibuja();
	void Mueve(float t);
	void SetVel(float vx, float vy);
	void Salto();
	void SetAc(float ax, float ay);
};