#include "pila_pseudoestatica.h"
#include <cstdlib>
#include <iostream>
#include "cubilete.h"

int genera_numero(int a, int b)
{
    return ((rand() % (b - a + 1)) + a);
}

void prueba_cubiletes()
{
    using namespace std;
    PilaCubiletes A(12), B(12);
    for (int i = 0; i < 12; i++)
    {
        tCubo a(genera_numero(1, 12), genera_numero(0, 1));
        A.push(a);
    }

    B = A;
    while (!A.vacia())
    {
        cout << A.tope().tamano << "|" << A.tope().boca_abajo << " ";
        A.pop();
    }

    cout << endl;

    A = ordenar_cubiletes(B);

    while (!A.vacia())
    {
        cout << A.tope().tamano << "|" << A.tope().boca_abajo << " ";
        A.pop();
    }

    cout << endl;
}

PilaCubiletes ordenar_cubiletes(PilaCubiletes &cubiletes)
{
    PilaCubiletes cubiletesOrdenados(cubiletes.tamaMax());
    tCubo aux;
    int i;

    while (!cubiletes.vacia())
    {
        aux = cubiletes.tope();
        cubiletes.pop();
        aux.boca_abajo = true;
        i = cubiletesOrdenados.tama();

        while (!cubiletesOrdenados.vacia() && cubiletesOrdenados.tope().tamano < aux.tamano)
        {
            cubiletes.push(cubiletesOrdenados.tope());
            cubiletesOrdenados.pop();
        }

        cubiletesOrdenados.push(aux);

        while (i + 1 != cubiletesOrdenados.tama())
        {
            cubiletesOrdenados.push(cubiletes.tope());
            cubiletes.pop();
        }
    }

    return cubiletesOrdenados;
}