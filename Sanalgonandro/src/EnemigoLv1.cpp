#include "EnemigoLv1.h"
#include "glut.h"

Enemigo1::Enemigo1() {
	tamaño = 1.5;
}

Enemigo1::Enemigo1(float x, float y,float vx, float vy) {
	tamaño = 1.5;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;
}

Enemigo1::~Enemigo1() {

}

void Enemigo1::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;

}

void Enemigo1::Dibuja() {
	
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 0.0f, 115);
	glutSolidCube(tamaño);
	glPopMatrix();
}

void Enemigo1::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (posicion.x <= 7.75) {
		SetVel(15.0, 0);
	}
	if (posicion.x >= 14.25) {
		SetVel(-15.0, 0);
	}
}

void Enemigo1::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
