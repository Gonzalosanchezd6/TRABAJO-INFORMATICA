#include "Monedas.h"
#include "glut.h"

Monedas::~Monedas() {

}

/*void Monedas::SetRadio(float r) {
	radio = r;
}*/

void Monedas::SetRadio(float r) {
	radio = r;
}

void Monedas::Dibuja() {
	
	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(248, 255, 0.0f);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();*/
	moneda->setPos(posicion.x, posicion.y);
	moneda->draw();
}