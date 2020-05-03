#include "Interaccion.h"
#include <math.h>
#include "glut.h"

Interaccion::Interaccion() {

}

Interaccion::~Interaccion() {

}

void Interaccion::rebote(Hombre &h, Pared p) {
	Vector2D dir;
	float dif = p.distancia(h.posicion, &dir) - h.altura;
	if (dif <= 0.0f) {
		h.aceleracion.y = 0.0f;
		h.velocidad.y = 0.0f;
	}
	/*else if (dif >= 0.0f) {
		h.aceleracion.y = -9.8f;
	}*/
}

bool Interaccion::rebote(Esfera &e, Pared p) {
	Vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		e.posicion = e.posicion - dir * dif;
		return true;//hemos tenido colision
	}
	return false; //no hay colision
}

/*void Interaccion::rebote(Hombre &h, Caja c) {
	rebote(h, c.plataforma1);
	rebote(h, c.plataforma2);
	rebote(h, c.plataforma3);
	rebote(h, c.plataforma4);
	rebote(h, c.inferior1);
	rebote(h, c.inferior2);
}*/


void Interaccion::rebote(Esfera &esfera1, Esfera &esfera2) {
		
	Vector2D dif = esfera2.posicion - esfera1.posicion;
	float d = dif.modulo();
	float dentro = d - (esfera1.radio + esfera2.radio);

	if (dentro<0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1 = esfera1.velocidad.modulo();
		float ang1 = esfera1.velocidad.argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2 = esfera2.velocidad.modulo();
		float ang2 = esfera2.velocidad.argumento();

		//el argumento del vector que une los centros
		float angd = dif.argumento();

		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro / 2 * cos(angd), dentro / 2 * sin(angd));
		esfera1.posicion = esfera1.posicion + desp;
		esfera2.posicion = esfera2.posicion - desp;

		angd = angd - 3.14159f / 2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = ang1 - angd;
		float th2 = ang2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = v1 * cos(th1);
		float u1y = v1 * sin(th1);
		float u2x = v2 * cos(th2);
		float u2y = v2 * sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = esfera1.radio;
		float m2 = esfera2.radio;
		float py = m1 * u1y + m2 * u2y;//Cantidad de movimiento inicial ejey
		float ey = m1 * u1y*u1y + m2 * u2y*u2y;//Energia cinetica inicial ejey

		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py*m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a*c;
		if (disc<0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x*v1x + v1y * v1y);
		modv2 = sqrt(v2x*v2x + v2y * v2y);
		fi1 = angd + atan2(v1y, v1x);
		fi2 = angd + atan2(v2y, v2x);

		//Velocidades en absolutas despues del choque en componentes
		esfera1.velocidad.x = modv1 * cos(fi1);
		esfera1.velocidad.y = modv1 * sin(fi1);
		esfera2.velocidad.x = modv2 * cos(fi2);
		esfera2.velocidad.y = modv2 * sin(fi2);
	}
}

bool Interaccion::Colision(Pared p, Hombre h) {
	Vector2D dir;
	float dif = p.distancia(h.posicion, &dir) - h.altura;
	if (dif <= 0.0f) {
		return true;
	}
	return false;
}

bool Interaccion::Choque(Hombre h, Enemigo1 e) {
	Vector2D dif = h.posicion - e.posicion;
	float d = dif.modulo();
	float dentro = d - (h.altura + e.tama�o/2);

	if (dentro < 0.0f) {
		return true;
	}
	else {
		return false;
	}
}

bool Interaccion::Choque(Hombre h, Llave l) {
	Vector2D pos_l = l.GetPos();
	Vector2D pos_h = h.GetPos();
	//pos_h.y += h.altura / 2.0f;
	float distancia = (pos_l - pos_h).modulo() - (h.altura + 1.5);
	if (distancia < 0.1f) {
		return true;
	}
	return false;
}

bool Interaccion::Choque(Hombre h, EnemigoBolas b) {
	Vector2D dif = h.posicion - b.posicion;
	float d = dif.modulo();
	float dentro = d - (h.altura + b.radio / 2);

	if (dentro < 0.0f) {
		return true;
	}
	else {
		return false;
	}
}

bool Interaccion::colision(EnemigoBolas e, Hombre h) {
	Vector2D pos = h.GetPos(); //la posicion de la base del hombre
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (e.posicion - pos).modulo();
	if (distancia < e.radio)
		return true;
	return false;
}


bool Interaccion::colision(Vida v, Hombre h) {
	Vector2D pos = h.GetPos();
	pos.y += h.GetAltura() / 2.0f;

	float distancia = (v.posicion - pos).modulo();
	if (distancia < 1) {
		return true;
	}
	return false;

}