#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
};

void IniciarLista(pnodo &inicio) {
	inicio = NULL;
}

void CrearNodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarInicio(pnodo &inicio, pnodo nuevo) {
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		nuevo->sig = inicio;
		inicio->ant = nuevo;
		inicio = nuevo;
	}
}

void AgregarFinal(pnodo &inicio, pnodo nuevo) {
	pnodo i;
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		for (i = inicio; i->sig != NULL; i = i->sig);
		i->sig = nuevo;
		nuevo->ant = i;
	}
}

void AgregarOrden(pnodo &inicio, pnodo nuevo) {
	pnodo i;
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		if (nuevo->dato < inicio->dato) {
			nuevo->sig = inicio;
			inicio->ant = nuevo;
			inicio = nuevo;
		} else {
			for (i = inicio; i->sig != NULL && i->sig->dato < nuevo->dato; i = i->sig);
			if (i->sig != NULL) {
				nuevo->sig = i->sig;
				nuevo->ant = i;
				i->sig->ant = nuevo;
				i->sig = nuevo;
			} else {
				i->sig = nuevo;
				nuevo->ant = i;
			}
		}
	}
}

pnodo QuitarInicio(pnodo &inicio) {
	pnodo extraido;
	if (inicio == NULL) {
		extraido = NULL;
	} else {
		if (inicio->sig == NULL) {
			extraido = inicio;
			inicio = NULL;
		} else {
			extraido = inicio;
			inicio = inicio->sig;
			inicio->ant = NULL;
			extraido->sig = NULL;
		}
	}
	return extraido;
}

pnodo QuitarFinal(pnodo &inicio) {
	pnodo extraido, i;
	if (inicio == NULL) {
		extraido = NULL;
	} else {
		for (i = inicio; i->sig != NULL; i = i->sig);
		extraido = i;
		if (i->ant != NULL) {
			i->ant->sig = NULL;
		} else {
			inicio = NULL;
		}
		i->ant = NULL;
	}
	return extraido;
}

pnodo QuitarNodo(pnodo &inicio, int valor) {
	pnodo extraido, i;
	if (inicio == NULL) {
		extraido = NULL;
	} else {
		if (inicio->dato == valor) {
			extraido = inicio;
			inicio = inicio->sig;
			if (inicio != NULL)
				inicio->ant = NULL;
			extraido->sig = NULL;
		} else {
			for (i = inicio; i != NULL && i->dato != valor; i = i->sig);
			if (i != NULL) {
				extraido = i;
				if (i->ant != NULL)
					i->ant->sig = i->sig;
				if (i->sig != NULL)
					i->sig->ant = i->ant;
				extraido->sig = NULL;
				extraido->ant = NULL;
			} else {
				extraido = NULL;
			}
		}
	}
	return extraido;
}

bool BuscarNodo(pnodo inicio, int valor) {
	pnodo i;
	for (i = inicio; i != NULL && i->dato != valor; i = i->sig);
	return i != NULL;
}

void MostrarLista(pnodo inicio) {
	pnodo i;
	cout << "Lista: ";
	for (i = inicio; i != NULL; i = i->sig) {
		cout << i->dato << " ";
	}
	cout << endl;
}

int main() {
	pnodo lista;
	pnodo nuevo, borrado;
	int valor, opcion;
	
	IniciarLista(lista);
	
	do {
		cout << "\n*** MENU ***" << endl;
		cout << "1. Agregar al inicio" << endl;
		cout << "2. Agregar al final" << endl;
		cout << "3. Agregar ordenado" << endl;
		cout << "4. Quitar inicio" << endl;
		cout << "5. Quitar final" << endl;
		cout << "6. Quitar valor especifico" << endl;
		cout << "7. Buscar valor" << endl;
		cout << "8. Mostrar lista" << endl;
		cout << "9. Salir" << endl;
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
			cout << "Valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarOrden(lista, nuevo);
			break;
		case 4:
			borrado = QuitarInicio(lista);
			if (borrado != NULL) {
				cout << "Eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vacia." << endl;
			}
			break;
		case 5:
			borrado = QuitarFinal(lista);
			if (borrado != NULL) {
				cout << "Eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vacia." << endl;
			}
			break;
		case 6:
			cout << "Valor a eliminar: ";
			cin >> valor;
			borrado = QuitarNodo(lista, valor);
			if (borrado != NULL) {
				cout << "Eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "No encontrado." << endl;
			}
			break;
		case 7:
			cout << "Valor a buscar: ";
			cin >> valor;
			cout << (BuscarNodo(lista, valor) ? "Encontrado." : "No encontrado.") << endl;
			break;
		case 8:
			MostrarLista(lista);
			break;
		case 9:
			cout << "Adeu" << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
	} while (opcion != 9);
	
	return 0;
}
