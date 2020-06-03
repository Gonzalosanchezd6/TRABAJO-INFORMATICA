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
		reja = new ETSIDI::Sprite("imagenes/rejas.png", 0, 0, 6, 6);
	}
	virtual ~Reja();
	void SetRadio(float r);
	void Dibuja();

};