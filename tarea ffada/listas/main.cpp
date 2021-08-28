#include <iostream>
using namespace std;

/**
 * Estructura Nodo
 */
struct Nodo {
	int valor;
	Nodo *siguiente;
};

/**
 * Clase Lista
 */
class Lista {
private:
	Nodo *_primero;
public:
	Lista();
	~Lista();
	void agregar( int );
	Nodo * primero();
};

/**
 * Constructor
 */
Lista::Lista() {
	_primero = NULL;
}

/**
 * Destructor
 */
Lista::~Lista() {
	Nodo *nodo_actual = _primero;
	while( nodo_actual != NULL ) {
		Nodo *siguiente = nodo_actual->siguiente;
		delete nodo_actual;
		nodo_actual = siguiente;
	}
}

/**
 * Método Agregar
 * Agrega un nodo a la lista
 */
void Lista::agregar( int nuevo_valor ) {
	Nodo *nuevo_nodo = new Nodo;
	nuevo_nodo->valor = nuevo_valor;
	nuevo_nodo->siguiente = NULL;
	if( _primero == NULL ) {
		_primero = nuevo_nodo;
	} else {
		Nodo *nodo_actual = _primero;
		while( nodo_actual->siguiente != NULL ) nodo_actual = nodo_actual->siguiente;
		nodo_actual->siguiente = nuevo_nodo;
	}
}

/**
 * Método Primero
 * retorna el primer nodo de la lista
 */
Nodo * Lista::primero() {
	return _primero;
}

/**
 * Función principal
 */
int main() {
	Lista lista;

	// se agregan algunos valores a la lista
	lista.agregar( 17 );
	lista.agregar( 21 );
	lista.agregar( 12 );

	// se recorre la lista y se muestran los valores agregados
	Nodo * it = lista.primero();
	while( it != NULL ) {
		cout << it->valor << endl;
		it = it->siguiente;
	}
	return 0;
}
