#include "EnemigoLv1.h"
#include "glut.h"

/*Enemigo1::Enemigo1() {
	//tama�o = 3.0f;

}*/

Enemigo1::Enemigo1(float x, float y,float vx, float vy) {
	tama�o = 6.0;
	velocidad.x = vx;
	velocidad.y = vy;
	posicion.x = x;
	posicion.y = y;
	enemigo = new ETSIDI::Sprite("imagenes/enemigo.png", 2, 2, 6, 6);
}

Enemigo1::~Enemigo1() {

}

void Enemigo1::Dibuja() {
	enemigo->setPos(posicion.x, posicion.y);
	enemigo->draw();
}

void Enemigo1::Mueve(float t) {

	Animado::Mueve(t);
	enemigo->loop();
}



float Enemigo1::GetTam() {
	return tama�o;
}




