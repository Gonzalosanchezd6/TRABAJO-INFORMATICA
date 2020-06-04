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
#include "PlataformaMovil.h"
#include "EnemigoBolas.h"
#include"Vida.h"
#include "ListaBolas.h"
#include"ListaDisparos.h"
#include"ListaEnemigos.h"
#include "Premios.h"
#include "Monedas.h"
#include "Reja.h"
#include "DisparoSuper.h"
#include"ListaVidas.h"
#include "Enemigo2vidas.h"
#include "EnemigoFinal.h"
#include "PremioVida.h"
#include "Pistola.h"


class Mundo
{
private: //se puede poner como private sin problema
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int salto = 0;
	int dispder = 1;
	float CrearBola = 0;
	bool muerte;
	bool FinLevel;
	int nivel;
	Vector2D PosEne;
	Disparo *disparo;
	Hombre hombre;
	Bonus bonus;
	ListaPlataformas plataformas;
	ListaPremios premios;
	Puerta puerta;
	ListaBolas Bolas;
	ListaDisparos disparos;
	ListaEnemigos enemigos;
	DisparoSuper disparosuper;
	ListaVidas vidas;

	
	
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
	int GetNivel() { return nivel; }

	bool cargarNivel();
	void reset();
};
