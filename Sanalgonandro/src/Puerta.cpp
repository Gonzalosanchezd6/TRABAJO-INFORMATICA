#include "Puerta.h"
#include "ETSIDI.h"
#include "glut.h"


Puerta::Puerta(float x1, float y1, float x2, float y2):Pared(x1, y1, x2, y2) {
	puerta = new ETSIDI::Sprite("imagenes/puertacerrada.png", 2, 2, 8, 8);
}

Puerta::~Puerta() {

}

void Puerta::Dibuja() {
	/*glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
		glVertex3d(limite1.x, limite1.y, 0);
		glVertex3d(limite2.x, limite1.y, 0);
		glVertex3d(limite2.x, limite2.y, 0);
		glVertex3d(limite1.x, limite2.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);*/

	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Puerta.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(limite1.x, limite1.y, 0);
	glTexCoord2d(1, 1); glVertex3d(limite2.x, limite1.y, 0);
	glTexCoord2d(1, 0); glVertex3d(limite2.x, limite2.y, 0);
	glTexCoord2d(0, 0); glVertex3d(limite1.x, limite2.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);*/ //imagen puerta

	puerta->setPos((limite1.x + limite2.x)/2, (limite1.y + limite2.y) / 2);
	puerta->draw();
}

void Puerta::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}

void Puerta::SetPos(float lim1x, float lim1y, float lim2x, float lim2y) {
	limite1.x = lim1x;
	limite1.y = lim1y;
	limite2.x = lim2x;
	limite2.y = lim2y;
}

void Puerta::DibujaPuertaAbierta() {
	puerta = new ETSIDI::Sprite("imagenes/puertaabierta.png", 2, 2, 8, 8);
	Puerta::Dibuja();
	
}
