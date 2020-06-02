#include "Coordinador.h"
//#include "Mundo.h"
#include "ETSIDI.h"
#include <iostream>
#include "glut.h" //debe ir siempre como ultimo include

Coordinador coordinador;
//Mundo mundo;

using namespace ETSIDI; //esto en teoria es para las imagenes, musica, texto,etc
using ETSIDI::getTexture;//esto en teoria es para las imagenes, musica, texto,etc

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y);

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1000,750); //800x600
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores

	
	//mundo.Inicializa();
	
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void) {
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	coordinador.Dibuja();
	//mundo.Dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t) {
	//poner aqui el c�digo de teclado
	coordinador.Tecla(key);
	//mundo.Tecla(key);

	glutPostRedisplay();
}

void OnTimer(int value) {
//poner aqui el c�digo de animacion
	coordinador.Mueve();
	//mundo.Mueve();
	//mundo.RotarOjo();


	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y) {
	coordinador.teclaEspecial(key);
	//mundo.teclaEspecial(key);
}