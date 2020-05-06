#pragma once
#include"Animado.h"
#include "Vector2D.h"

class Enemigo1:public Animado {
private:
	friend class Interaccion;
	float tama�o;

public:
	Enemigo1();
	Enemigo1(float x, float y, float vx=-15.0f, float vy=0.0f);
	virtual ~Enemigo1();
	void Dibuja();
	void Mueve(float t);

	Vector2D GetPos();
	float GetTam();
	Vector2D GetVel();
	void SetVel(float vx, float vy);
};
