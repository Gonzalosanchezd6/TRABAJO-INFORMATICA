#include "Hombre.h"
#include "glut.h"

Hombre::Hombre() {
	altura = 0.8f;
	aceleracion.y = -9.8;
	control = 0;
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
	if (control == 1) {
		float jump = posicion.y + 2.5;
		SetAc(0,9.8);
		do {
			posicion = posicion + velocidad * t + aceleracion * (0.02f * t * t);
			velocidad = velocidad + aceleracion * t;
		} while (posicion.y <= jump);
		SetAc(0, -9.8);
		control = 0;
	}

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

void Hombre::SetCont(int x) {

	control = x;
}


float Hombre::GetPosX() {
	return posicion.x;
}

float Hombre::GetPosY() {
	return posicion.y;
}

