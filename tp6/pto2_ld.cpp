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

void AgregarInicio(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
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

pnodo QuitarInicio(tlista &lista) {
	pnodo extraido;
	if (lista.inicio == NULL) {
		extraido = NULL;
	} else {
		extraido = lista.inicio;
		if (lista.inicio == lista.fin) { 
			lista.inicio = NULL;
			lista.fin = NULL;
		} else {
			lista.inicio = lista.inicio->sig;
			lista.inicio->ant = NULL;
			extraido->sig = NULL;
		}
	}
	return extraido;
}

pnodo QuitarFinal(tlista &lista) {
	pnodo extraido;
	if (lista.inicio == NULL) {
		extraido = NULL;
	} else {
		extraido = lista.fin;
		if (lista.inicio == lista.fin) { 
			lista.inicio = NULL;
			lista.fin = NULL;
		} else {
			lista.fin = lista.fin->ant;
			lista.fin->sig = NULL;
			extraido->ant = NULL;
		}
	}
	return extraido;
}

void MostrarLista(tlista lista) {
	pnodo i;
	cout << "Lista: ";
	for (i = lista.inicio; i != NULL; i = i->sig) {
		cout << i->dato << " ";
	}
	cout << endl;
}

int main() {
	tlista lista;
	pnodo nuevo, borrado;
	int valor, opcion;
	
	IniciarLista(lista);
	
	do {
		cout << "\n*** MENU ***" << endl;
		cout << "1. Agregar al inicio" << endl;
		cout << "2. Agregar al final" << endl;
		cout << "3. Quitar al inicio" << endl;
		cout << "4. Quitar al final" << endl;
		cout << "5. Mostrar lista" << endl;
		cout << "6. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarInicio(lista, nuevo);
			break;
		case 2:
			cout << "Valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarFinal(lista, nuevo);
			break;
		case 3:
			borrado = QuitarInicio(lista);
			if (borrado != NULL) {
				cout << "Eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vacia." << endl;
			}
			break;
		case 4:
			borrado = QuitarFinal(lista);
			if (borrado != NULL) {
				cout << "Eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vacia." << endl;
			}
			break;
		case 5:
			MostrarLista(lista);
			break;
		case 6:
			cout << "Hasta pronto!" << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
	} while (opcion != 6);
	
	return 0;
}
