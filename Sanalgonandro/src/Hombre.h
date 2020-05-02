#pragma once
#include "Vector2D.h"
#include "EnemigoLv1.h"
#include "EnemigoBolas.h"
#include "Llave.h"

class Hombre {
private:
	friend class Interaccion;
	friend class ListaPlataformas;

	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	int llaves;
	

public:
	enum objetos { LLAVE = 1, MONEDA };

	Hombre();
	virtual ~Hombre();
	void SetAltura(float r);
	void SetPos(float ix, float iy);
	void Dibuja();
	void Mueve(float t);
	void SetVel(float vx, float vy);
	void SetAc(float ax, float ay);
	bool Muerte(Hombre h, Enemigo1 e);
	bool Muerte(Hombre h, EnemigoBolas b);
	Vector2D GetPos();
	float GetPosX();
	float GetPosY();

	float GetAltura();
	
	void Premios(objetos ob);
};