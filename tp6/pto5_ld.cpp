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

void EliminarMultiplosDe3(tlista &lista) {
	pnodo i = lista.inicio;
	pnodo aux;
	
	while (i != NULL) {
		aux = i->sig;
		if (i->dato % 3 == 0) {
			if (i == lista.inicio && i == lista.fin) {
				lista.inicio = NULL;
				lista.fin = NULL;
			} else if (i == lista.inicio) {
				lista.inicio = i->sig;
				if (lista.inicio != NULL)
					lista.inicio->ant = NULL;
			} else if (i == lista.fin) {
				lista.fin = i->ant;
				if (lista.fin != NULL)
					lista.fin->sig = NULL;
			} else {
				i->ant->sig = i->sig;
				i->sig->ant = i->ant;
			}
			delete i;
		}
		i = aux;
	}
}

void MostrarLista(tlista lista) {
	pnodo i = lista.inicio;
	if (i == NULL) {
		cout << "Lista vacía." << endl;
	} else {
		cout << "Lista: ";
		while (i != NULL) {
			cout << i->dato << " ";
			i = i->sig;
		}
		cout << endl;
	}
}

int main() {
	tlista lista;
	pnodo nuevo;
	int valor, opcion;
	
	IniciarLista(lista);
	
	do {
		cout << "*** MENU ***" << endl;
		cout << "1. Cargar valores " << endl;
		cout << "2. Eliminar mulltiplos de 3" << endl;
		cout << "3. Mostrar lista" << endl;
		cout << "4. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese valores, terminar con -999:" << endl;
			while (true) {
				cout << "Valor: ";
				cin >> valor;
			
				CrearNodo(nuevo, valor);
				AgregarFinal(lista, nuevo);
			}
			break;
		case 2:
			EliminarMultiplosDe3(lista);
			cout << "multiplos de 3 eliminados." << endl;
			break;
		case 3:
			MostrarLista(lista);
			break;
		case 4:
			cout << "Fin del programa." << endl;
			break;
		default:
			cout << "" << endl;
		}
	} while (opcion != 4);
	
	return 0;
}
