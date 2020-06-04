#include "EnemigoBolas.h"
#include "ETSIDI.h"
#include "glut.h"

EnemigoBolas::EnemigoBolas() {
	radio = 0.3f;
	SetPos(0.0f, 0.0f); 
	fuego = new ETSIDI::Sprite("imagenes/oie_transparent.png", 0.0f, 0.0f, 2, 2);
}

EnemigoBolas::~EnemigoBolas() {

}

EnemigoBolas::EnemigoBolas(float rad, float x, float y, float vx, float vy) {
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	aceleracion.y = -9.8f;
	fuego = new ETSIDI::Sprite("imagenes/oie_transparent.png",x,y, 2,2);
}


void EnemigoBolas::Dibuja() {
	
	fuego->setPos(posicion.x, posicion.y);
	fuego->draw();

}
void EnemigoBolas::Mueve(float t) {
	Animado::Mueve(t);
	fuego->loop();
}




