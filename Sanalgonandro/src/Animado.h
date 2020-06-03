////////// clase base para personaje y enemigos///////////
#pragma once
#include"Vector2D.h"

class Animado{
protected:
	int vidas;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;



public:
	Animado();
	Animado( float x, float y , int nvida=1, float vx = 0.0f, float vy = 0.0f);
	virtual ~Animado();
	void SetPos(float ix, float iy);
	void Mueve(float t);
	void SetVel(float vx, float vy);
	void SetAc(float ax, float ay);
	Vector2D GetPos() { return posicion; }
	Vector2D GetVel() { return velocidad; };

};

