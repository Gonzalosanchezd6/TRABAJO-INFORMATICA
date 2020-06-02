#pragma once

#include "Disparo.h"

class DisparoSuper : public Disparo {

public:
	DisparoSuper();
	DisparoSuper(int d, Vector2D Orig);
	virtual ~DisparoSuper();
	void Dibuja();
};