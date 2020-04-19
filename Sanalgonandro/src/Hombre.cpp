#include "Hombre.h"
#include "glut.h"

Hombre::Hombre() {
	altura = 1.8f;
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