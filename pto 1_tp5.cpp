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
	if (lista == NULL) {
		lista = nuevo;
	} else {
		pnodo i = lista;
		while (i->siguiente != NULL) {
			i = i->siguiente;
		}
		i->siguiente = nuevo;
	}
}


pnodo eliminar_inicio(pnodo &lista) {
	if (lista == NULL) return NULL;
	pnodo borrado = lista;
	lista = lista->siguiente;
	borrado->siguiente = NULL;
	return borrado;
}


pnodo minimo(pnodo &lista) {
	if (lista == NULL) return NULL;
	
	pnodo borrado = lista;
	pnodo anteriorMin = NULL;
	pnodo i = lista;
	pnodo anterior = NULL;
	
	while (i != NULL) {
		if (i->dato < borrado->dato) {
			borrado = i;
			anteriorMin = anterior;
		}
		anterior = i;
		i = i->siguiente;
	}
	
	if (anteriorMin == NULL) {
		lista = borrado->siguiente;
	} else {
		anteriorMin->siguiente = borrado->siguiente;
	}
	borrado->siguiente = NULL;
	return borrado;
}

int main() {
	pnodo lista;
	pnodo nuevo;
	pnodo borrado;
	int opcion;
	
	iniciar_lista(lista);
	
	do {
		cout << "*** MENU ***"<<endl;
		cout << "1. Agregar nodo al final"<<endl;
		cout << "2. Eliminar al inicio"<<endl;
		cout << "3. Extraer minimo"<<endl;
		cout << "4. Mostrar lista"<<endl;
		cout << "5. Te vas"<<endl;
		cout << "Opcion: "<<endl;
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			crear_nodo(nuevo);
			agregar_final(lista, nuevo);
			break;
		case 2:
			borrado = eliminar_inicio(lista);
			if (borrado != NULL) {
				cout << "Nodo eliminado al inicio: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vacia." << endl;
			}
			break;
		case 3:
			borrado = minimo(lista);
			if (borrado != NULL) {
				cout << "Nodo minimo eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vaci­a." << endl;
			}
			break;
		case 4:
			cout << "Lista: ";
			if (lista == NULL) {
				cout << "vaci­a." << endl;
			} else {
				pnodo aux = lista;
				while (aux != NULL) {
					cout << aux->dato << " -> ";
					aux = aux->siguiente;
				}
				cout << "NULL" << endl;
			}
			break;
		case 5:
			cout << "Te fuiste." << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
		
	} while (opcion != 5);

}

