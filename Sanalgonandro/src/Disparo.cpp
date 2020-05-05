#include "Disparo.h"
#include "glut.h"

Disparo::Disparo() {
	radio = 0.25f;
	velocidad.x = 200.0f;
	posicion = origen;
}

Disparo::Disparo(Vector2D Orig) {
	radio = 0.25f;
	origen = Orig;
	velocidad.x = 200.0f;
	posicion = origen;
}


Disparo::~Disparo() {

}

void Disparo::Dibuja() {

	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);

	glVertex3d(origen.x, origen.y, 0.0f);
	glVertex3d(posicion.x, posicion.y, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);


	glPopMatrix();
}

void Disparo::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (posicion.x >= origen.x + 3.5) {
		origen = origen + velocidad * t + aceleracion * (0.5f * t * t);
	}
}

void Disparo::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;

}

void Disparo::SetOrig(float ix, float iy) {
	origen.x = ix;
	origen.y = iy;
}

