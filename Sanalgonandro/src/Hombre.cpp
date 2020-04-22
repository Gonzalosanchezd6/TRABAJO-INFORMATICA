#include "Hombre.h"
#include "glut.h"

Hombre::Hombre() {
	altura = 0.8f;
	aceleracion.y = -9.8;
}
Hombre::~Hombre() {
	//gonzalo friki
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

void Hombre::Salto() {

	float jump = posicion.y + 5.0;
	do {
		posicion.y += 0.01;
	} while (posicion.y <= jump);
	SetAc(0, -9.8);
}