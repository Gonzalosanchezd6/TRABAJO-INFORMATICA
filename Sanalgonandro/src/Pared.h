#pragma once
#include "Vector2D.h"

class Pared {
private:
	friend class Interaccion;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;
public:
	Pared();
	virtual ~Pared();
	void Dibuja();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float lim1x, float lim1y, float lim2x, float lim2y);
	float distancia(Vector2D punto, Vector2D *direccion = 0);
};