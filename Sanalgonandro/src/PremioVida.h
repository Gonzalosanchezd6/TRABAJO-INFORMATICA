#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Premios.h"

class PremioVida : public Premio {
private:
	ETSIDI::Sprite* premioVida;
public:
	PremioVida(objetos o = VIDA) :Premio(o) { premioVida = new ETSIDI::Sprite("imagenes/corazon.png", 0, 0, 3, 3); }
	virtual ~PremioVida();
	void Dibuja();
};