#include "lista_dinamica.h"

void eliminar_elemento(Lista<int>& A, const int &x)
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