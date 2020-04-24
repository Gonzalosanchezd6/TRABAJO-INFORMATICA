#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Interaccion.h"
#include "Pared.h"
#include "ListaPlataformas.h"

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
	//Pared plataforma;
	ListaPlataformas plataformas;
	
public:
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
};
