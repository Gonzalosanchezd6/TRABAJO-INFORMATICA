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
			if (mundo.cargarNivel()) {
				estado = HISTORIA;
			}
			else {
				estado = FIN;
				ETSIDI::play("sonidos/YouWin.mp3");
			}
			
		}
	}
}

void Coordinador::Dibuja() {
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/PANTALLAINICIAL.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-80, -40, -118);
		glTexCoord2d(1, 1); glVertex3f(80, -40, -118);
		glTexCoord2d(1, 0); glVertex3f(80, 55, -118);
		glTexCoord2d(0, 0); glVertex3f(-80, 55, -118);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else if (estado == JUEGO) {

			mundo.Dibuja();

		
	}
	else if (estado == GAMEOVER) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Revamped-X3q1a.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Te has quedado sin vidas", -7, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -7, 5);
	}
	else if (estado == FIN) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setFont("fuentesRevamped-X3q1a.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -7, 10);
		//hay que imprimir las puntuaciones, los objetos recogidos estan en listaPremios
		ETSIDI::printxy("Pulsa -C- para continuar", -7, 9);
	}
	else if (estado == HISTORIA) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		if (mundo.GetNivel() == 1) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/HISTORIA-MUNDO1.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-80, -40, -118);
			glTexCoord2d(1, 1); glVertex3f(80, -40, -118);
			glTexCoord2d(1, 0); glVertex3f(80, 55, -118);
			glTexCoord2d(0, 0); glVertex3f(-80, 55, -118);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
		else if (mundo.GetNivel() == 2) {
			ETSIDI::setFont("fuentes/Revamped-X3q1a.ttf", 16);
			ETSIDI::printxy("--nivel 1 -> nivel 2--", -7, 10);
			ETSIDI::printxy("Pulsa -C- para continuar", -7, 9);
			
		}
		else if (mundo.GetNivel() == 3) {
			ETSIDI::setFont("fuentes/Revamped-X3q1a.ttf", 16);
			ETSIDI::printxy("--nivel 2 -> nivel 3--", -7, 10);
			ETSIDI::printxy("Pulsa -C- para continuar", -7, 9);
		}
		else if (mundo.GetNivel() == 4) {
			ETSIDI::setFont("fuentes/Revamped-X3q1a.ttf", 16);
			ETSIDI::printxy("--nivel 3 -> nivel 4--", -7, 10);
			ETSIDI::printxy("Pulsa -C- para continuar", -7, 9);
		}
		
	}
	else if (estado == INSTRUCCIONES) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/INSTRUCCIONES.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-80, -40, -118);
		glTexCoord2d(1, 1); glVertex3f(80, -40, -118);
		glTexCoord2d(1, 0); glVertex3f(80, 55, -118);
		glTexCoord2d(0, 0); glVertex3f(-80, 55, -118);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else if (estado == PAUSA) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/Revamped-X3q1a.ttf", 24);
		ETSIDI::printxy("PAUSA", -7, 16);
		ETSIDI::setFont("fuentes/Revamped-X3q1a.ttf", 16);
		ETSIDI::printxy("--Inserte texto aqui jeje xd (meteria las instrucciones aqui tb)--", -7, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -7, 9);
	}
}

void Coordinador::Tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key == 'e') {
			mundo.Inicializa();
			estado = HISTORIA;
		}
		if (key == 's') {
			exit(0);
		}if (key == 'i') {
			estado = INSTRUCCIONES;
		}
	}
	else if (estado == JUEGO) {
		mundo.Tecla(key);
		if (key == 'p') {
			estado = PAUSA;
		}
	}
	else if (estado == GAMEOVER) {
		if (key == 'c')
			mundo.reset();
			estado = INICIO;
	}
	else if (estado == FIN) {
		if (key == 'c')
			mundo.reset();
			estado = INICIO;
	}
	else if (estado == HISTORIA) {
		if (key == 'c') {
			estado = JUEGO;
		}
	}
	else if (estado == INSTRUCCIONES) {
		if (key == 'c') {
			estado = INICIO;
		}
	}
	else if (estado == PAUSA) {
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
