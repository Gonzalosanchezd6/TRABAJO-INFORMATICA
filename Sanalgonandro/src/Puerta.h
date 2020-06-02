#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Pared.h"

class Puerta: public Pared{
//private:
//	unsigned char rojo;
//	unsigned char verde;
//	unsigned char azul;
//	Vector2D limite1;
//	Vector2D limite2;
	ETSIDI::Sprite* puerta;
public:
	Puerta(float x1 = 0.0f, float y1 = 0.0f, float x2 = 0.0f, float y2 = 0.0f);

	virtual ~Puerta();
	void Dibuja();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float lim1x, float lim1y, float lim2x, float lim2y);
	void DibujaPuertaAbierta();
};