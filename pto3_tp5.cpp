#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;
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
	lista.fin = NULL;
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
		lista.fin = nuevo;
	} else {
		lista.fin->siguiente = nuevo;
		lista.fin = nuevo;
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
			lista.fin = NULL;
		}
		borrado->siguiente = NULL;
		lista.cantidad--;
	}
	return borrado;
}

int cantidad_elementos(tlista lista) {
	return lista.cantidad;
}


void mostrar_lista(tlista lista) {
	pnodo i;
	if (lista.inicio != NULL) {
		for (i = lista.inicio; i != NULL; i = i->siguiente) {
			cout << "Nodo: " << i->dato << endl;
		}
	} else {
		cout << "la lista esta vacia." << endl;
	}
}

int buscar_indice(tlista lista, int valor) {
	pnodo i = lista.inicio;
	int indice = 0;
	while (i != NULL) {
		if (i->dato == valor) {
			return indice;
		}
		i = i->siguiente;
		indice++;
	}
	return -1;
}


pnodo buscar_por_indice(tlista lista, int indiceBuscado) {
	pnodo i = lista.inicio;
	int indice = 0;
	while (i != NULL) {
		if (indice == indiceBuscado) {
			return i;
		}
		i = i->siguiente;
		indice++;
	}
	return NULL;
}


int main() {
	tlista lista;
	pnodo nuevo, borrado, buscado;
	int opcion, valor, indice;
	
	iniciar_lista(lista);
	
	do {
		cout << "*** MENU ***" << endl;
		cout << "1. Agregar nodo al final" << endl;
		cout << "2. Eliminar nodo al inicio" << endl;
		cout << "3. Mostrar cantidad de elementos" << endl;
		cout << "4. Buscar valor y devolver su indice" << endl;
		cout << "5. Buscar nodo por indice" << endl;
		cout << "6. Mostrar lista" << endl;
		cout << "7. Salir" << endl;
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
				cout << "Lista vacía." << endl;
			}
			break;
			
		case 3:
			cout << "Cantidad de elementos: " << cantidad_elementos(lista) << endl;
			break;
			
		case 4:
			cout << "Ingrese valor a buscar: ";
			cin >> valor;
			indice = buscar_indice(lista, valor);
			if (indice != -1)
				cout << "Valor encontrado en indice: " << indice << endl;
			else
				cout << "Valor no encontrado." << endl;
			break;
			
		case 5:
			cout << "Ingrese indice a buscar: ";
			cin >> indice;
			buscado = buscar_por_indice(lista, indice);
			if (buscado != NULL)
				cout << "Nodo en indice " << indice << ": " << buscado->dato << endl;
			else
				cout << "No existe nodo en ese indice." << endl;
			break;
			
		case 6:
			mostrar_lista(lista);
			break;
			
		case 7:
			cout << "ADIOS" << endl;
			break;
			
		default:
			cout << "Opcion no valida." << endl;
		}
	} while (opcion != 7);
	

	}
	


 
