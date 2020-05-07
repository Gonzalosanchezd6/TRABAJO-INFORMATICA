#include"ListaDisparos.h"
#include"Interaccion.h"

ListaDisparos::ListaDisparos() {
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++) {//poner los punteros a null
		lista[i] = 0;
	}
}

ListaDisparos::~ListaDisparos() {

}

bool ListaDisparos::agregar(Disparo* d) {
	for (int i = 0; i < numero; i++) {// si ya existe que no se vuelva a añadir
		if (lista[i] == d) {
			return false;
		}
	}
	if (numero < MAX_DISPAROS) {
		lista[numero++] = d;
		return true;
	}
	else {
		return false;// no se ha podido agregar una esfera
	}
}

void ListaDisparos::destruirContenido() {
	for (int i = 0; i < numero; i++) {
		delete lista[i];
		numero = 0;
	}
}

void ListaDisparos::mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}

void ListaDisparos::dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
		Vector2D pos = lista[i]->GetPos();//si se pasa de largo se elimina
		if (pos.x > 86) {
			Eliminar(i);
		}
	}

}

Disparo* ListaDisparos::colision(Pared p) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*lista[i], p)) {
			lista[i]->SetVel(0.0f, 0.0f);
			return lista[i];
		}
	}
	return 0;
}

Disparo* ListaDisparos::colision(Enemigo1 e) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*lista[i], e)) {
			lista[i]->SetVel(0.0f, 0.0f);
			return lista[i];
		}
	}
	return 0;
}



void ListaDisparos::Eliminar(int index) {
	Vector2D referencia;
	if ((index < 0) || (index >= numero)) {
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaDisparos::Eliminar(Disparo* d) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == d) {
			Eliminar(i);
			return;
		}
	}
}
