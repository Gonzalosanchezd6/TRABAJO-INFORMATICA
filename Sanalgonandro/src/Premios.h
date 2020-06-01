#pragma once
#include "Vector2D.h"
//#include "Hombre.h"
//#include "glut.h"


class Premio {
protected:
	Vector2D posicion;
public:
	enum objetos { LLAVE = 0, MONEDA };
protected:
	objetos tipo;

public:
	Premio(objetos t) :tipo(t) {}
	virtual ~Premio();
	//void SetLlave(float r1, float r2);
	void SetPos(float x, float y);
	virtual void Dibuja() {}
	Vector2D GetPos() { return posicion; }
	objetos GetTipo() { return tipo; }

	friend bool operator==(const Premio& l1, const Premio& l2);

};
