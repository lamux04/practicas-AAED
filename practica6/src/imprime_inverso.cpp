#include "lista_dinamica.h"
#include "imprime_inverso.h"
#include "pila-dinamica.h"
#include <iostream>

void imprime_inverso(const ListaDinamica<int>& A, ListaDinamica<int>::posicion p)
{
    using namespace std;
    Pila<int> pila;
    cout << "LISTA INVERTIDA: ";

    for (ListaDinamica<int>::posicion q = p; q != A.fin(); q = A.siguiente(q))
        pila.push(A.elemento(q));

    while (!pila.vacia())
    {
        cout << pila.tope();
        pila.pop();
    }
}