#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
};

typedef struct tlista {
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista) {
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}

void MostrarMayorMenor(tlista lista) {
	if (lista.inicio == NULL) {
		cout << "lista vacia." << endl;
	} else {
		int mayor = lista.inicio->dato;
		int menor = lista.inicio->dato;
		pnodo i = lista.inicio->sig;
		
		while () {
			if (i->dato > mayor) mayor = i->dato;
			if (i->dato < menor) menor = i->dato;
			i = i->sig;
		}
		
		cout << "Mayor: " << mayor << endl;
		cout << "Menor: " << menor << endl;
	}
}

int main() {
	tlista lista;
	pnodo nuevo;
	int valor, opcion;
	
	IniciarLista(lista);
	
	do {
		cout << "*** MENU ***" << endl;
		cout << "1. Agregar valor" << endl;
		cout << "2. Mostrar mayor y menor" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarFinal(lista, nuevo);
			break;
		case 2:
			MostrarMayorMenor(lista);
			break;
		case 3:
			cout << "bye." << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
	} while (opcion != 3);
	
	return 0;
}
