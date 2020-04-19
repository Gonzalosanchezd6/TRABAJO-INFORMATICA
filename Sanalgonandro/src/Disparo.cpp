#include "Disparo.h"
#include "glut.h"

Disparo::Disparo() {
	radio = 0.25f;
	velocidad.y = 0.5f;
}
Disparo::~Disparo() {

}

void Disparo::Dibuja() {
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();


	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	if (origen > 0) {

		glVertex3d(origen + 0.125, posicion.y, 0);
		glVertex3d(origen - 0.125, posicion.y, 0);
		glVertex3d(origen - 0.125, 0, 0);
		glVertex3d(origen + 0.125, 0, 0);

	}
	else {
		glVertex3d(origen - 0.125, posicion.y, 0);
		glVertex3d(origen + 0.125, posicion.y, 0);
		glVertex3d(origen + 0.125, 0, 0);
		glVertex3d(origen - 0.125, 0, 0);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}

void Disparo::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
	//pelotudo
}

void Disparo::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;

	origen = posicion.x;
}