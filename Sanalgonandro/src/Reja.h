#pragma once
#include "Premios.h"
#include "ETSIDI.h"

class Reja :public Premio {
private:
	float radio;
	ETSIDI::Sprite* reja;
public:
	Reja(objetos o = REJA) :Premio(o), radio(0) { 
		Premio::SetLibertad(false);
		/*reja = new ETSIDI::Sprite("imagenes/moneda.png", 0, 0, 3, 3);*/
	}
	virtual ~Reja();
	void SetRadio(float r);
	//void SetPos(float x, float y);
	void Dibuja();
	//Vector2D GetPos();

	//friend bool operator==(const Monedas& l1, const Monedas& l2);

};