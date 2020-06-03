#include "Mundo.h"
#include <math.h>
#include <iostream>
#include <cstdlib>
#include "glut.h"
#include "ETSIDI.h"

using namespace std;

Mundo::Mundo() {
	FinLevel = false;
	muerte = false;
	nivel = 0;
}

Mundo::~Mundo() {
	Bolas.destruirContenido();
}

void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo + z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}

void Mundo::Dibuja()
{
	//void DibujarTexto(const char *texto, int longitud, int x, int y);
	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/marte.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-50,-10, -5);
	glTexCoord2d(1, 1); glVertex3f(100, -10, -5);
	glTexCoord2d(1, 0); glVertex3f(100, 50, -5);
	glTexCoord2d(0, 0); glVertex3f(-50, 50, -5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D); //no borrar!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	hombre.Dibuja();
	plataformas.Dibuja();
	enemigos.Dibuja();
	premios.Dibuja();
	puerta.Dibuja();
	disparos.Dibuja();
	Bolas.Dibuja();
	std::string texto;
	//texto.size = 20;
	texto = "SUPER BOLA BROS";
	DibujarTexto(texto.data(), texto.size(), x_ojo+320, 500);
}

void Mundo::Mueve(){
	if (hombre.GetVidas() == 0) {
		muerte = true;
	}


	hombre.Mueve(0.025f);
	enemigos.Mueve(0.0025f);
	disparos.Mueve(0.0025f);
	Bolas.Mueve(0.025f);

	enemigos.colision(plataformas);

	if (Bolas.Crear(0.025f) == true) {
		double i = -20 + (rand() % 47);
		Bolas.agregar(new EnemigoBolas(0.5f, i, 37));
	}

	for (int i = 0; i < enemigos.num(); i++) {
		Enemigo1 *auxi = enemigos[i];
		if (hombre.Muerte(hombre, auxi)) {
			
			hombre.restarVida();
			ETSIDI::play("sonidos/PacManDies.mp3");
			x_ojo = 7;
			nivel--;
			cargarNivel();
			premios.reset(hombre.GetNumPrem(Hombre::LLAVE), hombre.GetNumPrem(Hombre::MONEDA));
		}
	
		Disparo* var = disparos.colision(*auxi);
		if (var != 0) {
			disparos.Eliminar(var);
			enemigos.Eliminar(auxi);
			ETSIDI::play("sonidos/Bala.mp3");
		}
	}

	if (hombre.Muerte()) {
		hombre.restarVida();
		ETSIDI::play("sonidos/PacManDies.mp3");
		x_ojo = 7;
		nivel--;
		cargarNivel();
	}

	for (int i = 0; i < Bolas.getNumero(); i++) {
		EnemigoBolas* auxx = Bolas.colision(hombre);
		if (auxx != 0) { //si alguna esfera ha chocado 
			if (hombre.Muerte(hombre, auxx)) {
				hombre.restarVida();
				ETSIDI::play("sonidos/PacManDies.mp3");
				x_ojo = 7;
				nivel--;
				cargarNivel();
			}
			Bolas.Eliminar(auxx);
		}	
	}



	EnemigoBolas* auxiliar = Bolas.colision(plataformas);
	if (auxiliar != 0) {
		Bolas.Eliminar(auxiliar);
	}


	Pared* aux = plataformas.colision(hombre);
	if ((aux != 0) && ((hombre.GetPos().y - (hombre.GetAltura()/2)) >= aux->GetPos().y)) {
		salto = 1;
		hombre.SetAc(0,0);
		hombre.SetVel(0,0);
	}
	else if ((aux != 0) && ((hombre.GetPos().y - (hombre.GetAltura()/2)) <= aux->GetPos().y)) {
		salto = 0;
		hombre.SetAc(0, 0);
		hombre.SetVel(0, -5.0f);
	}
	else if (aux == 0) {
		salto = 0;
		hombre.SetAc(0, -9.8);
	}

	Premio* prem_aux = premios.colision(hombre);
	if (prem_aux != 0) {
		if (prem_aux->GetTipo() == Premio::LLAVE) {
			hombre.Premios(Hombre::LLAVE);
		}
		else if (prem_aux->GetTipo() == Premio::MONEDA) {
			hombre.Premios(Hombre::MONEDA);
		}
		premios.Eliminar(prem_aux);
		
	}


	/////////////////////////
	//CONDICIONES PARA PASARSE CADA NIVEL
	if (nivel == 1) {
		if (hombre.NumPremios(Hombre::MONEDA) >= 1) {
			premios.Eliminar(premios.buscar(Premio::REJA));
			premios.SetLibertad(premios.buscar(Premio::LLAVE), true);
		}
		if (hombre.NumPremios(Hombre::LLAVE) == 1) {
			if (hombre.NumPremios(Hombre::MONEDA) == 1) {
				puerta.DibujaPuertaAbierta();
				if (hombre.Choque(hombre, puerta)) {
					FinLevel = true;
					hombre.reset();
				}
			}
		}
	}
	if (nivel == 2) {
		if (hombre.NumPremios(Hombre::LLAVE) == 1) {
			puerta.SetColor(0, 0, 255);
			if (hombre.Choque(hombre, puerta)) {
				FinLevel = true;
				hombre.reset();
			}
		}
	}
	

}

void Mundo::Inicializa() {
	FinLevel = false;
	muerte = false;

	x_ojo = 7;
	y_ojo = 21;
	z_ojo = 70;
	
	cargarNivel();
}

void Mundo::Tecla(unsigned char key) {
	switch (key) {
	case ' ': {
		Vector2D pos = hombre.GetPos();
		Disparo* d = new Disparo(dispder, pos);
		disparos.agregar(d);
		break;
	}
	case 'z': {
		Vector2D pos = hombre.GetPos();
		DisparoSuper* disup = new DisparoSuper(dispder, pos);
		disparos.agregar(disup);
		break;
	}
	
	}
}

void Mundo::teclaEspecial(unsigned char key) {

	

	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (hombre.GetPos().x >= -20.85) {
			hombre.SetPos((hombre.GetPos().x) - 0.3, hombre.GetPos().y);
			if (x_ojo >= 7 && (hombre.GetPos().x) >= 4 && (hombre.GetPos().x) <= 56) {
				x_ojo -= 0.3;
				hombre.setposvidas(1);
			}
		}
		else {
			hombre.SetPos(-20.85, hombre.GetPos().y);
		}
		dispder = 0; 

		break;
	case GLUT_KEY_RIGHT:
		if (hombre.GetPos().x <= 84.85) {
			hombre.SetPos((hombre.GetPos().x) + 0.3, hombre.GetPos().y);
			if (x_ojo <= 57 && (hombre.GetPos().x) >= 4 && (hombre.GetPos().x) <= 56) {
				x_ojo += 0.3;
				hombre.setposvidas(0);
			}
		}
		else {
			hombre.SetPos(84.86, hombre.GetPos().y);
		}
		dispder = 1;

		break;

	case GLUT_KEY_UP:

		if (salto == 1) {
			hombre.SetVel(0, 10.0f);
			hombre.SetAc(0, -9.8f);
		}
		break;
	}

}

void Mundo::DibujarTexto(const char* texto, int longitud, int x, int y) {
	glMatrixMode(GL_PROJECTION);
	double* matla = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matla);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < longitud; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)texto[i]);

	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matla);
	glMatrixMode(GL_MODELVIEW);
}

bool Mundo::cargarNivel() {
	nivel++;
	FinLevel = false;
	x_ojo = 7;
	y_ojo = 21;
	z_ojo = 70;
	//hay que destruir cosas y eso
	enemigos.destruirContenido();
	premios.destruirContenido();


	if (nivel == 1) {
		hombre.SetPos(-10,7);

		Enemigo1* enemigo1 = new Enemigo1(-6.0f, 10.75f, -15.0f);
		Enemigo1* enemigo2 = new Enemigo1(64.0f, 10.76f, 15.05);
		enemigos.agregar(enemigo1);
		enemigos.agregar(enemigo2);


		Llave* llave = new Llave();
		llave->SetLlave(0.25, 0.5);
		llave->SetPos(30, 17);
		llave->SetLibertad(false);
		premios.agregar(llave);

		Reja* reja = new Reja();
		reja->SetPos(30, 17);
		reja->SetRadio(0.5);
		premios.agregar(reja);

		Monedas* moneda = new Monedas();
		moneda->SetRadio(0.5);
		moneda->SetPos(25, 6);
		premios.agregar(moneda);

		Pared* inferior1 = new Pared(-22, 1.01, 4, 1.01);
		inferior1->SetColor(0, 200, 0);
		plataformas.Agregar(inferior1);

		Pared* inferior2 = new Pared(15, 1, 45, 1);
		inferior2->SetColor(0, 200, 0);
		plataformas.Agregar(inferior2);

		Pared* inferior3 = new Pared(56, 1.01, 86, 1.01);
		inferior3->SetColor(0, 200, 0);
		plataformas.Agregar(inferior3);

		Pared* pared1 = new Pared(-22, 1, -22, 80);
		pared1->SetColor(0, 150, 0);
		plataformas.Agregar(pared1);

		Pared* pared2 = new Pared(86, 1, 86, 22);
		pared2->SetColor(0, 150, 0);
		plataformas.Agregar(pared2);

		Pared* plat1 = new Pared(3, 6, 16, 6);
		plat1->SetColor(100, 0, 0);
		plataformas.Agregar(plat1);
		Pared* plat2 = new Pared(-10, 10, -1, 10);
		plat2->SetColor(100, 0, 0);
		plataformas.Agregar(plat2);
		Pared* plat3 = new Pared(3, 14, 16, 14);
		plat3->SetColor(100, 0, 0);
		plataformas.Agregar(plat3);
		Pared* plat4 = new Pared(23, 12.5, 37, 12.5);
		plat4->SetColor(100, 0, 0);
		plataformas.Agregar(plat4);
		Pared* plat5 = new Pared(44, 14, 57, 14);
		plat5->SetColor(100, 0, 0);
		plataformas.Agregar(plat5);
		Pared* plat6 = new Pared(44, 6, 57, 6);
		plat6->SetColor(100, 0, 0);
		plataformas.Agregar(plat6);
		Pared* plat7 = new Pared(61, 10.01, 70, 10.01);
		plat7->SetColor(100, 0, 0);
		plataformas.Agregar(plat7);

		puerta.SetColor(130, 27, 5);
		puerta.SetPos(28.5, 10, 31.5, 0);
	}
	if (nivel == 2) {
		hombre.SetPos(-10, 7);

		Llave* llave = new Llave();
		llave->SetLlave(0.25, 0.5);
		llave->SetPos(30, 17);
		premios.agregar(llave);

		Pared* inferior1 = new Pared(-22, 1.01, 4, 1.01);
		inferior1->SetColor(0, 200, 0);
		plataformas.Agregar(inferior1);

		Pared* inferior2 = new Pared(15, 1, 45, 1);
		inferior2->SetColor(0, 200, 0);
		plataformas.Agregar(inferior2);

		Pared* inferior3 = new Pared(56, 1.01, 86, 1.01);
		inferior3->SetColor(0, 200, 0);
		plataformas.Agregar(inferior3);

		Pared* pared1 = new Pared(-22, 1, -22, 22);
		pared1->SetColor(0, 150, 0);
		plataformas.Agregar(pared1);

		Pared* pared2 = new Pared(86, 1, 86, 22);
		pared2->SetColor(0, 150, 0);
		plataformas.Agregar(pared2);

		Pared* plat1 = new Pared(3, 6, 16, 6);
		plat1->SetColor(100, 0, 0);
		plataformas.Agregar(plat1);
		Pared* plat2 = new Pared(-10, 10, -1, 10);
		plat2->SetColor(100, 0, 0);
		plataformas.Agregar(plat2);
		Pared* plat3 = new Pared(3, 14, 16, 14);
		plat3->SetColor(100, 0, 0);
		plataformas.Agregar(plat3);
		Pared* plat4 = new Pared(23, 12.5, 37, 12.5);
		plat4->SetColor(100, 0, 0);
		plataformas.Agregar(plat4);
		Pared* plat5 = new Pared(44, 14, 57, 14);
		plat5->SetColor(100, 0, 0);
		plataformas.Agregar(plat5);
		Pared* plat6 = new Pared(44, 6, 57, 6);
		plat6->SetColor(100, 0, 0);
		plataformas.Agregar(plat6);
		Pared* plat7 = new Pared(61, 10.01, 70, 10.01);
		plat7->SetColor(100, 0, 0);
		plataformas.Agregar(plat7);

		puerta.SetColor(0, 27, 5);
		puerta.SetPos(28.5, 6, 31.5, 0);
	}
	if (nivel <= 2) {
		return true;
	}
	return false;
}

void Mundo::reset() {
	nivel = 1;
	int v = 3 - hombre.GetVidas();//para que solo puedas tener max 3 vidas, ya que lo llamamos tb cuando terminas todos los levels
	for (int i = 0; i < v; i++) {
		hombre.aumentarVida();
	}
	muerte = false;
	nivel = 0;
}