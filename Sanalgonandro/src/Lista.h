#pragma once
#define MAX_ELEM 10
#include"Interaccion.h"
#include"EnemigoLv1.h"

template <class T>

class Lista {
public:
	Lista();
	virtual ~Lista();
	bool agregar(T* d);
	void destruirContenido();
	void Eliminar(T* d);
	void Eliminar(int index);
	void mueve(float t);
	void dibuja();
	T* colision(Pared p);
	T* colision(Enemigo1 e);
	//T* colision(Hombre& h);
	int num() { return numero; }
	
private:
	T* lista[MAX_DISPAROS];
	int numero;
};


template <class T>
inline
Lista<T>::Lista() {
	numero = 0;
	for (int i = 0; i < MAX_ELEM; i++) {//poner los punteros a null
		lista[i] = 0;
	}
}

template <class T>
inline
Lista<T>::~Lista() {

}

template <class T>
inline
bool Lista< T>::agregar(T* d) {
	for (int i = 0; i < numero; i++) {// si ya existe que no se vuelva a añadir
		if (lista[i] == d) {
			return false;
		}
	}
	if (numero < MAX_ELEM) {
		lista[numero++] = d;
		return true;
	}
	else {
		return false;// no se ha podido agregar una esfera
	}
}

template <class T>
inline
void Lista< T>::destruirContenido() {
	for (int i = 0; i < numero; i++) {
		delete lista[i];
		numero = 0;
	}
}

template <class T>
inline
void  Lista< T>::mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}

template <class T>
inline
void Lista< T>::dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
		Vector2D pos = lista[i]->GetPos();//si se pasa de largo se elimina
		if (pos.x > (lista[i]->GetOrig().x + 15.0f) || pos.x < (lista[i]->GetOrig().x - 15.0f)) {
			Eliminar(i);
		}
	}

}

template <class T>
inline
T* Lista<T>::colision(Pared p) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*lista[i], p)) {
			lista[i]->SetVel(0.0f, 0.0f);
			return lista[i];
		}
	}
	return 0;
}

template <class T>
inline
T* Lista<T>::colision(Enemigo1 e) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*lista[i], e)) {
			lista[i]->SetVel(0.0f, 0.0f);
			return lista[i];
		}
	}
	return 0;
}


template <class T>
inline
void Lista< T>::Eliminar(int index) {
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

template <class T>
inline
void Lista< T>::Eliminar(T* d) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == d) {
			Eliminar(i);
			return;
		}
	}
}


