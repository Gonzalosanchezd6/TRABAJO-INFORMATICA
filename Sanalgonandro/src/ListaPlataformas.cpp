#include "ListaPlataformas.h"
#include "Interaccion.h"

ListaPlataformas::ListaPlataformas() {
	numero = 0;
	for (int i = 0; i < MAX_PLATAFORMAS; i++) {
		lista[i] = 0;
	}
}

ListaPlataformas::~ListaPlataformas() {

}

bool ListaPlataformas::Agregar(Pared* p) {

	if (numero < MAX_PLATAFORMAS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == p) {
				return false;
			}
		}
		lista[numero] = p;
		numero++;
		return true;
	}
	else {
		return false;
	}
}

void ListaPlataformas::Dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

void ListaPlataformas::Mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}

Pared* ListaPlataformas::colision(Hombre& h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), h)) {
			return lista[i];
		}
	}
	return 0;
}

bool ListaPlataformas::colision(ListaPlataformas l, Enemigo1 e) {
	for (int i = 0; i < l.numero; i++) {
		if (Interaccion::colision(*(l.lista[i]), e)) {
			return true;
		}
	}
	return false;
}

Pared* ListaPlataformas::operator [](int i) {
	if (i >= numero) { //si me paso, devuelvo la ultima 
		i = numero - 1;
	}
	if (i < 0) {//si el indice es negativo, devuelvo la primera 
		i = 0;
		return lista[i];
	}
	return lista[i];
}
