#include "Mundo.h"
#include <math.h>
#include "glut.h"

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
	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	hombre.Dibuja();
	plataformas.Dibuja();
	enemigo1.Dibuja();
	premios.Dibuja();
	puerta.Dibuja();
	//llave.Dibuja();
	//caja.Dibuja();
	//bloque.Dibuja();
	/*esfera.Dibuja();
	esfera2.Dibuja();
	caja.Dibuja();
	disparo.Dibuja();
	plataforma.Dibuja();
	bonus.Dibuja();*/
}

void Mundo::Mueve()
{
	hombre.Mueve(0.025f);
	enemigo1.Mueve(0.0025f);
	if (hombre.Muerte(hombre, enemigo1)) {
		hombre.SetPos(-10, 7);
		hombre.SetAc(0, -8);
		hombre.SetVel(0, 0);
		x_ojo = 0;
	}
	Pared* aux = plataformas.Colision(hombre);
	if (aux != 0) {
		salto = 1;
		hombre.SetAc(0,0);
		hombre.SetVel(0,0);
	}
	else if (aux == 0) {
		salto = 0;
		hombre.SetAc(0, -9.8);
	}

	Llave* prem_aux = premios.colision(hombre);
	if (aux != 0) {
		premios.Eliminar(prem_aux);
	}

	//Interaccion::rebote(hombre, caja);
	/*esfera.Mueve(0.025f);
	esfera2.Mueve(0.025f);
	bonus.Mueve(0.025f);
	disparo.Mueve(0.025f);
	Interaccion::rebote(esfera, caja);
	Interaccion::rebote(esfera, plataforma);
	Interaccion::rebote(esfera2, caja);
	Interaccion::rebote(esfera2, plataforma);
	Interaccion::rebote(esfera, esfera2);*/
	

}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 21;
	z_ojo = 70;
	/*esfera.SetPos(2, 4);
	esfera.SetRadio(1.5f);
	esfera.SetColor(0, 0, 255);
	esfera.SetVel(5, 15);
	esfera2.SetColor(200, 60, 10);
	esfera2.SetRadio(2);
	esfera2.SetPos(-2, 4);
	esfera2.SetVel(-5, 15);
	bonus.SetPos(5.0f, 5.0f);
	disparo.SetPos(-5.0, 0.0);
	plataforma.SetPos(-5.0f, 9.0f, 5.0f, 9.0f);*/
	hombre.SetPos(-10, 7);
	enemigo1.SetPos(11, 15.75);

	Llave* llave = new Llave();
	llave->SetLlave(0.25, 0.5);
	llave->SetPos(25, 22);
	premios.agregar(llave);
	//llave.SetLlave(0.25, 0.5);
	//llave.SetPos(25, 21);

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

void Mundo::Tecla(unsigned char key)
{

}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.SetPos((hombre.GetPosX()) - 0.3 , hombre.GetPosY());
		x_ojo -= 0.3;
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetPos((hombre.GetPosX()) + 0.3, hombre.GetPosY());
		x_ojo += 0.3;
		break;
	case GLUT_KEY_UP:

		if (salto == 1) {
			hombre.SetVel(0, 10.0f);
			hombre.SetAc(0, -9.8f);
			//y_ojo += 0.2;
		}
		break;
	}
}