#include <iostream>
#include <string>
#include "nodo.h"
using namespace std;

template <typename T>
void agregarNodo(Nodo<T>*& head, T data) {
    Nodo<T>* nuevoNodo = new Nodo<T>(data);
    if (!head) {
        head = nuevoNodo;
    }
    else {
        Nodo<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = nuevoNodo;
    }
}

template <typename T>
void imprimirLista(Nodo<T>* head) {
    Nodo<T>* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}


template <typename T>
void liberarLista(Nodo<T>*& head) {
    Nodo<T>* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nLa lista ha sido eliminada.\n" << endl;
}


template <typename T>
void menuAcciones(Nodo<T>*& lista) {
    int opcion;
    do {
        cout << "\nQue deseas hacer con la lista?\n";
        cout << "1. Mostrar la lista\n";
        cout << "2. Borrar la lista\n";
        cout << "3. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\nLista enlazada: ";
            imprimirLista(lista);
            break;
        case 2:
            liberarLista(lista);
            break;
        case 3:
            cout << "\nRegresando al menu principal...\n";
            break;
        default:
            cout << "\nOpcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}

void menu() {
    int opcion;
    do {
        cout << "\nSeleccione el tipo de lista enlazada que desea crear:\n";
        cout << "1. Lista de enteros\n";
        cout << "2. Lista de strings\n";
        cout << "3. Lista de caracteres\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            Nodo<int>* listaInt = nullptr;
            int valor;
            char continuar;
            do {
                cout << "\nIngrese un valor entero: ";
                cin >> valor;
                agregarNodo(listaInt, valor);
                cout << "\nDesea agregar otro valor? (s/n): ";
                cin >> continuar;
            } while (continuar == 's');
            menuAcciones(listaInt);
            liberarLista(listaInt);
            break;
        }
        case 2: {
            Nodo<string>* listaString = nullptr;
            string valor;
            char continuar;
            do {
                cout << "\nIngrese un string: ";
                cin >> valor;
                agregarNodo(listaString, valor);
                cout << "\nDesea agregar otro valor? (s/n): ";
                cin >> continuar;
            } while (continuar == 's');
            menuAcciones(listaString);
            liberarLista(listaString);
            break;
        }
        case 3: {
            Nodo<char>* listaChar = nullptr;
            char valor;
            char continuar;
            do {
                cout << "\nIngrese un caracter: ";
                cin >> valor;
                agregarNodo(listaChar, valor);
                cout << "\nDesea agregar otro valor? (s/n): ";
                cin >> continuar;
            } while (continuar == 's');
            menuAcciones(listaChar);
            liberarLista(listaChar);
            break;
        }
        case 4:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "\nOpcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
}

int main() {
    menu();
    return 0;
}