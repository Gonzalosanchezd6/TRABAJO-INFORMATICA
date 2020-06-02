#include"ListaVidas.h"
#include "Interaccion.h"
#include"glut.h"
ListaVidas::ListaVidas(){
	numero = 0;
	for (int i = 0; i < MAX_VIDAS; i++) {
		lista[i] = 0;
	}
}

ListaVidas::~ListaVidas(){

}


bool ListaVidas::Agregar(Vida* v) {
	for (int i = 0; i < numero; i++) {//comprobamos si ya se ha añadido o no, porque si ya se ha añadido dará fallo el delete
		if (lista[i] == v) {
			return false;
		}
	}
	if (numero < MAX_VIDAS) {
		lista[numero++] = v;
		return true;
	}
	else {
		return false;// no se ha podido agregar una esfera
	}
}

void ListaVidas::Dibuja() {
	int i;
	for (i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}

}
/*
Vida* ListaVidas::Colision(Hombre& h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), h)) {
			return lista[i];
		}
	}
	return 0;
}*/


void ListaVidas::Mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}

void ListaVidas::destruirContenido(){
	for (int i = 0; i < numero; i++) {
		delete lista[i];
	}
	numero = 0;
}

void ListaVidas::Eliminar(int index){
	if ((index < 0) || (index >= numero)) {
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaVidas::Eliminar(Vida* v){
	for (int i = 0; i < numero; i++) {
		if (lista[i] == v) {
			Eliminar(i);
		}
	}
}

void ListaVidas::setpos(int i) {

	/*if (lista[0]->GetPos().x <= 57 && (x) >= 4 && (x) <= 56) {
		for (int i = 0; i < numero; i++) {
			lista[i]->SetPos((lista[i]->GetPos().x) + 0.3, y);
		}
	}
	if (lista[0]->GetPos().x >= 7 && (x) >= 4 && (x) <= 56) {
		for (int i = 0; i < numero; i++) {
			lista[i]->SetPos((lista[i]->GetPos().x) - 0.3, y);
		}
	}*/

	if (i == 0) { //esto es sumar
		for (int i = 0; i < numero; i++) {
			lista[i]->SetPos((lista[i]->GetPos().x) + 0.3, 40);
		}
	}
	if (i==1) { //esto es restar
		for (int i = 0; i < numero; i++) {
			lista[i]->SetPos((lista[i]->GetPos().x) - 0.3, 40);
		}
	}
}
