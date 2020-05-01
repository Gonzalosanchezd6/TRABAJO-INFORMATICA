#include "EnemigoBolas.h"
#include "glut.h"

EnemigoBolas::EnemigoBolas() {
	//radio = 0.3f;
	//aceleracion.y = -50.0f;
	//velocidad.y = -50.0f;
	
}

EnemigoBolas::~EnemigoBolas() {

}

EnemigoBolas::EnemigoBolas(float rad, float x, float y, float vx, float vy) {
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	aceleracion.y = -50.0f;
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
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (posicion.x <= -20) {
		setVel(3, 0);
	}
	if (posicion.x >= 25) {
		setVel(-3, 0);
	}


}

void EnemigoBolas::SetAc(float ax, float ay) {

	aceleracion.x = ax;
	aceleracion.y = ay;
}

void EnemigoBolas::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
