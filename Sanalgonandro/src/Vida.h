#pragma once
#include"Vector2D.h"
#include "ETSIDI.h"
class Vida{
	friend class Interaccion;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	ETSIDI::Sprite* vida;

public:

	Vida();
	~Vida();
	Vida(float x,float y,float vx=0.0f,float vy=0.0f,float ax=0.0f,float ay=0.0f);
	void Dibuja();
	void SetPos(float ix, float iy);
	void Mueve(float t);
	void SetVel(float vx, float vy);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	Vector2D GetPos() { return posicion; }
};

