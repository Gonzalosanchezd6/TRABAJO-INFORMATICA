#include "Coordinador.h"
#include "ETSIDI.h"

Coordinador::Coordinador() {
	estado = INICIO;
}

Coordinador::~Coordinador() {

}

void Coordinador::Mueve() {
	if (estado == JUEGO) {
		mundo.Mueve();
		if (mundo.GetMuerte()) {
			estado = GAMEOVER;
			ETSIDI::play("sonidos/GameOver.mp3");
		}
		else if (mundo.GetFin()) {
			estado = HISTORIA;
			ETSIDI::play("sonidos/YouWin.mp3");
		}
	}
}

void Coordinador::Dibuja() {
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("SUPER BOLA BROS", -10, 17);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Creadores: Sanalgonandro", -10, 16.4);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
	}
	else if (estado == JUEGO) {
		mundo.Dibuja();
	}
	else if (estado == GAMEOVER) {
		mundo.Dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Te has quedado sin vidas", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN) {
		mundo.Dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
	else if (estado == HISTORIA) {
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("--Inserte texto aqui jeje xd--", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}

void Coordinador::Tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key == 'e') {
			mundo.Inicializa();
			estado = JUEGO;
		}
		if (key == 's') {
			exit(0);
		}
	}
	else if (estado == JUEGO) {
		mundo.Tecla(key);
	}
	else if (estado == GAMEOVER) {
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN) {
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == HISTORIA) {
		if (key == 'c') {
			estado = JUEGO;
		}
	}
}

void Coordinador::teclaEspecial(unsigned char key) {
	if (estado == JUEGO) {
		mundo.teclaEspecial(key);
	}
}
