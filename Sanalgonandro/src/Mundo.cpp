#include "Mundo.h"
#include <math.h>
#include "glut.h"

void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,
		0.0, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	caja.Dibuja();
	/*esfera.Dibuja();
	esfera2.Dibuja();
	caja.Dibuja();
	hombre.Dibuja();
	disparo.Dibuja();
	plataforma.Dibuja();
	bonus.Dibuja();*/
}

void Mundo::Mueve()
{
	/*hombre.Mueve(0.025f);
	esfera.Mueve(0.025f);
	esfera2.Mueve(0.025f);
	bonus.Mueve(0.025f);
	disparo.Mueve(0.025f);
	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(esfera, caja);
	Interaccion::rebote(esfera, plataforma);
	Interaccion::rebote(esfera2, caja);
	Interaccion::rebote(esfera2, plataforma);
	Interaccion::rebote(esfera, esfera2);*/
}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
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
	plataforma.SetPos(-5.0f, 9.0f, 5.0f, 9.0f);
	hombre.SetPos(0, 0);*/
}

void Mundo::Tecla(unsigned char key)
{

}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.SetVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetVel(5.0f, 0.0f);
		break;
	}
}