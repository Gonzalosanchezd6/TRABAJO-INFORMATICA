#include "EnemigoBolas.h"
#include "glut.h"

EnemigoBolas::EnemigoBolas() {
	radio = 0.3f;
	aceleracion.y = -50.0f;
	velocidad.y = -50.0f;
}

EnemigoBolas::~EnemigoBolas() {

}
void EnemigoBolas::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;

}
void EnemigoBolas::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(100, 100, 100);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

}
void EnemigoBolas::Mueve(float t) {
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;


}

void EnemigoBolas::SetAc(float ax, float ay) {

	aceleracion.x = ax;
	aceleracion.y = ay;
}
