#include "ListaPremios.h"
#include "Interaccion.h"

ListaPremios::ListaPremios() {
	num_premio = 0;
	for (int i = 0; i < MAX_PREMIOS; i++) {
		lista[i] = 0;
	}
	num_llaves = 0;
	num_monedas = 0;
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
			if (lista[i]->GetTipo() == Premio::LLAVE) {
				num_llaves++;
			}
			else if (lista[i]->GetTipo() == Premio::MONEDA) {
				num_monedas++;
			}
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
		if (!lista[i]->Libre()) {

		}
		else if (Interaccion::Choque(h, (lista[i]))) {
			return lista[i];
		}
	}
	return 0;
}

void ListaPremios::reset(int n_llave, int n_moneda) {
	num_llaves -= n_llave;
	num_monedas -= n_moneda;
}

Premio* ListaPremios::buscar(Premio::objetos o) {
	for (int i = 0; i < num_premio; i++) {
		if (lista[i]->GetTipo() == o) {
			return lista[i];
		}
	}
	return 0;
}

void ListaPremios::SetLibertad(Premio* p, bool lib) {
	for (int i = 0; i < num_premio; i++) {
		if (lista[i] == p) {
			lista[i]->SetLibertad(lib);
		}
	}
}
