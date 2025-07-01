#include <iostream>
#include <cctype>
using namespace std;

typedef struct tnodo* pnodo;
typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

void iniciar_lista(pnodo &lista) {
	lista = NULL;
}

void crear_nodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
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

void mostrar_lista(pnodo lista) {
	while (lista != NULL) {
		cout << lista->dato << " -> ";
		lista = lista->siguiente;
	}
	cout << "NULL" << endl;
}

bool es_primo(int num) {
	if (num <= 1) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int contar_primos(pnodo lista) {
	int contador = 0;
	while (lista != NULL) {
		if (es_primo(lista->dato)) contador++;
		lista = lista->siguiente;
	}
	return contador;
}

//  caracteres

typedef struct cnodo* pcnodo;
typedef struct cnodo {
	char dato;
	pcnodo siguiente;
};

void iniciar_lista_c(pcnodo &lista) {
	lista = NULL;
}

void crear_nodo_c(pcnodo &nuevo, char valor) {
	nuevo = new cnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
	} else {
		cout << "Memoria insuficiente" << endl;
	}
}

void agregar_final_c(pcnodo &lista, pcnodo nuevo) {
	if (lista == NULL) {
		lista = nuevo;
	} else {
		pcnodo i = lista;
		while (i->siguiente != NULL) {
			i = i->siguiente;
		}
		i->siguiente = nuevo;
	}
}

void mostrar_lista_c(pcnodo lista) {
	while (lista != NULL) {
		cout << lista->dato << " -> ";
		lista = lista->siguiente;
	}
	cout << "NULL" << endl;
}

void contar_mayus_minus(pcnodo lista, int &mayus, int &minus) {
	mayus = minus = 0;
	while (lista != NULL) {
		if (isupper(lista->dato)) mayus++;
		else if (islower(lista->dato)) minus++;
		lista = lista->siguiente;
	}
}

int main() {
	pnodo listaNum;
	pcnodo listaChar;
	int opcion, valor, primos, mayus, minus;
	char cvalor;
	pnodo nuevoNum;
	pcnodo nuevoChar;
	
	iniciar_lista(listaNum);
	iniciar_lista_c(listaChar);
	
	do {
		cout << "*** MENU ***" << endl;
		cout << "1. Agregar numero a la lista" << endl;
		cout << "2. Mostrar numeros" << endl;
		cout << "3. Contar primos" << endl;
		cout << "4. Agregar caracter a la lista" << endl;
		cout << "5. Mostrar caracteres" << endl;
		cout << "6. Contar mayusculas y minusculas" << endl;
		cout << "7. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese numero: ";
			cin >> valor;
			crear_nodo(nuevoNum, valor);
			agregar_final(listaNum, nuevoNum);
			break;
		case 2:
			mostrar_lista(listaNum);
			break;
		case 3:
			primos = contar_primos(listaNum);
			cout << "Cantidad de numeros primos: " << primos << endl;
			break;
		case 4:
			cout << "Ingrese caracter: ";
			cin >> cvalor;
			crear_nodo_c(nuevoChar, cvalor);
			agregar_final_c(listaChar, nuevoChar);
			break;
		case 5:
			mostrar_lista_c(listaChar);
			break;
		case 6:
			contar_mayus_minus(listaChar, mayus, minus);
			cout << "Mayusculas: " << mayus << ", Minusculas: " << minus << endl;
			break;
		case 7:
			cout << "Fin" << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
		
	} while (opcion != 7);
	
	return 0;
}
