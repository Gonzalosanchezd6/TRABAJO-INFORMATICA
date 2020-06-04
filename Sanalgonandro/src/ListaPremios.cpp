#include "ListaPremios.h"
#include "Interaccion.h"



ListaPremios::~ListaPremios() {

}

/*bool ListaPremios::agregar(Premio* l) {
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
*/
void ListaPremios::Eliminar(Premio* l) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == l) {
			if (lista[i]->GetTipo() == Premio::LLAVE) {
				num_llaves++;
			}
			else if (lista[i]->GetTipo() == Premio::MONEDA) {
				num_monedas++;
			}
			else if (lista[i]->GetTipo() == Premio::PISTOLA) {
				num_disp_espec++;
			}
			else if (lista[i]->GetTipo() == Premio::VIDA) {
				num_vidas++;
			}
			Lista::Eliminar(i);
		}
	}
}
/*
void ListaPremios::Dibuja() {
	for (int i = 0; i < num_premio; i++) {
		lista[i]->Dibuja();
	}
}
*/
Premio* ListaPremios::colision(Hombre& h) {
	for (int i = 0; i < numero; i++) {
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
	for (int i = 0; i < num(); i++) {
		if (operator[](i)->GetTipo() == o) {
			return operator[](i);
		}
	}
	return 0;
}

void ListaPremios::SetLibertad(Premio* p, bool lib) {
	for (int i = 0; i < num(); i++) {
		if (operator[](i) == p) {
			operator[](i)->SetLibertad(lib);
		}
	}
}

int ListaPremios::GetNumPrem(Premio::objetos o) {
	switch (o)
	{
	case Premio::LLAVE:
		return num_llaves;
		break;
	case Premio::MONEDA:
		return num_monedas;
		break;
	case Premio::REJA:
		break;
	case Premio::VIDA:
		return num_vidas;
		break;
	case Premio::PISTOLA:
		return num_disp_espec;
		break;
	default:
		break;
	}
	return 0;
}
void ListaPremios::reiniciar(){
	num_llaves = 0;
	num_monedas = 0;
	num_vidas = 0;
	num_disp_espec = 0;

}