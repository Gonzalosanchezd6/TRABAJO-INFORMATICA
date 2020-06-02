#pragma once
#include "Mundo.h"

class Coordinador {
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, HISTORIA, INSTRUCCIONES, PAUSA};
	Estado estado;
public:
	Coordinador();
	virtual ~Coordinador();
	void Mueve();
	void Dibuja();
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
};