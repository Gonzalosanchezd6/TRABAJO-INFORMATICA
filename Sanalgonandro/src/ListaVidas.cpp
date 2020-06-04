#include"ListaVidas.h"

ListaVidas::~ListaVidas(){
}

void ListaVidas::setpos(int i) {
	if (i == 0) { //esto es sumar
		for (int i = 0; i < num(); i++) {
			operator[](i)->SetPos((operator[](i)->GetPos().x) + 0.3, 40);
		}
	}
	if (i==1) { //esto es restar
		for (int i = 0; i < num(); i++) {
			operator[](i)->SetPos((operator[](i)->GetPos().x) - 0.3, 40);
		}
	}
}


void ListaVidas::Eliminar(int n) {
	for (int i = n; i < num();i++) {
		Lista::Eliminar(i);
	}
}

