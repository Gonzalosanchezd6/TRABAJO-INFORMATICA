#include"ListaVidas.h"

ListaVidas::~ListaVidas(){
}


bool ListaVidas::agregar(Vida* v) {
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
	if (i == 0) { //esto es sumar
		for (int i = 0; i < num(); i++) {
			lista[i]->SetPos((lista[i]->GetPos().x) + 0.3, 40);
		}
	}
	if (i==1) { //esto es restar
		for (int i = 0; i < num(); i++) {
			lista[i]->SetPos((lista[i]->GetPos().x) - 0.3, 40);
		}
	}
}
