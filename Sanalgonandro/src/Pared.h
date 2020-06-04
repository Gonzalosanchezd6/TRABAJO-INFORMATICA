#pragma once
#include "Vector2D.h"

class Pared {
protected:
	friend class Interaccion;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;
public:
	Pared(float x1, float y1, float x2, float y2);
	virtual ~Pared();
	virtual void Dibuja();
	virtual void Mueve(float t);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float lim1x, float lim1y, float lim2x, float lim2y);
	float distancia(Vector2D punto, Vector2D *direccion = 0);
	Vector2D GetPos() { return limite1; };
	Vector2D GetPos(int num);
};