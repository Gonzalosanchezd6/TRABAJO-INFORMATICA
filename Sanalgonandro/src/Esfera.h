#pragma once
#include "Vector2D.h"

class Esfera {
private: 
	friend class Interaccion;

	float radio;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Esfera();
	virtual ~Esfera();
	void SetRadio(float r);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
	void Dibuja();
	void Mueve(float t);
	void SetVel(float vx, float vy);
};
