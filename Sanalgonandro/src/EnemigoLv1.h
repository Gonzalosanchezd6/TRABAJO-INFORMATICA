#pragma once
#include"Animado.h"
#include "Vector2D.h"
#include "ETSIDI.h"

class Enemigo1:public Animado {
private:
	friend class Interaccion;
	float tama�o;
	ETSIDI::Sprite* enemigo;

public:
	Enemigo1();
	Enemigo1(float x, float y, float vx=-15.0f, float vy=0.0f);
	virtual ~Enemigo1();
	void Dibuja();
	void Mueve(float t);
	float GetTam();
};
