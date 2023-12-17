#include <iostream>
#include "lista_dinamica.h"
#include "lista_ordenada.h"
#include "in_out_lista.h"

// void imprimir_lista(Lista<int> A) {
//     Lista<int>::posicion p;
//     std::cout << "LISTA: ";
//     for (p = A.primera(); p < A.fin(); ++p)
//     {
//         std::cout << A.elemento(p) << " ";
//     }
//     std::cout << std::endl;
// }

void imprimir_lista(Lista<int> A)
{
    using namespace std;
    cout << "LISTA: ";
    for (Lista<int>::posicion p = A.primera(); p != A.fin(); p = A.siguiente(p))
    {
        cout << A.elemento(p) << " ";
    }
    cout << endl;
}

void imprimir_lista_ordenada(ListaOrdenada<int> A)
{
    using namespace std;
    cout << "LISTA: ";
    for (ListaOrdenada<int>::posicion p = A.primera(); p != A.fin(); p = A.siguiente(p))
    {
        cout << A.elemento(p) << " ";
    }
    cout << endl;
}