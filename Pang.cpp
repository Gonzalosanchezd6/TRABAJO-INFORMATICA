#include "glut.h"
#include <math.h>

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

struct esfera_t {
	float x_esfera;
	float y_esfera;
	float z;
	float ang;
	float radio;
	float c1b, c2b, c3b;
	float direccion;//0: quieto, 1: horario, 2: antihorario
};
esfera_t esfera = { 5,0,0,0,2,255,0,0,0 };

struct toroide_t {
	float c1t, c2t, c3t;
};
toroide_t toroide = { 255,255,255 };

struct plano_t {
	float x_1 = 255, y_1 = 0, z_1 = 0;
	float x_2 = 255, y_2 = 255, z_2 = 0;
	float x_3 = 255, y_3 = 255, z_3 = 255;
	float x_4 = 0, y_4 = 255, z_4 = 255;
};
plano_t plano = { 255,0,0,255,255,0,255,255,255,0,255,255 };

struct mundo_t {
	float x_camara;
	float y_camara;
	float z;
};
mundo_t mundo = { -5,0,0 };





int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600); //-tamaño de la ventana, se puede cambiar el numero de pixeles
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("pang_uc"); //-simplemente es el nombre del juego

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks //-registrar funciones que se van a ejecutar cada cierto tiempo
	glutDisplayFunc(OnDraw);
	glutTimerFunc(100,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}
void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	gluLookAt(0.0, 10, 20,  // posicion del ojo
		mundo.x_camara, mundo.y_camara, mundo.z,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo
	glTranslatef(0, 0, 0);
	glColor3ub(toroide.c1t, toroide.c2t, toroide.c3t);
	glutSolidTorus(1, 5, 32, 32);

	//glTranslatef(0, 0, z_plano);
	glBegin(GL_POLYGON);
		glColor3ub(plano.x_1, plano.y_1, plano.z_1);
		glVertex3f(-5.0f, -5.0f, 0.0f);
		glColor3ub(plano.x_2, plano.y_2,plano.z_2);
		glVertex3f(-5.0f, 5.0f, 0.0f);
		glColor3ub(plano.x_3, plano.y_3, plano.z_3);
		glVertex3f(5.0f, 5.0f, 0.0f);
		glColor3ub(plano.x_4, plano.y_4, plano.z_4);
		glVertex3f(5.0f, -5.0f, 0.0f);
	glEnd();

	glTranslatef(5*cos(3.14159265), 5*sin(3.14159265), esfera.z);
	glColor3ub(esfera.c1b, esfera.c2b, esfera.c3b);
	glutSolidSphere(esfera.radio, 32, 32);

	

	/*glColor3ub(255, 255, 255);//-para que hacer el redisplay vuelva a pintarlo en blanco y no rojo
	glutSolidCube(lado_cubo);
	glTranslatef(3, -1, 0);
	glColor3ub(255, 0, 0); //-todo lo que dibujemos despues se dibuja en rojo
	glutWireTeapot(tam_tetera);
	*/
	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	if (key == 'h') {
		esfera.direccion = 1;
	}
	else if (key == 'a') {
		esfera.direccion = 2;
	}
	else if (key == 'q') {
		esfera.direccion = 0;
	}

	if (key == '+') {
		esfera.radio += 0.1;
	}
	else if (key == '-') {
		esfera.radio -= 0.1;
	}

	if (esfera.radio > 5) {
		esfera.radio = 2;
	}
	else if (esfera.radio < 1) {
		esfera.radio = 2;
	}

	if (key == 't') {
		toroide.c1t -= 50;
		toroide.c2t -= 100;
		toroide.c3t -= 150;
	}
	else if (key == 'b') {
		esfera.c1b += 150;
		esfera.c2b += 100;
		esfera.c3b += 75;
	}
	
	glutPostRedisplay();
}

void OnTimer(int value)
{
	mundo.x_camara += 0.1;
	mundo.y_camara = 0.0;

	if (mundo.x_camara > 5) {
		mundo.x_camara = -5;
	}

	if (plano.x_1 == 255 && plano.y_1 == 0 && plano.z_1 == 0) {
		plano.x_4 = 255, plano.y_4 = 0, plano.z_4 = 0;
		plano.x_1 = 255, plano.y_1 = 255, plano.z_1 = 0;
		plano.x_2 = 255, plano.y_2 = 255, plano.z_2 = 255;
		plano.x_3 = 0, plano.y_3 = 255, plano.z_3 = 255;
	}
	else if (plano.x_1 == 255 && plano.y_1 == 255 && plano.z_1 == 0){
		plano.x_3 = 255, plano.y_3 = 0, plano.z_3 = 0;
		plano.x_4 = 255, plano.y_4 = 255, plano.z_4 = 0;
		plano.x_1 = 255, plano.y_1 = 255, plano.z_1 = 255;
		plano.x_2 = 0, plano.y_2 = 255, plano.z_2 = 255;
	}
	else if (plano.x_1 == 255 && plano.y_1 == 255 && plano.z_1 == 255) {
		plano.x_2 = 255, plano.y_2 = 0, plano.z_2 = 0;
		plano.x_3 = 255, plano.y_3 = 255, plano.z_3 = 0;
		plano.x_4 = 255, plano.y_4 = 255, plano.z_4 = 255;
		plano.x_1 = 0, plano.y_1 = 255, plano.z_1 = 255;
	}
	else if (plano.x_1 == 0 && plano.y_1 == 255 && plano.z_1 == 255) {
		plano.x_1 = 255, plano.y_1 = 0, plano.z_1 = 0;
		plano.x_2 = 255, plano.y_2 = 255, plano.z_2 = 0;
		plano.x_3 = 255, plano.y_3 = 255, plano.z_3 = 255;
		plano.x_4 = 0, plano.y_4 = 255, plano.z_4 = 255;
	}

	if (esfera.direccion == 1) {
		esfera.ang -= 0.1;
		esfera.x_esfera = 5 * cos(esfera.ang);
		esfera.y_esfera = 5 * sin(esfera.ang);
	}
	else if (esfera.direccion == 2) {
		esfera.ang += 0.1;
		esfera.x_esfera = 5 * cos(esfera.ang);
		esfera.y_esfera = 5 * sin(esfera.ang);
	}

	glutTimerFunc(100, OnTimer, 0);
	glutPostRedisplay();
}

