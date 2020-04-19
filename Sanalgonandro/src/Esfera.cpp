#include "Esfera.h"
#include "glut.h"

Esfera::Esfera() {
	radio = 1.0f;//se inicializa por defecto a 1
	rojo = verde = azul = 255;
	aceleracion.y = -9.8f;
}

Esfera::~Esfera() {

}

void Esfera::SetRadio(float r) {
	radio = r;
}

void Esfera::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}

void Esfera::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Esfera::Dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Esfera::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
}

void Esfera::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}