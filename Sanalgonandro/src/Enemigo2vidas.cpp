#include "Enemigo2vidas.h"
#include "glut.h"

Enemigo2vidas::Enemigo2vidas() {
	//tamaño = 3.0f;

}

Enemigo2vidas::Enemigo2vidas(float x, float y, float vx, float vy) : Enemigo1(x, y, vx, vy) {
	tamaño = 6.0;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;

	vidas = 2;

	enemigo2vidas = new ETSIDI::Sprite("imagenes/enemigo.png", 2, 2, 3, 3);
}

Enemigo2vidas::~Enemigo2vidas() {

}

void Enemigo2vidas::Dibuja() {

	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 0.0f, 115);
	glutSolidCube(tamaño);
	glPopMatrix();*/

	enemigo2vidas->setPos(posicion.x, posicion.y);
	enemigo2vidas->draw();

}

void Enemigo2vidas::Mueve(float t) {
	/*posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;*/
	Animado::Mueve(t);
	/*if (posicion.x <= 7.75) {
		SetVel(15.0, 0);
	}
	if (posicion.x >= 14.25) {
		SetVel(-15.0, 0);
	}*/

	enemigo2vidas->loop();
}