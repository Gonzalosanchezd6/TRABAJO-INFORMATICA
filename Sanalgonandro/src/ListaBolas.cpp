#include "ListaBolas.h"
#include "EnemigoBolas.h"
#include "Interaccion.h"
#include <cstdlib>

ListaBolas::ListaBolas() {
	numero = 0;
	for (int i = 0; i < MAX_BOLAS; i++)
		lista[i] = 0;
}

ListaBolas::~ListaBolas() {
}

bool ListaBolas::agregar(EnemigoBolas *e) {
	if (numero < MAX_BOLAS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == e) {
				return false;
			}
		}
		lista[numero] = e;
		numero++;
		return true;
	}
	else {
		return false;
	}
}

void ListaBolas::dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

void ListaBolas::mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}


void ListaBolas::destruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaBolas::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaBolas::eliminar(EnemigoBolas* e) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e) {
			eliminar(i);
			return;
		}
	}
}

EnemigoBolas* ListaBolas::choque(Hombre& h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Choque(h, *lista[i])) {
			return lista[i];
		}
	}
	return 0; //no hay colisión 
}


EnemigoBolas* ListaBolas::operator [](int i) {
	if (i >= numero) { //si me paso, devuelvo la ultima 
		i = numero - 1;
	}
	if (i < 0) {//si el indice es negativo, devuelvo la primera 
		i = 0;
		return lista[i];
	}
	return lista[i];
}

EnemigoBolas* ListaBolas::choque(ListaPlataformas& p) {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < p.getNum(); j++) {
			if (Interaccion::Colision(*p[j] , *lista[i])) {
				return lista[i];
			}
		}
	}
	return 0; //no hay colisión 
}

/*void ListaBolas::Crear(float t) {
	random += t;
	
	if (random == 1) {
		double i = -15 + (rand() % 35);
		agregar(new EnemigoBolas(0.5f, i, 37));
		random = 0;
	}
}*/

bool ListaBolas::Crear(float t) {
	random += t;

	if (random >= 1) {
		random = 0;
		return true;
	}
	else {
		return false;
	}
}
