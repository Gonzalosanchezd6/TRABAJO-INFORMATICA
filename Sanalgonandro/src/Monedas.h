#pragma once
#include "Premios.h"
#include "ETSIDI.h"

class Monedas :public Premio {
private:
	float radio;
	ETSIDI::Sprite* moneda;
public:
	Monedas(objetos o = MONEDA) :Premio(o), radio(0) { moneda = new ETSIDI::Sprite("imagenes/moneda.png", 0, 0, 3, 3); }
	virtual ~Monedas();
	void SetRadio(float r);
	//void SetPos(float x, float y);
	void Dibuja();
	//Vector2D GetPos();

	//friend bool operator==(const Monedas& l1, const Monedas& l2);

};
