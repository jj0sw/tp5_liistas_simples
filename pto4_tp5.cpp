#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;
typedef struct tnodo {
	int dato;
	pnodo siguiente;
};


typedef struct Pila {
	pnodo cima;
} ;


typedef struct Cola{
	pnodo frente;
	pnodo fin;
	int cantidad;
} ;

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

void initStack(Pila &pila) {
	pila.cima = NULL;
}

void pushStack(Pila &pila, pnodo nuevo) {
	nuevo->siguiente = pila.cima;
	pila.cima = nuevo;
}

pnodo popStack(Pila &pila) {
	pnodo borrado;
	if (pila.cima == NULL) {
		borrado = NULL;
	} else {
		borrado = pila.cima;
		pila.cima = pila.cima->siguiente;
		borrado->siguiente = NULL;
	}
	return borrado;
}

void mostrarStack(Pila pila) {
	pnodo i;
	cout << "Pila: ";
	for (i = pila.cima; i != NULL; i = i->siguiente) {
		cout << i->dato << " -> ";
	}
	cout << "NULL" << endl;
}


void initQueue(Cola &cola) {
	cola.frente = NULL;
	cola.fin = NULL;
	cola.cantidad = 0;
}

void pushQueue(Cola &cola, pnodo nuevo) {
	if (cola.frente == NULL) {
		cola.frente = nuevo;
		cola.fin = nuevo;
	} else {
		cola.fin->siguiente = nuevo;
		cola.fin = nuevo;
	}
	cola.cantidad++;
}

pnodo pullQueue(Cola &cola) {
	pnodo borrado;
	if (cola.frente == NULL) {
		borrado = NULL;
	} else {
		borrado = cola.frente;
		cola.frente = cola.frente->siguiente;
		if (cola.frente == NULL) cola.fin = NULL;
		borrado->siguiente = NULL;
		cola.cantidad--;
	}
	return borrado;
}

void mostrarQueue(Cola cola) {
	pnodo i;
	cout << "Queue: ";
	for (i = cola.frente; i != NULL; i = i->siguiente) {
		cout << i->dato << " -> ";
	}
	cout << "NULL" << endl;
}

int cantidadQueue(Cola cola) {
	return cola.cantidad;
}


int main() {
	Pila pila;
	Cola cola;
	pnodo nuevo, borrado;
	int opcion, estructura;
	
	initStack(pila);
	initQueue(cola);
	
	do {
		cout << "*** MENU PRINCIPAL ***" << endl;
		cout << "1. Usar Pila" << endl;
		cout << "2. Usar Cola" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: ";
		cin >> estructura;
		
		switch (estructura) {
		case 1:
			do {
				cout << "--- Stack ---" << endl;
				cout << "1. Push" << endl;
				cout << "2. Pop" << endl;
				cout << "3. Mostrar" << endl;
				cout << "4. Volver" << endl;
				cout << "Opcion: ";
				cin >> opcion;
				
				switch (opcion) {
				case 1:
					crear_nodo(nuevo);
					pushStack(pila, nuevo);
					break;
				case 2:
					borrado = popStack(pila);
					if (borrado != NULL) {
						cout << "Elemento eliminado: " << borrado->dato << endl;
						delete borrado;
					} else {
						cout << "Stack vacio." << endl;
					}
					break;
				case 3:
					mostrarStack(pila);
					break;
				case 4:
					break;
				default:
					cout << "Opcion invalida." << endl;
				}
			} while (opcion != 4);
			break;
			
		case 2:
			do {
				cout << "--- Queue ---" << endl;
				cout << "1. Push" << endl;
				cout << "2. Pull" << endl;
				cout << "3. Mostrar" << endl;
				cout << "4. Cantidad de elementos" << endl;
				cout << "5. Volver" << endl;
				cout << "Opcion: ";
				cin >> opcion;
				
				switch (opcion) {
				case 1:
					crear_nodo(nuevo);
					pushQueue(cola, nuevo);
					break;
				case 2:
					borrado = pullQueue(cola);
					if (borrado != NULL) {
						cout << "Elemento eliminado: " << borrado->dato << endl;
						delete borrado;
					} else {
						cout << "Queue vacia." << endl;
					}
					break;
				case 3:
					mostrarQueue(cola);
					break;
				case 4:
					cout << "Cantidad actual: " << cantidadQueue(cola) << endl;
					break;
				case 5:
					break;
				default:
					cout << "Opcion invalida." << endl;
				}
			} while (opcion != 5);
			break;
			
		case 3:
			cout << "Fin del programa." << endl;
			break;
			
		default:
			cout << "Opcion invalida." << endl;
		}
	} while (estructura != 3);
	
	return 0;
}
