#include"Vida.h"
#include "ETSIDI.h"
#include "glut.h"

Vida::Vida(){
	SetColor(255, 0, 0);
	aceleracion.y = -9.8f;
}

Vida::Vida(float x, float y, float vx, float vy, float ax, float ay) {
	SetColor(255, 0, 0);
	SetPos(x, y);
	SetVel(vx, vy);
	aceleracion.x = ax;
	aceleracion.y = ay;
}

Vida::~Vida(){

}

void Vida::Dibuja() {
	/*glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(255.0f, 0.0f, 0.0f);
	glutSolidSphere(0.7, 20, 20);
	glTranslatef(1.3, 0, 0);
	glutSolidSphere(0.7, 20, 20);
	glDisable(GL_LIGHTING);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.1f, -0.2f, 0);
	glVertex3f(0.75f, -0.2f, 0.0f);
	glVertex3f(-0.675f, -2.2f, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslatef(-posicion.x-1.3,- posicion.y, 0);*/

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/corazon.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glTexCoord2d(0, 1); glVertex3f(posicion.x-1.5, posicion.y- 1.5, 0);
	glTexCoord2d(1, 1); glVertex3f(posicion.x+ 1.5, posicion.y- 1.5, 0);
	glTexCoord2d(1, 0); glVertex3f(posicion.x+ 1.5, posicion.y+ 1.5, 0);
	glTexCoord2d(0, 0); glVertex3f(posicion.x- 1.5, posicion.y+ 1.5, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D); //imagen corazon
}

void Vida::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Vida::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Vida::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Vida::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}
