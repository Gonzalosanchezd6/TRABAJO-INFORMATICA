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
	vida = new ETSIDI::Sprite("imagenes/corazon.png", x, y, 3, 3);
}

Vida::~Vida(){

}

void Vida::Dibuja() {
	vida->setPos(posicion.x, posicion.y);
	vida->draw();
}

void Vida::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}
