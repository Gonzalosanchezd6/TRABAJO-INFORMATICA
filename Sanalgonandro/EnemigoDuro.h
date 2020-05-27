#pragma once
#include "Animado.h"
#include "Vector2D.h"


class EnemigoDuro:public Animado
{
private:
	friend class Interaccion;
	float tamaño;

public:
	EnemigoDuro();
	EnemigoDuro(float x, float y, float vx = -15.0f, float vy = 0.0f);
	virtual ~EnemigoDuro();
	void Dibuja();
	void Mueve(float t);

	Vector2D GetPos();
	float GetTam();
	Vector2D GetVel();
	void SetVel(float vx, float vy);
};

