#pragma once
#include "Premios.h"

class Monedas :public Premio {
private:
	float radio;

public:
	Monedas(objetos o = MONEDA) :Premio(o), radio(0) {}
	virtual ~Monedas();
	void SetRadio(float r);
	//void SetPos(float x, float y);
	void Dibuja();
	//Vector2D GetPos();

	//friend bool operator==(const Monedas& l1, const Monedas& l2);

};
