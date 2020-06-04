#pragma once
#include"Interaccion.h"
#include"EnemigoLv1.h"

template <class T,int n>
class Lista {
public:
	Lista();
	virtual ~Lista();
	bool agregar(T* d);
	void destruirContenido();
	virtual void Eliminar(T* d);
	void Eliminar(int index);
	void Mueve(float t);
	virtual void Dibuja();
	T* colision(Pared p);
	T* colision(Enemigo1 e);
	T* colision(Hombre& h);
	int num() { return numero; }
	T* operator[](int i);
protected:
	static const int MAX_ELEM = n;
	T* lista[MAX_ELEM];
	int numero;
};


template <class T, int n>
inline
Lista<T,n>::Lista<T, n>() {
	numero = 0;
	for (int i = 0; i < MAX_ELEM; i++) {//poner los punteros a null
		lista[i] = 0;
	}
}

template <class T, int n>
inline
Lista<T, n>::~Lista() {
	destruirContenido();
}

template <class T, int n>
inline
bool Lista<T, n>::agregar(T* d) {
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

template <class T, int n>
inline
void Lista<T, n>::destruirContenido() {
	for (int i = 0; i < numero; i++) {
		delete lista[i];
		numero = 0;
	}
}

template <class T, int n>
inline
void  Lista<T, n>::Mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}

template <class T, int n>
inline
void Lista<T, n>::Dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

template <class T, int n>
inline
T* Lista<T, n>::colision(Pared p) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*lista[i], p)) {
			lista[i]->SetVel(0.0f, 0.0f);
			return lista[i];
		}
	}
	return 0;
}

template<class T, int n>
inline
T* Lista<T, n>::colision(Enemigo1 e) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*lista[i], e)) {
			lista[i]->SetVel(0.0f, 0.0f);
			return lista[i];
		}
	}
	return 0;
}

template <class T, int n>
inline
T* Lista<T, n>::colision(Hombre& h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Choque(h, lista[i])) {
			return lista[i];
		}
	}
	return 0; //no hay colisión 
}
/*
template <class T, int n>
inline
T* Lista<T, n>::colision(ListaPlataformas& p) {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < p.getNum(); j++) {
			if (Interaccion::colision(*p[j], *lista[i])) {
				return lista[i];
			}
		}
	}
	return 0; //no hay colisión 
}*/

template <class T, int n>
inline
void Lista<T, n>::Eliminar(int index) {
	//Vector2D referencia;
	if ((index < 0) || (index >= numero)) {
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
}

template <class T, int n>
inline
void Lista<T, n>::Eliminar(T* d) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == d) {
			Eliminar(i);
			return;
		}
	}
}
/*
template <class T, int n>
inline
bool Lista<T, n>::Crear(float t) {
	random += t;

	if (random >= 1) {
		random = 0;
		return true;
	}
	else {
		return false;
	}
}*/


template <class T, int n>
inline
T* Lista<T, n>::operator[](int i) {
	if (i >= numero) { //si me paso, devuelvo la ultima 
		i = numero - 1;
	}
	if (i < 0) {//si el indice es negativo, devuelvo la primera 
		i = 0;
		return lista[i];
	}
	return lista[i];
}