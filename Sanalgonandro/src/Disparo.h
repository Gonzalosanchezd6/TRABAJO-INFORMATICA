#pragma once
#include "Animado.h"

class Disparo: public Animado {
protected:
	float radio;
	int disparo;
	Vector2D origendisp;
	Vector2D origen;
	bool especial;
	
public:
	Disparo();
	Disparo(int d, Vector2D Orig);
	virtual ~Disparo();
	virtual void Dibuja();
	void Mueve(float t);
	void SetOrig(float ix, float iy);
	Vector2D GetOrig() { return origendisp; }
	float GetRadio() { return radio; }
	bool GetEsp() { return especial; }
};