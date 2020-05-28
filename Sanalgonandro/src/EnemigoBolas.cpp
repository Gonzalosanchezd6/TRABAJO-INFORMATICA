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
	aceleracion.y = -9.8f;
}


void EnemigoBolas::Dibuja() {
	
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(100, 100, 100);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

}
void EnemigoBolas::Mueve(float t) {
	Animado::Mueve(t);
}




