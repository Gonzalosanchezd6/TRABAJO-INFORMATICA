#include "ListaPremios.h"
#include "Interaccion.h"

ListaPremios::ListaPremios() {
	num_premio = 0;
	for (int i = 0; i < MAX_PREMIOS; i++) {
		lista[i] = 0;
	}
}

ListaPremios::~ListaPremios() {

}

bool ListaPremios::agregar(Premio* l) {
	if (num_premio < MAX_PREMIOS) {
		for (int i = 0; i < num_premio; i++) {
			if (lista[i] == l) {
				return false;
			}
		}
		lista[num_premio] = l;
		num_premio++;
		return true;
	}
	else {
		return false;
	}
}

void ListaPremios::destruirContenido() {
	for (int i = 0; i < num_premio; i++) {
		delete lista[i]; //delete solo elimina cosas creadas con new
	}
	num_premio = 0;
}

void ListaPremios::Eliminar(int index) {
	if ((index < 0) || (index >= num_premio)) {
		return;
	}
	delete lista[index];
	num_premio--;
	for (int i = index; i < num_premio; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaPremios::Eliminar(Premio* l) {
	for (int i = 0; i < num_premio; i++) {
		if (lista[i] == l) {
			Eliminar(i);
			return;
		}
	}
}

void ListaPremios::Dibuja() {
	for (int i = 0; i < num_premio; i++) {
		lista[i]->Dibuja();
	}
}

Premio* ListaPremios::colision(Hombre& h) {
	for (int i = 0; i < num_premio; i++) {
		if (Interaccion::Choque(h, (lista[i]))) {
			return lista[i];
		}
	}
	return 0;
}