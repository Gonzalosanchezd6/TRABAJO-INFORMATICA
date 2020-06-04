#include "ListaBolas.h"
#include "Interaccion.h"



ListaBolas::~ListaBolas() {
}


ListaBolas::ListaBolas() {
	numero = 0;
	for (int i = 0; i < MAX_BOLAS; i++)
		lista[i] = 0;
}


bool ListaBolas::agregar(EnemigoBolas* e) {
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

void ListaBolas::Dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

void ListaBolas::Mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}


void ListaBolas::destruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaBolas::Eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaBolas::Eliminar(EnemigoBolas* e) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e) {
			Eliminar(i);
			return;
		}
	}
}

EnemigoBolas* ListaBolas::colision(Hombre& h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Choque(h, lista[i])) {
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

EnemigoBolas* ListaBolas::colision(ListaPlataformas& p) {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < p.getNum(); j++) {
			if (Interaccion::colision(*p[j], *lista[i])) {
				return lista[i];
			}
		}
	}
	return 0; //no hay colisión 
}

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
