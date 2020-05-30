#include"ListaDisparos.h"

ListaDisparos::~ListaDisparos() {

}

void ListaDisparos::Dibuja() {
	Lista::Dibuja();
	
	for (int i = 0; i < Lista::num(); i++) {
		
		Vector2D pos = Lista::operator[](i)->GetPos();//si se pasa de largo se elimina
		if (pos.x > (Lista::operator[](i)->GetOrig().x + 15.0f) || pos.x < (Lista::operator[](i)->GetOrig().x - 15.0f)) {
			Lista::Eliminar(i);
		}
	}

}
