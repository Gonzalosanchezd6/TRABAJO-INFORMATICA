#include "Hombre.h"
#include "Interaccion.h"
#include "glut.h"

Hombre::Hombre() {
	altura = 0.8f;
	aceleracion.y = -9.8;
	llaves = 0;
	for (int i = 0; i < 3; i++) {
		Vida* aux = new Vida(-20+i*3,40);
		vidas.Agregar(aux);
	}
}

Hombre::~Hombre() {
	
}
/*
void Hombre::SetAltura(float r) {
	altura = r;
}




void Hombre::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}
*/
void Hombre::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
	vidas.Dibuja();
	/*///vidas
	glTranslatef(-30, 45, 0);
	int i;
	for (i = 0; i < vidas; i++) {
		
		glColor3f(255.0f, 0.0f, 0.0f);
		glutSolidSphere(0.7, 20, 20);
		glTranslatef(1.3, 0, 0);
		glutSolidSphere(0.7, 20, 20);
		glDisable(GL_LIGHTING);
		glBegin(GL_TRIANGLES);
		glVertex3f(-2.1f, -0.2f, 0);
		glVertex3f(0.75f, -0.2f, 0.0f);
		glVertex3f(-0.675f, -2.2f, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glTranslatef(3, 0, 0);
	}

	glTranslatef(30-(3+1.3)*(float)i, -45, 0);*/
}

void Hombre::Mueve(float t) {
	/*posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;*/
	Animado::Mueve(t);
	//vidas.Mueve(t);
}
/*
void Hombre::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void Hombre::SetAc(float ax, float ay) {

	aceleracion.x = ax;
	aceleracion.y = ay;
}*/

bool Hombre::Muerte(Hombre h, Enemigo1 e) {

	if (Interaccion::Choque(h, e)) {
		return true;
	}
	else {
		return false;
	}

}

bool Hombre::Muerte() {

	if (posicion.y < -3) {
		return true;
	}
	else {
		return false;
	}

}

bool Hombre::Muerte(Hombre h, EnemigoBolas b) {

	if (Interaccion::Choque(h, b)) {
		return true;
	}
	else {
		return false;
	}

}






float Hombre::GetAltura() {
	return altura;
}

void Hombre::Premios(objetos ob) {
	switch (ob) {
	case LLAVE:
		llaves += 1;
		break;
	default:
		break;
	}
}

int Hombre::NumPremios(objetos ob) {
	int num;
	switch (ob) {
	case LLAVE:
		num = llaves;
		return num;
		break;
	default:
		break;
	}
	return 0;
}

bool Hombre::Choque(Hombre h, Puerta p) {
	if (Interaccion::colision(p, h)) {
		return true;
	}
	return false;
}

void Hombre::reinicia() {
	SetPos(-10, 7);
	SetAc(0, -8);
	SetVel(0, 0);
}

void Hombre::aumentarVida() {
		Vida* aux = new Vida(-20 + vidas.nVidas() * 3, 40);
		vidas.Agregar(aux);
}

void Hombre::restarVida() {
	
	if (vidas.nVidas() > 0) {
		vidas.Eliminar(vidas.nVidas()-1);
		reinicia();
	}

}

int Hombre::GetVidas() {
	return vidas.nVidas();
}