#include"ListaEnemigos.h"
#include"Interaccion.h"


ListaEnemigos::~ListaEnemigos() {
}


void ListaEnemigos::Dibuja() {
	Lista::Dibuja();
	for (int i = 0; i < Lista::num(); i++) {
		Vector2D pos = Lista::operator[](i)->GetPos();//si se pasa de largo se elimina
		if (pos.x > 86) {
			Eliminar(i);
		}
	}
}

Enemigo1* ListaEnemigos::colision(ListaPlataformas l) {
	for (int i = 0; i < Lista::num(); i++) {
		if (ListaPlataformas::colision(l, *(operator[](i)))) {
			float vel = (operator[](i))->GetVel().x;
			operator[](i)->SetVel(-vel, 0);
			return operator[](i);
		}
	}
	return nullptr;
}
