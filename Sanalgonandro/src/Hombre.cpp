#include "Hombre.h"
#include "Interaccion.h"
#include "ETSIDI.h"
#include "glut.h"

Hombre::Hombre() {
	altura = 1.75;
	aceleracion.y = -9.8;
	llaves = 0;
	monedas = 0;
	vidas = 3;
	disparoEspecial = 0;
	hombre = new ETSIDI::Sprite("imagenes/AstroBoy.png", 0, 0, 3, 3);
}

Hombre::~Hombre() {
	
}


void Hombre::Dibuja() {
	hombre->setPos(posicion.x, posicion.y);
	hombre->draw();
}

void Hombre::Mueve(float t) {
	Animado::Mueve(t);
	hombre->loop();
}


bool Hombre::Muerte(Hombre h, Enemigo1 *e) {

	if (Interaccion::Choque(h, e)) {
		return true;
	}
	else {
		return false;
	}

}

bool Hombre::Muerte() {

	if (posicion.y < -3) {
		return true;
	}
	else {
		return false;
	}

}

bool Hombre::Muerte(Hombre h, EnemigoBolas *b) {

	if (Interaccion::Choque(h, b)) {
		return true;
	}
	else {
		return false;
	}

}




float Hombre::GetAltura() {
	return altura;
}

void Hombre::Premios(objetos ob) {
	switch (ob) {
	case LLAVE:
		llaves += 1;
		break;
	case MONEDA:
		if (monedas < 5) {
			monedas += 1;
		}
		break;
	default:
		break;
	}
}

int Hombre::NumPremios(objetos ob) {
	switch (ob) {
	case LLAVE:
		return llaves;
		break;
	case MONEDA:
		return monedas;
		break;
	default:
		break;
	}
	return 0;
}

bool Hombre::Choque(Hombre h, Puerta p) {
	if (Interaccion::colision(p, h)) {
		return true;
	}
	return false;
}

void Hombre::reinicia() {
	SetPos(-10, 7);
	SetAc(0, -8);
	SetVel(0, 0);
}

void Hombre::aumentarVida() {
	vidas++;
}

void Hombre::restarVida() {
	if (vidas > 0) {
		vidas--;
		reinicia();
		reset();
		disparoEspecial = 0;
	}

}

int Hombre::GetVidas() {
	return vidas;
}

void Hombre::reset() {
	llaves = 0;
	monedas = 0;
}

int Hombre::GetNumPrem(objetos o) {
	switch (o)
	{
	case Hombre::LLAVE:
		return llaves;
		break;
	case Hombre::MONEDA:
		return monedas;
		break;
	default:
		return 0;
		break;
	}
}
