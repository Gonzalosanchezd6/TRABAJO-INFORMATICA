#include "Hombre.h"
#include "Interaccion.h"
#include "glut.h"

Hombre::Hombre() {
	altura = 0.8f;
	aceleracion.y = -9.8;
	llaves = 0;
}

Hombre::~Hombre() {
	
}

void Hombre::SetAltura(float r) {
	altura = r;
}

void Hombre::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Hombre::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}

void Hombre::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
}

void Hombre::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void Hombre::SetAc(float ax, float ay) {

	aceleracion.x = ax;
	aceleracion.y = ay;
}

float Hombre::GetPosX() {
	return posicion.x;
}

float Hombre::GetPosY() {
	return posicion.y;
}

bool Hombre::Muerte(Hombre h, Enemigo1 e) {

	if (posicion.y < -3 || Interaccion::Choque(h, e)) {
		return true;
	}
	else {
		return false;
	}

}

bool Hombre::Muerte(Hombre h, EnemigoBolas b) {

	if (posicion.y < -3 || Interaccion::Choque(h, b)) {
		return true;
	}
	else {
		return false;
	}

}

Vector2D Hombre::GetPos() {
	return posicion;
}

float Hombre::GetAltura() {
	return altura;
}

void Hombre::Premios(objetos ob) {
	switch (ob) {
	case LLAVE:
		llaves += 1;
		break;
	default:
		break;
	}
}

int Hombre::NumPremios(objetos ob) {
	int num;
	switch (ob) {
	case LLAVE:
		num = llaves;
		return num;
		break;
	default:
		break;
	}
	return 0;
}

bool Hombre::Choque(Hombre h, Puerta p) {
	if (Interaccion::Colision(p, h)) {
		return true;
	}
	return false;
}

