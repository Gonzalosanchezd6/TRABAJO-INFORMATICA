#include "EnemigoFinal.h"
#include "glut.h"

EnemigoFinal::EnemigoFinal() {
	//tamaño = 3.0f;

}

EnemigoFinal::EnemigoFinal(float x, float y, float vx, float vy) : Enemigo1(x, y, vx, vy) {
	tamaño = 6.0;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;

	vidas = 5;

	enemigofinal = new ETSIDI::Sprite("imagenes/enemigo.png", 2, 2, 6, 6);
}

EnemigoFinal::~EnemigoFinal() {

}

void EnemigoFinal::Dibuja() {

	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 0.0f, 115);
	glutSolidCube(tamaño);
	glPopMatrix();*/

	enemigofinal->setPos(posicion.x, posicion.y);
	enemigofinal->draw();

}

void EnemigoFinal::Mueve(float t) {
	/*posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;*/
	Animado::Mueve(t);
	/*if (posicion.x <= 7.75) {
		SetVel(15.0, 0);
	}
	if (posicion.x >= 14.25) {
		SetVel(-15.0, 0);
	}*/

	enemigofinal->loop();
}



float EnemigoFinal::GetTam() {
	return tamaño;
}