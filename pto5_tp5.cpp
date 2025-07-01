#include <iostream>
using namespace std;


typedef struct tnodo *pnodo;
typedef struct tnodo {
	int dato;
	pnodo siguiente;
};


void iniciar_lista(pnodo &lista) {
	lista = NULL;
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


void agregar_final(pnodo &lista, pnodo nuevo) {
	pnodo i;
	if (lista == NULL) {
		lista = nuevo;
	} else {
		for (i = lista; i->siguiente != NULL; i = i->siguiente);
		i->siguiente = nuevo;
	}
}


void mostrar_lista(pnodo lista) {
	pnodo i;
	if (lista != NULL) {
		for (i = lista; i != NULL; i = i->siguiente) {
			cout << i->dato << " -> ";
		}
		cout << "NULL" << endl;
	} else {
		cout << "Lista vacia." << endl;
	}
}

// Ordenar por selecc
void ordenar_seleccion(pnodo &lista) {
	pnodo i, j, menor;
	int aux;
	for (i = lista; i != NULL; i = i->siguiente) {
		menor = i;
		for (j = i->siguiente; j != NULL; j = j->siguiente) {
			if (j->dato < menor->dato) {
				menor = j;
			}
		}
		if (menor != i) {
			aux = i->dato;
			i->dato = menor->dato;
			menor->dato = aux;
		}
	}
}

// combinar sin importar orden
void combinar_sin_orden(pnodo &lista1, pnodo lista2) {
	pnodo nuevo;
	while (lista2 != NULL) {
		nuevo = new tnodo;
		nuevo->dato = lista2->dato;
		nuevo->siguiente = NULL;
		agregar_final(lista1, nuevo);
		lista2 = lista2->siguiente;
	}
}

// combinar respetando orden
void combinar_con_orden(pnodo &lista1, pnodo lista2) {
	pnodo nuevo;
	while (lista2 != NULL) {
		nuevo = new tnodo;
		nuevo->dato = lista2->dato;
		nuevo->siguiente = NULL;
		agregar_final(lista1, nuevo);
		lista2 = lista2->siguiente;
	}
	ordenar_seleccion(lista1);
}


int main() {
	pnodo lista1, lista2;
	pnodo nuevo;
	int opcion;
	
	iniciar_lista(lista1);
	iniciar_lista(lista2);
	
	do {
		cout << "*** MENU ***" << endl;
		cout << "1. Agregar nodo a Lista 1" << endl;
		cout << "2. Agregar nodo a Lista 2" << endl;
		cout << "3. Mostrar Listas" << endl;
		cout << "4. Ordenar Lista 1 por seleccion" << endl;
		cout << "5. Combinar sin orden" << endl;
		cout << "6. Combinar con orden" << endl;
		cout << "7. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch(opcion) {
		case 1:
			crear_nodo(nuevo);
			agregar_final(lista1, nuevo);
			break;
		case 2:
			crear_nodo(nuevo);
			agregar_final(lista2, nuevo);
			break;
		case 3:
			cout << "Lista 1: "; mostrar_lista(lista1);
			cout << "Lista 2: "; mostrar_lista(lista2);
			break;
		case 4:
			ordenar_seleccion(lista1);
			cout << "Lista 1 ordenada." << endl;
			break;
		case 5:
			combinar_sin_orden(lista1, lista2);
			cout << "Listas combinadas sin ordenar." << endl;
			break;
		case 6:
			combinar_con_orden(lista1, lista2);
			cout << "Listas combinadas y ordenadas." << endl;
			break;
		case 7:
			cout << "Fin del programa." << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
	} while (opcion != 7);
	
	return 0;
}
