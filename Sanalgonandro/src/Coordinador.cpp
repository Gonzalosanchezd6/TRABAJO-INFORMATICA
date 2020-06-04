#include "Coordinador.h"
#include "ETSIDI.h"
#include <sstream>
#include <iostream>


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
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GAMEOVER.png").id);
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
	else if (estado == FIN) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/FINALSCORE.png").id);
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
		
		std::stringstream sstr2;
		std::string textoklk2;
		//LLAVE
		
		sstr2 << mundo.getNum(Mundo::LLAVE);//////////////////////////////////////////////////////
		textoklk2 = sstr2.str();
		glDisable(GL_LIGHTING);
		glColor3ub(81, 209, 246);
		mundo.DibujarTexto(textoklk2.data(), textoklk2.size(), 520, 370);//x_ojo
		glEnable(GL_LIGHTING);

		std::stringstream sstr3;
		std::string textoklk3;
		sstr3 << mundo.getNum(Mundo::MONEDA);//////////////////////////////////////////////////////
		textoklk3 = sstr3.str();
		glDisable(GL_LIGHTING);
		glColor3ub(81, 209, 246);
		mundo.DibujarTexto(textoklk3.data(), textoklk3.size(), 520, 480);//x_ojo
		glEnable(GL_LIGHTING);


		std::stringstream sstr4;
		std::string textoklk4;
		sstr4 << mundo.getNum(Mundo::VIDA);//////////////////////////////////////////////////////
		textoklk4 = sstr4.str();
		glDisable(GL_LIGHTING);
		glColor3ub(81, 209, 246);
		mundo.DibujarTexto(textoklk4.data(), textoklk4.size(), 520, 425);//x_ojo
		glEnable(GL_LIGHTING);

		std::stringstream sstr5;
		std::string textoklk5;
		sstr5 << mundo.getNum(Mundo::PISTOLA);//////////////////////////////////////////////////////
		textoklk5 = sstr5.str();
		glDisable(GL_LIGHTING);
		glColor3ub(81, 209, 246);
		mundo.DibujarTexto(textoklk5.data(), textoklk5.size(), 520, 320);//x_ojo
		glEnable(GL_LIGHTING);

		/*ETSIDI::setFont("fuentesRevamped-X3q1a.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -7, 10);
		//hay que imprimir las puntuaciones, los objetos recogidos estan en listaPremios
		ETSIDI::printxy("Pulsa -C- para continuar", -7, 9);*/
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
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/NIVEL 2.png").id);
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
		else if (mundo.GetNivel() == 3) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/NIVEL 3.png").id);
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
		else if (mundo.GetNivel() == 4) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/NIVEL4.png").id);
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
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/MENUPAUSA.png").id);
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
