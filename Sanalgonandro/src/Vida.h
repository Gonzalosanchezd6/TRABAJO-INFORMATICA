#pragma once
#include"Animado.h"
#include "ETSIDI.h"
class Vida: public Animado{
	friend class Interaccion;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	ETSIDI::Sprite* vida;

public:
	Vida();
	~Vida();
	Vida(float x,float y,float vx=0.0f,float vy=0.0f,float ax=0.0f,float ay=0.0f);
	void Dibuja();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
};

