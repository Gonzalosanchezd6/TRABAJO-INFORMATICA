#include "TextoInic.h"
#include "ETSIDI.h"

TextoInic::TextoInic(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite2.x = x2;
	limite1.y = y1;
	limite2.y = y2;
	rojo = 0;
	verde = 250;
	azul = 0;
}
void TextoInic::Dibuja() {
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glVertex3d(limite1.x, limite1.y, 0);
	glVertex3d(limite2.x, limite1.y, 0);
	glVertex3d(limite2.x, limite2.y, 0);
	glVertex3d(limite1.x, limite2.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	/*void renderSpacedBitmapString(float x, float y, int spacing, void* font, char* string) {
		char* c; int x1 = x;
		for (c = string; *c != '\0'; c++) {
			glRasterPos2f(x1, y);
			glutBitmapCharacter(font, *c);
			x1 = x1 + glutBitmapWidth(font, *c) + spacing;
		}
		*/
}
TextoInic::~TextoInic() {

}
/*
void TextoInic::TextoImprimir(std::string name, float x, float y, float red, float green, float blue, float size) {
	char* nombre = strcpy(new char[name.length() + 1], name.c_str());
	glTranslatef(x, y, 0.2);
	const std::string pene = name;
	ETSIDI::setTextColor(red, green, blue);
	ETSIDI::print(pene, "fuentes/Revamped-X3q1a.ttf", size);
	glTranslatef(-x, -y, -0.2);
}*/