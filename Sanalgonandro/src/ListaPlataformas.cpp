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

Pared* ListaPlataformas::Colision(Hombre& h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Colision(*(lista[i]), h)) {
			return lista[i];
		}
	}
	return 0;
}