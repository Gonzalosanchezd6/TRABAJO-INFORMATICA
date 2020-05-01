#include "ListaPremios.h"
#include "Interaccion.h"

ListaPremios::ListaPremios() {
	num_llave = 0;
	for (int i = 0; i < MAX_LLAVES; i++) {
		lista[i] = 0;
	}
}

ListaPremios::~ListaPremios() {

}

bool ListaPremios::agregar(Llave* l) {
	if (num_llave < MAX_LLAVES) {
		for (int i = 0; i < num_llave; i++) {
			if (*lista[i] == *l) {
				return false;
			}
		}
		lista[num_llave] = l;
		num_llave++;
		return true;
	}
	else {
		return false;
	}
}

void ListaPremios::destruirContenido() {
	for (int i = 0; i < num_llave; i++) {
		delete lista[i]; //delete solo elimina cosas creadas con new
	}
	num_llave= 0;
}

void ListaPremios::Eliminar(int index) {
	if ((index < 0) || (index >= num_llave)) {
		return;
	}
	delete lista[index];
	num_llave--;
	for (int i = index; i < num_llave; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaPremios::Eliminar(Llave* l) {
	for (int i = 0; i < num_llave; i++) {
		if (lista[i] == l) {
			Eliminar(i);
			return;
		}
	}
}

void ListaPremios::Dibuja() {
	for (int i = 0; i < num_llave; i++) {
		lista[i]->Dibuja();
	}
}

Llave* ListaPremios::colision(Hombre& h) {
	for (int i = 0; i < num_llave; i++) {
		if (Interaccion::Choque(h, *(lista[i]))) {
			return lista[i];
		}
	}
	return 0;
}
