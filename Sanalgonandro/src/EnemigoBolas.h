#pragma once
#include "Animado.h"
#include "ETSIDI.h"
class EnemigoBolas:public Animado {

private:
	friend class Interaccion;

	float radio;
	//Vector2D posicion;
	//Vector2D velocidad;
	//Vector2D aceleracion;

	ETSIDI::Sprite* fuego;


public:
	EnemigoBolas();
	virtual ~EnemigoBolas();
	EnemigoBolas(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	//void SetPos(float ix, float iy);
	void Dibuja();
	void Mueve(float t);
	//void SetAc(float ax, float ay);
	//void setVel(float vx, float vy);

	

};



