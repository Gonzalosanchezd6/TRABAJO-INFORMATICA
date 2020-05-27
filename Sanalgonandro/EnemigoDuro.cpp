#include "EnemigoDuro.h"
#include "glut.h"

EnemigoDuro::EnemigoDuro() {
	tama�o = 1;
}

EnemigoDuro::EnemigoDuro(float x, float y, float vx, float vy) {
	tama�o = 0.5;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;
}

EnemigoDuro::~EnemigoDuro() {

}



void EnemigoDuro::Dibuja() {

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(255.0f, 0.0f, 0);
	glutSolidCube(tama�o);
	glutSolidTorus(tama�o, tama�o+0.5, 3, 3);
	glPopMatrix();
}

void EnemigoDuro::Mueve(float t) {

	Animado::Mueve(t);

}

Vector2D EnemigoDuro::GetPos() {
	return posicion;
}

float EnemigoDuro::GetTam() {
	return tama�o;
}

Vector2D EnemigoDuro::GetVel() {
	return velocidad;
}

void EnemigoDuro::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}