#pragma once
#include "Bonus.h"
#include "Disparo.h"
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
#include"ListaDisparos.h"
#include"ListaEnemigos.h"
#include"Lista.h"


class Mundo
{
private: //se puede poner como private sin problema
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int salto = 0;
	int dispder = 1;
	bool muerte;
	bool FinLevel;
	Disparo *disparo;
	Hombre hombre;
	Bonus bonus;
	ListaPlataformas plataformas;
	//Enemigo1 enemigo1;
	//EnemigoBolas bolas;
	ListaPremios premios;
	Puerta puerta;
	//ListaBolas Bolas;
	//ListaDisparos disparos;
	ListaEnemigos enemigos;
	Lista<Disparo> disparos;
	Lista<EnemigoBolas> Bolas;
	//Lista<Enemigo1>enemigos;
	
public:
	Mundo();
	~Mundo();

	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);

	void DibujarTexto(const char* texto, int longitud, int x, int y);
	bool GetMuerte() { return muerte; }
	bool GetFin() { return FinLevel; }
};
