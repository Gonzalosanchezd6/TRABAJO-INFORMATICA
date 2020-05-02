#include "Bloque.h"
#include <stdlib.h>
#include "glut.h"
Bloque::Bloque() {
	lado = 2.0f;

}
Bloque::~Bloque() {

}

void Bloque::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1, 1, 0);
	//glRotatef(0, 1, 1, 1);
	/*glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);*/
	glutSolidCube(lado);
	glPopMatrix();
}

void Bloque::Mueve(float t) {

	posicion = posicion + velocidad * t;


}

void Bloque::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}
void Bloque::SetVel(float vx, float vy) {
	velocidad.x = v;
	velocidad.y = vy;
}




