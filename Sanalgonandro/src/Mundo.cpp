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
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::Dibuja()
{
	//void DibujarTexto(const char *texto, int longitud, int x, int y);
	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

	glEnable(GL_TEXTURE_2D);
	if (GetNivel() == 1) {
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Moon.png").id);
	}
	else if (GetNivel() == 2) {
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/marte.png").id);
	}
	else if (GetNivel() == 3) {
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Jupiter.png").id);
	}
	else if (GetNivel() == 4) {
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Saturn.png").id);
	}

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-50, -10, -5);
	glTexCoord2d(1, 1); glVertex3f(100, -10, -5);
	glTexCoord2d(1, 0); glVertex3f(100, 50, -5);
	glTexCoord2d(0, 0); glVertex3f(-50, 50, -5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//no borrar!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	vidas.Dibuja();
	hombre.Dibuja();
	plataformas.Dibuja();
	enemigos.Dibuja();
	premios.Dibuja();
	puerta.Dibuja();
	disparos.Dibuja();
	Bolas.Dibuja();
	std::string texto;
	//texto.size = 20;
	/*texto = "GALAXY TROUBLE";
	DibujarTexto(texto.data(), texto.size(), x_ojo+320, 500);*/
}

void Mundo::Mueve() {
	if (hombre.GetVidas() == 0) {
		muerte = true;
	}

	vidas.Eliminar(hombre.GetVidas());
	hombre.Mueve(0.025f);
	enemigos.Mueve(0.0025f);
	disparos.Mueve(0.0025f);
	plataformas.Mueve(0.001f);
	Bolas.Mueve(0.025f);
	vidas.Mueve(0.025f);
	enemigos.colision(plataformas);

	if (Bolas.Crear(CrearBola) == true) {
		double i = -20 + (rand() % 86);
		Bolas.agregar(new EnemigoBolas(0.5f, i, 37));
	}

	for (int i = 0; i < enemigos.num(); i++) {
		Enemigo1* auxi = enemigos[i];
		if (hombre.Muerte(hombre, auxi)) {
			premios.reset(hombre.GetNumPrem(Hombre::LLAVE), hombre.GetNumPrem(Hombre::MONEDA));
			hombre.restarVida();
			ETSIDI::play("sonidos/PacManDies.mp3");
			x_ojo = 7;
			nivel--;
			cargarNivel();
		}
		Disparo* var = disparos.colision(*auxi);
		if (var != 0) {
			PosEne = auxi->GetPos();
			if (disparos.GetEsp(var)) {
				enemigos.restarVida(auxi);
			}
			enemigos.restarVida(auxi);
			if (enemigos.GetVidas(auxi) <= 0) {
				double i = (rand() % 100);
				if (auxi->GetTipo()) {
					Llave* llave = new Llave();
					llave->SetPos(PosEne.x, PosEne.y + 1);
					premios.agregar(llave);
				}
				else {
					if (i <= 20) {
						PremioVida* vid = new PremioVida();
						vid->SetPos(PosEne.x, PosEne.y + 1);
						premios.agregar(vid);
					}
					else if (i <= 40) {
						Pistola* pis = new Pistola();
						pis->SetPos(PosEne.x, PosEne.y + 1);
						premios.agregar(pis);
					}
				}
				enemigos.Eliminar(auxi);
				//random value 20% corazon, 20% pistola, 60% nada
				ETSIDI::play("sonidos/Bala.mp3");
			}
			disparos.Eliminar(var);
		}
	}

	if (hombre.Muerte()) {
		premios.reset(hombre.GetNumPrem(Hombre::LLAVE), hombre.GetNumPrem(Hombre::MONEDA));
		hombre.restarVida();
		ETSIDI::play("sonidos/PacManDies.mp3");
		x_ojo = 7;
		nivel--;
		cargarNivel();
	}


	for (int i = 0; i < Bolas.num(); i++) {
		EnemigoBolas* auxx = Bolas.colision(hombre);
		if (auxx != 0) { //si alguna esfera ha chocado 
			if (hombre.Muerte(hombre, auxx)) {
				premios.reset(hombre.GetNumPrem(Hombre::LLAVE), hombre.GetNumPrem(Hombre::MONEDA));
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
	if ((aux != 0) && ((hombre.GetPos().y - (hombre.GetAltura() / 2)) >= aux->GetPos().y)) {
		salto = 1;
		hombre.SetAc(0, 0);
		hombre.SetVel(0, 0);
	}
	else if ((aux != 0) && ((hombre.GetPos().y - (hombre.GetAltura() / 2)) <= aux->GetPos().y)) {
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
		else if (prem_aux->GetTipo() == Premio::VIDA) {
			hombre.aumentarVida();
			Vida* vid = new Vida(vidas.posVida1().x + (hombre.GetVidas() - 1) * 3, 40);
			vidas.agregar(vid);
		}
		else if (prem_aux->GetTipo() == Premio::PISTOLA) {
			hombre.DisparoEsp();
		}
		premios.Eliminar(prem_aux);

	}
	/////////////////////////
	//CONDICIONES PARA PASARSE CADA NIVEL
	if (nivel == 1) {
		if (hombre.NumPremios(Hombre::LLAVE) == 1) {
			puerta.DibujaPuertaAbierta();
			if (hombre.Choque(hombre, puerta)) {
				FinLevel = true;
				hombre.reset();
			}
		}
	}
	if (nivel == 2) {
		if (hombre.NumPremios(Hombre::MONEDA) >= 5) {
			premios.Eliminar(premios.buscar(Premio::REJA));
			premios.SetLibertad(premios.buscar(Premio::LLAVE), true);
		}
		if (hombre.NumPremios(Hombre::LLAVE) == 1) {
			puerta.DibujaPuertaAbierta();
			if (hombre.Choque(hombre, puerta)) {
				FinLevel = true;
				hombre.reset();
			}
		}
	}
	if (nivel == 3) {
		if (hombre.NumPremios(Hombre::MONEDA) >= 4) {
			premios.Eliminar(premios.buscar(Premio::REJA));
			premios.SetLibertad(premios.buscar(Premio::LLAVE), true);
		}
		if (hombre.NumPremios(Hombre::LLAVE) == 1) {
			puerta.DibujaPuertaAbierta();
			if (hombre.Choque(hombre, puerta)) {
				FinLevel = true;
				hombre.reset();
			}
		}
	}
	if (nivel == 4) {
		if (hombre.NumPremios(Hombre::LLAVE) == 1) {
			puerta.DibujaPuertaAbierta();
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
		if (disparos.num() == 0) {
			if (hombre.GetDispEsp()) {
				Vector2D pos = hombre.GetPos();
				DisparoSuper* disup = new DisparoSuper(dispder, pos);
				disparos.agregar(disup);
				hombre.RestarDisp();
			}
		}
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
				vidas.setpos(1);
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
				vidas.setpos(0);
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
	vidas.posIni();
	//hay que destruir cosas y eso
	enemigos.destruirContenido();
	premios.destruirContenido();
	plataformas.destruirContenido();
	disparos.destruirContenido();
	Bolas.destruirContenido();


	if (nivel == 1) {
		hombre.SetPos(-10, 7);
		CrearBola = 0;

		Enemigo1* enemigo1 = new Enemigo1(-6.0f, 12.0f, -15.0f);
		Enemigo1* enemigo2 = new Enemigo1(64.0f, 12.01f, 15.05);
		enemigos.agregar(enemigo1);
		enemigos.agregar(enemigo2);

		Llave* llave = new Llave();
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

		puerta.SetPos(28.5, 10, 31.5, 0);
		puerta.PuertaCerrada();

		for (int i = 0; i < hombre.GetVidas(); i++) {
			Vida* aux = new Vida(-20 + i * 3, 40);
			vidas.agregar(aux);
		}
	}
	if (nivel == 2) {
		hombre.SetPos(-10, 7);
		CrearBola = 0.025f;

		Llave* llave = new Llave();
		llave->SetPos(80, 5);
		llave->SetLibertad(false);
		premios.agregar(llave);

		Reja* reja = new Reja();
		reja->SetPos(80, 5);
		premios.agregar(reja);

		Pared* inferior1 = new Pared(-22, 1.01, 10, 1.01);
		inferior1->SetColor(0, 200, 0);
		plataformas.Agregar(inferior1);

		Pared* inferior2 = new Pared(54, 1.01, 86, 1.01);
		inferior2->SetColor(0, 200, 0);
		plataformas.Agregar(inferior2);

		Pared* pared1 = new Pared(-22, 1, -22, 22);
		pared1->SetColor(0, 150, 0);
		plataformas.Agregar(pared1);

		Pared* pared2 = new Pared(86, 1, 86, 22);
		pared2->SetColor(0, 150, 0);
		plataformas.Agregar(pared2);

		Pared* plat1 = new Pared(-1, 6.01f, 8, 6.01f);
		plat1->SetColor(100, 0, 0);
		plataformas.Agregar(plat1);
		Pared* plat2 = new Pared(-4, 10.25, 5, 10.25);
		plat2->SetColor(100, 0, 0);
		plataformas.Agregar(plat2);
		Pared* plat3 = new Pared(-1, 15.1f, 8, 15.1f);
		plat3->SetColor(100, 0, 0);
		plataformas.Agregar(plat3);
		Pared* plat4 = new Pared(-4, 19.51, 5, 19.51);
		plat4->SetColor(100, 0, 0);
		plataformas.Agregar(plat4);
		Pared* plat5 = new Pared(58, 6.0f, 67, 6.0f);
		plat5->SetColor(100, 0, 0);
		plataformas.Agregar(plat5);
		Pared* plat6 = new Pared(55, 10.5, 64, 10.5);
		plat6->SetColor(100, 0, 0);
		plataformas.Agregar(plat6);
		Pared* plat7 = new Pared(58.5, 15.0f, 67.5, 15.0f);
		plat7->SetColor(100, 0, 0);
		plataformas.Agregar(plat7);
		Pared* plat8 = new Pared(55, 19.5, 64, 19.5);
		plat8->SetColor(100, 0, 0);
		plataformas.Agregar(plat8);
		Pared* plat9 = new Pared(12, 23, 23, 23);
		plat9->SetColor(100, 0, 0);
		plataformas.Agregar(plat9);
		Pared* plat10 = new Pared(25.5, 18, 32.5, 18);
		plat10->SetColor(100, 0, 0);
		plataformas.Agregar(plat10);
		Pared* plat11 = new Pared(37, 23.01, 48, 23.01);
		plat11->SetColor(100, 0, 0);
		plataformas.Agregar(plat11);

		Monedas* moneda1 = new Monedas();
		moneda1->SetRadio(0.5);
		moneda1->SetPos(-17, 16);
		premios.agregar(moneda1);

		Monedas* moneda2 = new Monedas();
		moneda2->SetRadio(0.5);
		moneda2->SetPos(3, 2.5);
		premios.agregar(moneda2);

		Monedas* moneda3 = new Monedas();
		moneda3->SetRadio(0.5);
		moneda3->SetPos(29, 20);
		premios.agregar(moneda3);

		Monedas* moneda4 = new Monedas();
		moneda4->SetRadio(0.5);
		moneda4->SetPos(81, 16);
		premios.agregar(moneda4);

		Monedas* moneda5 = new Monedas();
		moneda5->SetRadio(0.5);
		moneda5->SetPos(59.5, 12.5);
		premios.agregar(moneda5);

		Enemigo1* enemigo4 = new Enemigo1(62.4f, 8.0f, 15.0f);
		Enemigo1* enemigo1 = new Enemigo1(0.5f, 12.25, -15.0f);
		Enemigo1* enemigo2 = new Enemigo1(16.5f, 25, 15.0f);
		Enemigo1* enemigo3 = new Enemigo1(62.5f, 17.0f, -15.0f);
		enemigos.agregar(enemigo4);
		enemigos.agregar(enemigo1);
		enemigos.agregar(enemigo2);
		enemigos.agregar(enemigo3);

		puerta.SetPos(-18, 10, -14.5, 0);
		puerta.PuertaCerrada();

		for (int i = 0; i < hombre.GetVidas(); i++) {
			Vida* aux = new Vida(-20 + i * 3, 40);
			vidas.agregar(aux);
		}
	}

	if (nivel == 3) {
		hombre.SetPos(-10, 3);
		CrearBola = 0.035f;

		Llave* llave = new Llave();
		llave->SetPos(2, 7);
		llave->SetLibertad(false);
		premios.agregar(llave);

		Reja* reja = new Reja();
		reja->SetPos(2, 7);
		premios.agregar(reja);

		Pared* inferior1 = new Pared(-22, 1.11, 10, 1.11);
		inferior1->SetColor(0, 200, 0);
		plataformas.Agregar(inferior1);

		Pared* inferior2 = new Pared(49, 1.01, 85, 1.01);
		inferior2->SetColor(0, 200, 0);
		plataformas.Agregar(inferior2);

		Pared* inferior3 = new Pared(84, 1.11, 86, 1.11);
		inferior3->SetColor(0, 200, 0);
		plataformas.Agregar(inferior3);

		Pared* pared1 = new Pared(-22, 1, -22, 22);
		pared1->SetColor(0, 150, 0);
		plataformas.Agregar(pared1);

		Pared* pared2 = new Pared(86, 1, 86, 22);
		pared2->SetColor(0, 150, 0);
		plataformas.Agregar(pared2);

		Pared* plat1 = new Pared(-17, 6, -8, 6);
		plat1->SetColor(100, 0, 0);
		plataformas.Agregar(plat1);
		Pared* plat2 = new Pared(-14, 10.5, -5, 10.5);
		plat2->SetColor(100, 0, 0);
		plataformas.Agregar(plat2);
		Pared* plat3 = new Pared(-17, 15, -8, 15);
		plat3->SetColor(100, 0, 0);
		plataformas.Agregar(plat3);
		Pared* plat4 = new Pared(-14, 19.5, -5, 19.5);
		plat4->SetColor(100, 0, 0);
		plataformas.Agregar(plat4);
		Pared* plat5 = new Pared(24.5, 19.6, 34.5, 19.6);
		plat5->SetColor(100, 0, 0);
		plataformas.Agregar(plat5);
		Pared* plat6 = new Pared(65, 19.5, 74, 19.5);
		plat6->SetColor(100, 0, 0);
		plataformas.Agregar(plat6);

		PlatMovil* mov1 = new PlatMovil(5, 19.5, 14, 19.5);
		mov1->SetColor(100, 0, 0);
		plataformas.Agregar(mov1);
		PlatMovil* mov2 = new PlatMovil(45, 19.5, 54, 19.5);
		mov2->SetColor(100, 0, 0);
		plataformas.Agregar(mov2);
		PlatMovil* mov3 = new PlatMovil(25, 3, 34, 3);
		mov3->SetColor(100, 0, 0);
		plataformas.Agregar(mov3);

		Monedas* moneda1 = new Monedas();
		moneda1->SetRadio(0.5);
		moneda1->SetPos(29, 10);
		premios.agregar(moneda1);

		Monedas* moneda2 = new Monedas();
		moneda2->SetRadio(0.5);
		moneda2->SetPos(29, 24);
		premios.agregar(moneda2);

		Monedas* moneda3 = new Monedas();
		moneda3->SetRadio(0.5);
		moneda3->SetPos(-18, 17);
		premios.agregar(moneda3);

		Monedas* moneda4 = new Monedas();
		moneda4->SetRadio(0.5);
		moneda4->SetPos(81, 16);
		premios.agregar(moneda4);

		Enemigo1* enemigo1 = new Enemigo1(-9.5f, 12.5, -15.0f);
		enemigos.agregar(enemigo1);
		Enemigo2vidas* enemigo2 = new Enemigo2vidas(29.5f, 21.6f, 15.0f);
		enemigos.agregar(enemigo2);
		Enemigo2vidas* enemigo4 = new Enemigo2vidas(65, 3.01f, 15.0f);
		enemigos.agregar(enemigo4);

		puerta.SetPos(80, 10, 83, 0);
		puerta.PuertaCerrada();

		for (int i = 0; i < hombre.GetVidas(); i++) {
			Vida* aux = new Vida(-20 + i * 3, 40);
			vidas.agregar(aux);
		}
	}

	if (nivel == 4) {
		hombre.SetPos(-16, 7);
		CrearBola = 0.015f;

		Pared* inferior1 = new Pared(-22, 1.11, -10, 1.11);
		inferior1->SetColor(0, 200, 0);
		plataformas.Agregar(inferior1);

		Pared* inferior2 = new Pared(49, 1.01, 85, 1.01);
		inferior2->SetColor(0, 200, 0);
		plataformas.Agregar(inferior2);

		Pared* inferior3 = new Pared(84, 1.11, 86, 1.11);
		inferior3->SetColor(0, 200, 0);
		plataformas.Agregar(inferior3);

		Pared* pared1 = new Pared(-22, 1, -22, 22);
		pared1->SetColor(0, 150, 0);
		plataformas.Agregar(pared1);

		Pared* pared2 = new Pared(86, 1, 86, 22);
		pared2->SetColor(0, 150, 0);
		plataformas.Agregar(pared2);

		Pared* plat1 = new Pared(-14, 6, -5, 6);
		plat1->SetColor(100, 0, 0);
		plataformas.Agregar(plat1);
		Pared* plat2 = new Pared(0, 10.5, 9, 10.5);
		plat2->SetColor(100, 0, 0);
		plataformas.Agregar(plat2);
		Pared* plat3 = new Pared(42, 15, 51, 15);
		plat3->SetColor(100, 0, 0);
		plataformas.Agregar(plat3);
		Pared* plat4 = new Pared(59, 15, 68, 15);
		plat4->SetColor(100, 0, 0);
		plataformas.Agregar(plat4);

		PlatMovil* mov1 = new PlatMovil(18, 15, 27, 15);
		mov1->SetColor(100, 0, 0);
		plataformas.Agregar(mov1);

		Enemigo2vidas* enemigo2 = new Enemigo2vidas(4.5f, 12.5f, 15.0f);
		enemigos.agregar(enemigo2);
		EnemigoFinal* enemigo4 = new EnemigoFinal(65, 3.01f, 25.0f);
		enemigos.agregar(enemigo4);

		puerta.SetPos(80, 10, 83, 0);
		puerta.PuertaCerrada();

		for (int i = 0; i < hombre.GetVidas(); i++) {
			Vida* aux = new Vida(-20 + i * 3, 40);
			vidas.agregar(aux);
		}

	}

	if (nivel <= 4) {
		return true;
	}
	return false;
}

void Mundo::reset() {
	nivel = 1;
	while (hombre.GetVidas()) {
		hombre.restarVida();
	}
	vidas.destruirContenido();
	for (int i = 0; i < 3; i++) {
		Vida* aux = new Vida(-20 + i * 3, 40);
		vidas.agregar(aux);
		hombre.aumentarVida();
	}

	muerte = false;
	nivel = 0;
}