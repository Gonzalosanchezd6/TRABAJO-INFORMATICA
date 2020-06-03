#include "EnemigoBolas.h"
#include "ETSIDI.h"
#include "glut.h"

/*EnemigoBolas::EnemigoBolas() {
	//radio = 0.3f;
	//aceleracion.y = -50.0f;
	//velocidad.y = -50.0f;
	
}*/

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
	
	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(100, 100, 100);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();*/
	fuego->setPos(posicion.x, posicion.y);
	fuego->draw();
	/*
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/oie_transparent.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glTexCoord2d(0, 1); glVertex3f(posicion.x-2, posicion.y-2, 0);
	glTexCoord2d(1, 1); glVertex3f(posicion.x+2, posicion.y-2, 0);
	glTexCoord2d(1, 0); glVertex3f(posicion.x+2, posicion.y+2, 0);
	glTexCoord2d(0, 0); glVertex3f(posicion.x-2, posicion.y+2, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);*/
}
void EnemigoBolas::Mueve(float t) {
	Animado::Mueve(t);
	fuego->loop();
}




