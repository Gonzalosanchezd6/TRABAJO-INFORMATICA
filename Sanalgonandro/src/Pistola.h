#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Premios.h"

class Pistola : public Premio {
private:
	float radio;
	ETSIDI::Sprite* pistola;
public:
	Pistola(objetos o = PISTOLA) :Premio(o), radio(0) { /*pistola = new ETSIDI::Sprite("imagenes/llave.png", 0, 0, 3, 3);*/ }
	virtual ~Pistola();
	void SetPis(float r);
	void Dibuja();
	//friend bool operator==(const Llave& l1, const Llave& l2);
};