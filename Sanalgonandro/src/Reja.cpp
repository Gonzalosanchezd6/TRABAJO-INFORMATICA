#include "Reja.h"
#include "glut.h"

Reja::~Reja() {

}

/*void Monedas::SetRadio(float r) {
	radio = r;
}*/

void Reja::SetRadio(float r) {
	radio = r;
}

void Reja::Dibuja() {

	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(248, 255, 0.0f);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();*/
	reja->setPos(posicion.x, posicion.y);
	reja->draw();
}