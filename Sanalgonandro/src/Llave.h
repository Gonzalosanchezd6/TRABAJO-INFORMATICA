#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Premios.h"

class Llave: public Premio {
private:
	float rad_int;
	float rad_ext;
	ETSIDI::Sprite* llave;
public:
	Llave(objetos o = LLAVE) :Premio(o), rad_ext(0), rad_int(0) { llave = new ETSIDI::Sprite("imagenes/llave.png", 0, 0, 3, 3); }
	virtual ~Llave();
	void SetLlave(float r1, float r2);
	void Dibuja();
	friend bool operator==(const Llave& l1, const Llave& l2);
};