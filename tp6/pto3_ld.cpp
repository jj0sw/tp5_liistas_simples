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

void MostrarLista(tlista lista) {
	pnodo i;
	cout << "Binario: ";
	for (i = lista.inicio; i != NULL; i = i->sig) {
		cout << i->dato;
	}
	cout << endl;
}

void DecimalABinario(tlista &lista, int numero) {
	pnodo nuevo;
	if (numero == 0) {
		CrearNodo(nuevo, 0);
		AgregarInicio(lista, nuevo);
	} else {
		while (numero > 0) {
			CrearNodo(nuevo, numero % 2);
			AgregarInicio(lista, nuevo);
			numero /= 2;
		}
	}
}

int main() {
	tlista lista;
	;
	
	IniciarLista(lista);
	
	cout << "Ingrese numero decimal: ";
	cin >> ;
	
	DecimalABinario(lista, numero);
	MostrarLista(lista);
	
	return 0;
}
