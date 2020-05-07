#include "Interaccion.h"
#include <math.h>
#include "glut.h"

Interaccion::Interaccion() {

}

Interaccion::~Interaccion() {

}

void Interaccion::rebote(Hombre &h, Pared p) {
	Vector2D dir;
	float dif = p.distancia(h.posicion, &dir) - h.altura;
	if (dif <= 0.0f) {
		h.aceleracion.y = 0.0f;
		h.velocidad.y = 0.0f;
	}
	
}


bool Interaccion::Colision(Pared p, Hombre h) {
	Vector2D dir;
	float dif = p.distancia(h.posicion, &dir) - h.altura;
	if (dif <= 0.0f) {
		return true;
	}
	return false;
}

bool Interaccion::Choque(Hombre h, Enemigo1 e) {
	Vector2D dif = h.posicion - e.posicion;
	float d = dif.modulo();
	float dentro = d - (h.altura + e.tamaño/2);

	if (dentro < 0.0f) {
		return true;
	}
	else {
		return false;
	}
}

bool Interaccion::Choque(Hombre h, Llave l) {
	Vector2D pos_l = l.GetPos();
	Vector2D pos_h = h.GetPos();
	//pos_h.y += h.altura / 2.0f;
	float distancia = (pos_l - pos_h).modulo() - (h.altura + 1.5);
	if (distancia < 0.1f) {
		return true;
	}
	return false;
}

bool Interaccion::Choque(Hombre h, EnemigoBolas b) {
	Vector2D dif = h.posicion - b.posicion;
	float d = dif.modulo();
	float dentro = d - (h.altura + b.radio / 2);

	if (dentro < 0.0f) {
		return true;
	}
	else {
		return false;
	}
}



bool Interaccion::colision(Vida v, Hombre h) {
	Vector2D pos = h.GetPos();
	pos.y += h.GetAltura() / 2.0f;

	float distancia = (v.posicion - pos).modulo();
	if (distancia < 1) {
		return true;
	}
	return false;

}


bool Interaccion::colision(Disparo d, Pared p) {
	Vector2D dir;
	float dif = p.distancia(d.GetPos(), &dir) - d.GetRadio();
	if (dif <= 0.1f) {
		return true;
	}
	return false;
}

bool Interaccion::colision(Disparo d, Enemigo1 e) {

	Vector2D dif = d.GetPos() - e.posicion;
	float dis = dif.modulo();
	float dentro = dis - (e.tamaño / 2);
	if (dentro < 0.1f) {
		return true;
	}
	else {
		return false;
	}
}

bool Interaccion::Colision(Pared p, EnemigoBolas b) {
	Vector2D dir;
	float dif = p.distancia(b.posicion, &dir) - b.radio;
	if (dif <= 0.0f) {
		return true;
	}
	return false;
}

bool Interaccion::colision(Pared p, Enemigo1 e) {
	float pos1 = e.GetPos().x + (e.GetTam() / 2);
	float pos2 = e.GetPos().x - (e.GetTam() / 2);
	if (e.GetPos().y == (p.GetPos(2).y + 0.75f)) {
		if ((pos2 <= p.GetPos(1).x) || (pos1 >= p.GetPos(2).x)) {
			return true;
		}
	}
	return false;
}
