#include"ListaEnemigos.h"
#include"Interaccion.h"

ListaEnemigos::ListaEnemigos(){
	numero = 0;
	for (int i = 0; i < MAX_ENEMIG; i++) {//poner los punteros a null
		lista[i] = 0;
	}
}

ListaEnemigos::~ListaEnemigos(){
}




bool ListaEnemigos::agregar(Enemigo1* e) {
	for (int i = 0; i < numero; i++) {// si ya existe que no se vuelva a añadir
		if (lista[i] == e) {
			return false;
		}
	}
	if (numero < MAX_ENEMIG) {
		lista[numero++] = e;
		return true;
	}
	else {
		return false;// no se ha podido agregar una esfera
	}
}

void ListaEnemigos::destruirContenido() {
	for (int i = 0; i < numero; i++) {
		delete lista[i];
		numero = 0;
	}
}

void ListaEnemigos::Eliminar(Enemigo1* e) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e) {
			Eliminar(i);
			return;
		}
	}
}

void ListaEnemigos::Eliminar(int index) {
	if ((index < 0) || (index >= numero)) {
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaEnemigos::mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}

void ListaEnemigos::dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
		Vector2D pos = lista[i]->GetPos();//si se pasa de largo se elimina
		if (pos.x > 40) {
			Eliminar(i);
		}
	}
}

Enemigo1* ListaEnemigos::Choque(Hombre h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Choque( h, *lista[i])) {
			lista[i]->SetVel(0.0f, 0.0f);
			return lista[i];
		}
	}
	return 0;
}