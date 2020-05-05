#include "Mundo.h"
#include <math.h>
#include <iostream>
#include "glut.h"

using namespace std;

Mundo::Mundo() {
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
	hombre.Dibuja();
	plataformas.Dibuja();
	enemigos.dibuja();
	premios.Dibuja();
	puerta.Dibuja();
	disparos.dibuja();
	Bolas.dibuja();
	std::string texto;
	//texto.size = 20;
	texto = "maldita gordeyuyu";
	DibujarTexto(texto.data(), texto.size(), 200, 300);
}

void Mundo::Mueve(){
	hombre.Mueve(0.025f);
	enemigos.mueve(0.0025f);
	disparos.mueve(0.0025f);
	Bolas.mueve(0.025f);

	//////////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < enemigos.num(); i++) {
		Enemigo1 *auxi = enemigos[i];
		if (hombre.Muerte(hombre, *auxi)) {
			hombre.restarVida();
			x_ojo = 0;
		}
	
		Disparo* var = disparos.colision(*auxi);
		if (var != 0) {
			disparos.Eliminar(var);
			enemigos.Eliminar(auxi);
		}
	}

	
	for (int i = 0; i < Bolas.getNumero(); i++) {
		EnemigoBolas* auxx = Bolas.choque(hombre);
		if (auxx != 0) { //si alguna esfera ha chocado 
			if (hombre.Muerte(hombre, *auxx)) {
				hombre.restarVida();
				x_ojo = 0;
			}
			Bolas.eliminar(auxx);
		}	
	}

	EnemigoBolas* auxiliar = Bolas.choque(plataformas);
	if (auxiliar != 0) {
		Bolas.eliminar(auxiliar);
	}


	Pared* aux = plataformas.Colision(hombre);
	if (aux != 0 && (hombre.GetPos().y - (hombre.GetAltura()-0.25)) >= aux->GetPos().y) {
		salto = 1;
		hombre.SetAc(0,0);
		hombre.SetVel(0,0);
	}
	else if (aux != 0 && (hombre.GetPos().y - (hombre.GetAltura()-0.25)) <= aux->GetPos().y) {
		salto = 0;
		hombre.SetAc(0, 0);
		hombre.SetVel(0, -5.0f);
	}
	else if (aux == 0) {
		salto = 0;
		hombre.SetAc(0, -9.8);
	}

	Llave* prem_aux = premios.colision(hombre);
	if (prem_aux != 0) {
		premios.Eliminar(prem_aux);
		hombre.Premios(Hombre::LLAVE);
		if (hombre.NumPremios(Hombre::LLAVE) == 1) {
			puerta.SetColor(0, 0, 255);
		}
	}

	//ESTO NO LO BORREIS, ES PARA PASAR DE NIVEL
	/*if (hombre.Choque(hombre, puerta)) {
		
	}*/

}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 21;
	z_ojo = 70;
	
	hombre.SetPos(-10, 7);
	
	Enemigo1* enemigo1 = new Enemigo1(11.0f, 15.75f, -15.0f);
	Enemigo1* enemigo2= new Enemigo1(11.0f, 1.75f,15.05);
	enemigos.agregar(enemigo1);
	enemigos.agregar(enemigo2);
	

	Llave* llave = new Llave();
	llave->SetLlave(0.25, 0.5);
	llave->SetPos(25, 22);
	premios.agregar(llave);

	Pared* inferior1 = new Pared(-22, 1, 2, 1);
	inferior1->SetColor(0, 200, 0);
	plataformas.Agregar(inferior1);

	Pared* inferior2 = new Pared(6, 1, 25, 1);
	inferior2->SetColor(0, 200, 0);
	plataformas.Agregar(inferior2);

	Pared* plat1 = new Pared(-13, 5, -5, 5);
	plat1->SetColor(100, 0, 0);
	plataformas.Agregar(plat1);
	Pared* plat2 = new Pared(-3, 10, 5, 10);
	plat2->SetColor(100, 0, 0);
	plataformas.Agregar(plat2);
	Pared* plat3 = new Pared(7, 15, 15, 15);
	plat3->SetColor(100, 0, 0);
	plataformas.Agregar(plat3);
	Pared* plat4 = new Pared(17, 20, 25, 20);
	plat4->SetColor(100, 0, 0);
	plataformas.Agregar(plat4);

	puerta.SetColor(130, 27, 5);
	puerta.SetPos(20, 6, 23, 0);
}

void Mundo::Tecla(unsigned char key) {
	switch (key) {
	case ' ': {

		Vector2D pos = hombre.GetPos();
		Disparo* d = new Disparo(pos);
		disparos.agregar(d);
		break;
	}
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.SetPos((hombre.GetPos().x) - 0.3 , hombre.GetPos().y);
		x_ojo -= 0.3;
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetPos((hombre.GetPos().x) + 0.3, hombre.GetPos().y);
		x_ojo += 0.3;
		Bolas.agregar(new EnemigoBolas(0.5f, 0, 37));
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