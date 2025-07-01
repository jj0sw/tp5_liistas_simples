#include <iostream>
using namespace std;


typedef struct tnodo* pnodo;
typedef struct tnodo {
	int dato;
	pnodo siguiente;
};


typedef struct tlista {
	pnodo inicio;
	pnodo final;
	int cantidad;
};


void iniciar_lista(tlista &lista) {
	lista.inicio = NULL;
	lista.final = NULL;
	lista.cantidad = 0;
}


void crear_nodo(pnodo &nuevo) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		cout << "Ingrese valor: ";
		cin >> nuevo->dato;
		nuevo->siguiente = NULL;
	} else {
		cout << "Memoria insuficiente" << endl;
	}
}


void agregar_final(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		lista.final->siguiente = nuevo;
		lista.final = nuevo;
	}
	lista.cantidad++;
}


pnodo eliminar_inicio(tlista &lista) {
	pnodo borrado;
	if (lista.inicio == NULL) {
		borrado = NULL;
	} else {
		borrado = lista.inicio;
		lista.inicio = lista.inicio->siguiente;
		if (lista.inicio == NULL) {
			lista.final = NULL;
		}
		borrado->siguiente = NULL;
		lista.cantidad--;
	}
	return borrado;
}


int cantidad_elementos(tlista lista) {
	return lista.cantidad;
}



int main() {
	tlista lista;
	pnodo nuevo;
	pnodo borrado;
	int opcion;
	
	iniciar_lista(lista);
	
	do {
		cout << "*** MENU ***"<<endl;
		cout << "1. Agregar nodo al final"<<endl;
		cout << "2. Eliminar nodo al inicio"<<endl;
		cout << "3. Mostrar cantidad de elementos"<<endl;
		cout << "4. Salir"<<endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			crear_nodo(nuevo);
			agregar_final(lista, nuevo);
			break;
		case 2:
			borrado = eliminar_inicio(lista);
			if (borrado != NULL) {
				cout << "Nodo eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vaci­a." << endl;
			}
			break;
		case 3:
			cout << "Cantidad actual de elementos: " << cantidad_elementos(lista) << endl;
			break;
		case 4:
			cout << "" << endl;
			break;
		default:
			cout << "Opcion invaliida." << endl;
	
		}} while (opcion != 4);
	
}

