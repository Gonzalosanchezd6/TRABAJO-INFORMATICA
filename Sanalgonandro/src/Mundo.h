#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Interaccion.h"
#include "Pared.h"
#include "ListaPlataformas.h"
#include "EnemigoLv1.h"
#include "Llave.h"
#include "ListaPremios.h"
#include "Puerta.h"
#include "EnemigoBolas.h"
#include "ListaBolas.h"

class Mundo
{
private: //se puede poner como private sin problema
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int salto = 0;
	Disparo disparo;
	Esfera esfera;
	Esfera esfera2;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	ListaPlataformas plataformas;
	Enemigo1 enemigo1;
	EnemigoBolas bolas;
	ListaPremios premios;
	Puerta puerta;
	ListaBolas Bolas;

public:
	Mundo();
	~Mundo();

	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
};
