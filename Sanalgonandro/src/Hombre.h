#pragma once
#include "Vector2D.h"
#include "EnemigoLv1.h"
#include "EnemigoBolas.h"
#include "Llave.h"
#include "Puerta.h"
#include"ListaVidas.h"

#define MAX_VIDAS 5

class Hombre {
private:
	friend class Interaccion;
	friend class ListaPlataformas;

	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	int llaves;
	ListaVidas vidas;
	
	

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
	void reinicia();// volver a la posicion inicial 
	Vector2D GetPos();
	float GetPosX();
	float GetPosY();
	void aumentarVida();
	void restarVida();

	float GetAltura();
	
	void Premios(objetos ob);
	int NumPremios(objetos ob);
	bool Choque(Hombre h, Puerta p);
};