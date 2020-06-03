#include "Pistola.h"
#include "ETSIDI.h"
#include "glut.h"



Pistola::~Pistola() {

}

void Pistola::SetPis(float r) {
	radio = r;
}

void Pistola::Dibuja() {
	/*glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glPopMatrix();*/
	pistola->setPos(posicion.x, posicion.y);
	pistola->draw();
}

//bool operator==(const Llave& l1, const Llave& l2) {
//	if (l1.rad_ext == l2.rad_ext && l1.rad_int == l2.rad_int && l1.posicion == l2.posicion) {
//		return true;
//	}
//	return false;
//}