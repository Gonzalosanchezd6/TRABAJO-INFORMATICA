#pragma once


#include "Vector2D.h"
#include <string>
//#include <glut.h>



class TextoInic {
public:
	TextoInic(float x1, float y1, float x2, float y2);
	virtual ~TextoInic();
	void Dibuja();
	void TextoImprimir(std::string name, float x, float y, float red, float green, float blue, float size);
private:
	Vector2D limite1;
	Vector2D limite2;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	
};

