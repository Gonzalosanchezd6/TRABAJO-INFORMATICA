#pragma once
#include"Animado.h"
#include "EnemigoLv1.h"
#include "Vector2D.h"
#include "ETSIDI.h"

class Enemigo2vidas :public Enemigo1 {
private:
	friend class Interaccion;
	ETSIDI::Sprite* enemigo2vidas;

public:
	Enemigo2vidas();
	Enemigo2vidas(float x, float y, float vx = -15.0f, float vy = 0.0f);
	virtual ~Enemigo2vidas();
	void Dibuja();
	void Mueve(float t);
};