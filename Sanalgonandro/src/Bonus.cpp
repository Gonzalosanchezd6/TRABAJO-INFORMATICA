#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"

Bonus::Bonus(){
	lado = 1.0f;
	aceleracion.y = -9.8f;
}
Bonus::~Bonus() {

}

void Bonus::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
			rand() / (float)RAND_MAX);//color aleatorio
		glutSolidCube(lado);
	glPopMatrix();
}
