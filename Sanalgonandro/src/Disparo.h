#pragma once
#include "Vector2D.h"

class Disparo {
private:
	float radio;
	Vector2D origendisp;
	Vector2D origen;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Disparo();
	Disparo(Vector2D Orig);
	virtual ~Disparo();
	void Dibuja();
	void Mueve(float t);
	void SetPos(float ix, float iy);
	void SetOrig(float ix, float iy);
	Vector2D GetPos() { return posicion; }
	Vector2D GetOrig() { return origendisp; }
	float GetRadio() { return radio; }
	void SetVel(float vx, float vy) { velocidad.x = vx, velocidad.y = vy; }
};