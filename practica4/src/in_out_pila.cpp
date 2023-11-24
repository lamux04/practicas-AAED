#include <iostream>
#include "pila-dinamica.h"
#include "in_out_pila.h"

void imprimir_pila_tope_derecha(Pila<char>& A) {
    using namespace std;
    Pila<char> B, C;
    C = A;
    cout << "PILA: ";
    while (!C.vacia()) 
    {
        B.push(C.tope());
        C.pop();
    }
    while (!B.vacia())
    {
        cout << B.tope();
        B.pop();
    }
    cout << endl;
}


void imprimir_pila_tope_izquierda(Pila<char>& A) {
    using namespace std;
    cout << "PILA: ";
    Pila<char> B;
    B = A;
    while (!B.vacia())
    {
        cout << B.tope();
        B.pop();
    }
    cout << endl;
}

void imprimir_pila_tope_derecha(Pila<int>& A) {
    using namespace std;
    Pila<int> B, C;
    C = A;
    cout << "PILA: ";
    while (!C.vacia()) 
    {
        B.push(C.tope());
        C.pop();
    }
    while (!B.vacia())
    {
        cout << B.tope();
        B.pop();
    }
    cout << endl;
}


void imprimir_pila_tope_izquierda(Pila<int>& A) {
    using namespace std;
    cout << "PILA: ";
    Pila<int> B;
    B = A;
    while (!B.vacia())
    {
        cout << B.tope();
        B.pop();
    }
    cout << endl;
}

void leer_pila(Pila<char>& A) {
    using namespace std;
    char a;
    cout << "Introduce caracteres a la pila (control d para parar): ";
    while (cin.get(a))
    {
        A.push(a);
    }
    cout << endl;
}

void leer_pila(Pila<int>&A) {
    using namespace std;
    char a;
    cout << "Introduce enteros a la pila (control d para parar): ";
    while (cin.get(a))          // cin devuelve false si lee control d
    {
        A.push(a - '0');
    }
    cout << endl;
}