#include <iostream>
#include "lista_dinamica.h"
#include "in_out_lista.h"

void imprimir_lista(Lista<int> A) {
    Lista<int>::posicion p;
    std::cout << "LISTA: ";
    for (p = A.primera(); p < A.fin(); ++p)
    {
        std::cout << A.elemento(p) << " ";
    }
    std::cout << std::endl;
}