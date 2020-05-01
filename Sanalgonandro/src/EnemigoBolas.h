#pragma once
#include "Vector2D.h"

class EnemigoBolas {

private:
	friend class Interaccion;

	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	EnemigoBolas();
	virtual ~EnemigoBolas();
	void SetPos(float ix, float iy);
	void Dibuja();
	void Mueve(float t);
	void SetAc(float ax, float ay);

};



