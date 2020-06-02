#include "Hombre.h"
#include "Interaccion.h"
#include "ETSIDI.h"
#include "glut.h"

Hombre::Hombre() {
	altura = 1.5f;
	aceleracion.y = -9.8;
	llaves = 0;
	monedas = 0;
	for (int i = 0; i < 3; i++) {
		Vida* aux = new Vida(-20+i*3,40);
		vidas.Agregar(aux);
	}
	hombre = new ETSIDI::Sprite("imagenes/AstroBoy.png", 0, 0, 3, 3);
}

Hombre::~Hombre() {
	
}
/*
void Hombre::SetAltura(float r) {
	altura = r;
}
*/
/*void Hombre::SetPos(float ix, float iy) {
	Animado::SetPos(ix, iy);
	vidas.setpos(ix, 40);
}*/

void Hombre::Dibuja() {
	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();*/
	vidas.Dibuja();
	hombre->setPos(posicion.x, posicion.y);
	hombre->draw();
	
}

void Hombre::Mueve(float t) {
	/*posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;*/
	Animado::Mueve(t);
	//vidas.Mueve(t);
	hombre->loop();
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
	case MONEDA:
		monedas += 1;
		break;
	default:
		break;
	}
}

int Hombre::NumPremios(objetos ob) {
	switch (ob) {
	case LLAVE:
		return llaves;
		break;
	case MONEDA:
		return monedas;
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

	for (int i = 0; i < vidas.nVidas(); i++){
		//vidas.setpos(-20 + i * 3, 40);
	}
	
}

void Hombre::aumentarVida() {
		Vida* aux = new Vida(-20 + vidas.nVidas() * 3, 40);
		vidas.Agregar(aux);
}

void Hombre::restarVida() {
	
	if (vidas.nVidas() > 0) {
		vidas.Eliminar(vidas.nVidas()-1);
		reinicia();
		reset();
	}

}

int Hombre::GetVidas() {
	return vidas.nVidas();
}

void Hombre::reset() {
	llaves = 0;
	monedas = 0;
}

int Hombre::GetNumPrem(objetos o) {
	switch (o)
	{
	case Hombre::LLAVE:
		return llaves;
		break;
	case Hombre::MONEDA:
		return monedas;
		break;
	default:
		return 0;
		break;
	}
}
