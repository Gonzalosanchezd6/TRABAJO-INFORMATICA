#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
class Llave {
private:
	float rad_int;
	float rad_ext;
	Vector2D posicion;
	ETSIDI::Sprite* llave;
public:
	Llave();
	virtual ~Llave();
	void SetLlave(float r1, float r2);
	void SetPos(float x, float y);
	void Dibuja();
	Vector2D GetPos();

	friend bool operator==(const Llave& l1, const Llave& l2);

};