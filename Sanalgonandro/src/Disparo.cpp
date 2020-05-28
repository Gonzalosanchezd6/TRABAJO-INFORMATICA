#include "Disparo.h"
#include "glut.h"

Disparo::Disparo() {
	radio = 0.25f;
	velocidad.x = 200.0f;
	posicion = origen;
	origendisp = origen;
}

Disparo::Disparo(int d, Vector2D Orig) {
	radio = 0.25f;
	origendisp = Orig;
	origen = Orig;
	velocidad.x = 200.0f;
	posicion = origen;
	disparo = d;
}


Disparo::~Disparo() {

}

void Disparo::Dibuja() {

	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);

	glVertex3d(origen.x, origen.y, 0.0f);
	glVertex3d(posicion.x, posicion.y, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);


	glPopMatrix();
}

void Disparo::Mueve(float t) {
	
	if (disparo == 1) {
		//posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
		//velocidad = velocidad + aceleracion * t;
		Animado::Mueve(t);
		if (posicion.x >= origen.x + 3.5) {
			origen = origen + velocidad * t + aceleracion * (0.5f * t * t);
		}
		else if (posicion.x <= origen.x - 3.5) {
			origen = origen + velocidad * t + aceleracion * (0.5f * t * t);
		}
	}
	else if (disparo == 0) {
		posicion = posicion - velocidad * t - aceleracion * (0.5f * t * t);
		velocidad = velocidad - aceleracion * t;
		if (posicion.x >= origen.x + 3.5) {
			origen = origen - velocidad * t - aceleracion * (0.5f * t * t);
		}
		else if (posicion.x <= origen.x - 3.5) {
			origen = origen - velocidad * t - aceleracion * (0.5f * t * t);
		}
	}
}



void Disparo::SetOrig(float ix, float iy) {
	origen.x = ix;
	origen.y = iy;
	origendisp.x = ix;
	origendisp.y = iy;
}

