#include "Caja.h"
#include "glut.h"

Caja::Caja() {
	inferior1.SetPos(-20, 1, -1, 1);
	inferior1.SetColor(0, 100, 0);
	inferior2.SetPos(1, 1, 20, 1);
	inferior2.SetColor(0, 100, 0);

	plataforma1.SetPos(-13, 5, -5, 5);
	plataforma1.SetColor(100, 0, 0);
	plataforma2.SetPos(-5, 8, 0, 8);
	plataforma2.SetColor(100, 0, 0);
	plataforma3.SetPos(0, 11, 8, 11);
	plataforma3.SetColor(100, 0, 0);
	plataforma4.SetPos(8, 14, 13, 14);
	plataforma4.SetColor(100, 0, 0);
}

Caja::~Caja() {

}

void Caja::Dibuja() {
	inferior1.Dibuja();
	inferior2.Dibuja();
	plataforma1.Dibuja();
	plataforma2.Dibuja();
	plataforma3.Dibuja();
	plataforma4.Dibuja();
}