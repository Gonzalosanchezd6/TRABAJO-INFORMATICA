////////// clase base para personaje y enemigos///////////
#pragma once
#include"ListaVidas.h"
#include"Vector2D.h"

class Animado{
protected:
	ListaVidas vidas;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;



public:
	Animado();
	Animado(int nvida, float x=0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual ~Animado();
	void SetPos(float ix, float iy);
	void Mueve(float t);
	void SetVel(float vx, float vy);
	void SetAc(float ax, float ay);


};

