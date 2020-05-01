#include "Llave.h"
#include "glut.h"

Llave::Llave() {
	rad_int = 0.0f;
	rad_ext = 0.0f;
}

Llave::~Llave() {

}

void Llave::SetLlave(float r1, float r2) {
	rad_int = r1;
	rad_ext = r2;
}

void Llave::SetPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Llave::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(255, 255, 0.0f);
	glutSolidTorus(rad_int, rad_ext, 20, 20);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	if (posicion.x > 0) {

		glVertex3d(posicion.x + 0.125, posicion.y - rad_ext, 0);
		glVertex3d(posicion.x - 0.125, posicion.y - rad_ext, 0);
		glVertex3d(posicion.x - 0.125, posicion.y - rad_ext - 1.5, 0);
		glVertex3d(posicion.x + 0.125, posicion.y - rad_ext - 1.5, 0);

	}
	else {
		glVertex3d(posicion.x - 0.125, posicion.y - rad_ext, 0);
		glVertex3d(posicion.x + 0.125, posicion.y - rad_ext, 0);
		glVertex3d(posicion.x + 0.125, posicion.y - rad_ext - 1.5, 0);
		glVertex3d(posicion.x - 0.125, posicion.y - rad_ext - 1.5, 0);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}

Vector2D Llave::GetPos() {
	return posicion;
}

bool operator==(const Llave& l1, const Llave& l2) {
	if (l1.rad_ext == l2.rad_ext && l1.rad_int == l2.rad_int && l1.posicion == l2.posicion) {
		return true;
	}
	return false;
}
