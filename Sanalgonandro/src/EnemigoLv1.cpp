#include "EnemigoLv1.h"
#include "glut.h"

Enemigo1::Enemigo1() {
	//tama�o = 3.0f;

}

Enemigo1::Enemigo1(float x, float y, float vx, float vy) {
	tama�o = 3;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;

	vidas = 1;

	enemigo = new ETSIDI::Sprite("imagenes/enemigo.png", 2, 2, 3, 3);
}

Enemigo1::~Enemigo1() {

}

void Enemigo1::Dibuja() {

	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 0.0f, 115);
	glutSolidCube(tama�o);
	glPopMatrix();*/

	enemigo->setPos(posicion.x, posicion.y);
	enemigo->draw();

}

void Enemigo1::Mueve(float t) {
	/*posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;*/
	Animado::Mueve(t);
	/*if (posicion.x <= 7.75) {
		SetVel(15.0, 0);
	}
	if (posicion.x >= 14.25) {
		SetVel(-15.0, 0);
	}*/

	enemigo->loop();
}



float Enemigo1::GetTam() {
	return tama�o;
}

void Enemigo1::restarVida() {

	vidas--;

}

int Enemigo1::GetVidas() {
	return vidas;
}



