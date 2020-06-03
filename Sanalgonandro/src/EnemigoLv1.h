#pragma once
#include"Animado.h"
#include "Vector2D.h"
#include "ETSIDI.h"

class Enemigo1 :public Animado {
protected:
	friend class Interaccion;
	float tamaño;
	ETSIDI::Sprite* enemigo;

public:
	Enemigo1();
	Enemigo1(float x, float y, float vx = -15.0f, float vy = 0.0f);
	virtual ~Enemigo1();
	virtual void Dibuja();
	void Mueve(float t);
	float GetTam();
	virtual void restarVida();
	virtual int GetVidas();
};
