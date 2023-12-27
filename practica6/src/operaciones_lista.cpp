#include "lista_dinamica.h"
#include "lista_ordenada.h"

void eliminar_elemento(Lista<int> &A, const int &x)
{
    Lista<int>::posicion p = A.primera();
    while (p != A.fin())
    {
        if (A.elemento(p) == x)
            A.eliminar(p);
        else
            p = A.siguiente(p);
    }
}

ListaOrdenada<int> concatenar_ordenadas(const ListaOrdenada<int> &A, const ListaOrdenada<int> &B)
{
    ListaOrdenada<int> C;
    C = A;
    for (ListaOrdenada<int>::posicion p = B.primera(); p != B.fin(); p = B.siguiente(p))
    {
        C.insertar(B.elemento(p));
    }

    return C;
}