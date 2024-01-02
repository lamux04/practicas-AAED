#include <cstddef>
#include <iostream>
#include <string>
#include "lista_dinamica.h"
#include "numero_binario.h"

Binario::Binario(std::string cad)
{
    size_t i;
    char c;
    for (i = 0; i < cad.size(); i++)
    {
        c = cad.at(i);
        lista.insertar(c - '0', lista.primera());
    }
}

Binario operator~(const Binario& A)
{
    Binario negado("");
    ListaDinamica<bool>::posicion i;

    for (i = A.lista.primera(); i != A.lista.fin(); i = A.lista.siguiente(i))
    {
        negado.lista.insertar(!A.lista.elemento(i), negado.lista.fin());
    }
    return negado;
}

Binario operator&(const Binario& A, const Binario& B)
{
    Binario resultado("");
    ListaDinamica<bool>::posicion i, j;

    i = A.lista.primera();
    j = B.lista.primera();

    while (i != A.lista.fin() || j != B.lista.fin())
    {
        if (i != A.lista.fin() && j != B.lista.fin())
            resultado.lista.insertar(A.lista.elemento(i) & B.lista.elemento(j), resultado.lista.fin());
        else
            resultado.lista.insertar(0, resultado.lista.fin());

        if (i != A.lista.fin())
            i = A.lista.siguiente(i);
        if (j != B.lista.fin())
            j = B.lista.siguiente(j);
    }

    return resultado;
}

Binario operator|(const Binario& A, const Binario& B)
{
    Binario resultado("");
    ListaDinamica<bool>::posicion i, j;

    i = A.lista.primera();
    j = B.lista.primera();

    while (i != A.lista.fin() || j != B.lista.fin())
    {
        if (i != A.lista.fin() && j != B.lista.fin())
            resultado.lista.insertar(A.lista.elemento(i) | B.lista.elemento(j), resultado.lista.fin());
        else if (i != A.lista.fin())
            resultado.lista.insertar(A.lista.elemento(i), resultado.lista.fin());
        else
            resultado.lista.insertar(B.lista.elemento(j), resultado.lista.fin());

        if (i != A.lista.fin())
            i = A.lista.siguiente(i);
        if (j != B.lista.fin())
            j = B.lista.siguiente(j);
    }

    return resultado;
}

Binario operator^(const Binario& A, const Binario& B)
{
    Binario resultado("");
    ListaDinamica<bool>::posicion i, j;

    i = A.lista.primera();
    j = B.lista.primera();

    while (i != A.lista.fin() || j != B.lista.fin())
    {
        if (i != A.lista.fin() && j != B.lista.fin())
            resultado.lista.insertar(A.lista.elemento(i) ^ B.lista.elemento(j), resultado.lista.fin());
        else if (i != A.lista.fin())
            resultado.lista.insertar(A.lista.elemento(i) ^ 0, resultado.lista.fin());
        else
            resultado.lista.insertar(B.lista.elemento(j) ^ 0, resultado.lista.fin());

        if (i != A.lista.fin())
            i = A.lista.siguiente(i);
        if (j != B.lista.fin())
            j = B.lista.siguiente(j);
    }

    return resultado;
}

Binario operator<<(const Binario& A, unsigned desp)
{
    Binario resultado("");
    ListaDinamica<bool>::posicion i;
    int cont;

    i = A.lista.primera();
    for (cont = 0; cont < A.lista.tama(); cont++)
    {
        if (cont < desp)
            resultado.lista.insertar(0, resultado.lista.fin());
        else {
            resultado.lista.insertar(A.lista.elemento(i), resultado.lista.fin());
            i = A.lista.siguiente(i);
        }
    }

    return resultado;
}

Binario operator>>(const Binario& A, unsigned desp)
{
    Binario resultado("");
    ListaDinamica<bool>::posicion i;
    int cont;

    for (i = A.lista.primera(), cont = 0; i != A.lista.fin(); i = A.lista.siguiente(i), ++cont)
    {
        if (cont >= desp)
            resultado.lista.insertar(A.lista.elemento(i), resultado.lista.fin());
    }

    for (desp; desp > 0; --desp)
    {
        resultado.lista.insertar(0, resultado.lista.fin());
    }

    return resultado;
}

void Binario::imprimir() const
{
    using namespace std;
    ListaDinamica<bool>::posicion i;
    cout << "BINARIO (al reves): ";
    for (i = lista.primera(); i != lista.fin(); i = lista.siguiente(i))
    {
        if (lista.elemento(i))
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}