#pragma once
#include "Animado.h"

class Disparo: public Animado {
private:
	float radio;
	int disparo;
	Vector2D origendisp;
	Vector2D origen;
	
public:
	Disparo();
	Disparo(int d, Vector2D Orig);
	virtual ~Disparo();
	void Dibuja();
	void Mueve(float t);
	void SetOrig(float ix, float iy);
	Vector2D GetOrig() { return origendisp; }
	float GetRadio() { return radio; }
	
};