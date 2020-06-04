#pragma once
#include "Vector2D.h"
//#include "Hombre.h"
//#include "glut.h"


class Premio {
protected:
	Vector2D posicion;
public:
	enum objetos { LLAVE = 0, MONEDA, REJA, VIDA, PISTOLA };
protected:
	objetos tipo;
	bool libre; //si esta a true se puede coger, false no

public:
	Premio(objetos t, bool lib = true) :tipo(t) {}
	virtual ~Premio();
	//void SetLlave(float r1, float r2);
	void SetPos(float x, float y);
	virtual void Dibuja() = 0;
	Vector2D GetPos() { return posicion; }
	objetos GetTipo() { return tipo; }

	friend bool operator==(const Premio& l1, const Premio& l2);
	bool Libre() { return libre; }
	void SetLibertad(bool l) { libre = l; }
};
