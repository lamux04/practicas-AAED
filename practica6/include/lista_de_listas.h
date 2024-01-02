#ifndef LISTA_DE_LISTAS
#define LISTA_DE_LISTAS
#include "lista_dinamica.h"

template <typename T>
ListaDinamica<T> concatenar_listas(ListaDinamica<ListaDinamica<T>> LInic)
{
    typename ListaDinamica<ListaDinamica<T>>::posicion i;
    typename ListaDinamica<T>::posicion j;
    ListaDinamica<T> LAux, LConcat;
    for (i = LInic.primera(); i != LInic.fin(); i = LInic.siguiente(i))
    {
        LAux = LInic.elemento(i);
        for (j = LAux.primera(); j != LAux.fin(); j = LAux.siguiente(j))
        {
            LConcat.insertar(LAux.elemento(j), LConcat.fin());
        }
    }

    return LConcat;
}

#endif