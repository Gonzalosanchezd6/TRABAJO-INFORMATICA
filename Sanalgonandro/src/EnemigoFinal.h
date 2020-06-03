#pragma once
#include"Animado.h"
#include "EnemigoLv1.h"
#include "Vector2D.h"
#include "ETSIDI.h"

class EnemigoFinal :public Enemigo1 {
private:
	friend class Interaccion;
	float tamaño;
	ETSIDI::Sprite* enemigofinal;

public:
	EnemigoFinal();
	EnemigoFinal(float x, float y, float vx = -15.0f, float vy = 0.0f);
	virtual ~EnemigoFinal();
	void Dibuja();
	void Mueve(float t);
	float GetTam();
};