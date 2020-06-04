#include "DisparoSuper.h"
#include "glut.h"

DisparoSuper::DisparoSuper() {
	radio = 0.35f;
	velocidad.x = 300.0f;
	posicion = origen;
	origendisp = origen;
	especial = true;
}


DisparoSuper::DisparoSuper(int d, Vector2D Orig) {

	radio = 0.35f;
	origendisp = Orig;
	origen = Orig;
	velocidad.x = 300.0f;
	posicion = origen;
	disparo = d;
	especial = true;
}

DisparoSuper::~DisparoSuper() {

}
void DisparoSuper::Dibuja() {

	glColor3ub(255, 0, 0);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3ub(255, 0, 0);
	glVertex3d(origen.x, origen.y, 0);
	glVertex3d(posicion.x, posicion.y, 0);

	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

}