#include <iostream>
#include "lista_dinamica.h"
#include "lista_ordenada.h"
#include "lista_circular.h"
#include "in_out_lista.h"
#include "operaciones_lista.h"

// void prueba_lista(Lista<int> B)
// {
//     using namespace std;
//     Lista<int> A;
//     A = B;

//     imprimir_lista(A);

//     A.insertar(7, A.primera());
//     A.insertar(-3, A.siguiente(A.primera()));
//     A.eliminar(A.anterior(A.anterior(A.fin()))); // LISTA: 7 -3 3 2 5 1 7 0

//     imprimir_lista(A);
// }

void prueba_lista_dinamica()
{
    Lista<int> A;
    Lista<int> B;

    A.insertar(3, A.fin());
    A.insertar(4, A.fin());
    A.insertar(6, A.fin());
    A.insertar(7, A.fin());

    A.insertar(5, A.siguiente(A.siguiente(A.anterior(A.siguiente(A.primera())))));

    for (Lista<int>::posicion q = A.primera(); q != A.fin(); q = A.siguiente(q))
    {
        std::cout << A.elemento(q);
    }
}

void prueba_lista_ordenada()
{
    ListaOrdenada<int> A;

    A.insertar(3);
    A.insertar(2);
    A.insertar(5);
    A.insertar(4);
    A.insertar(9);

    imprimir_lista_ordenada(A);
}

void prueba_lista_circular()
{
    using namespace std;
    ListaCircular<int> A;
    ListaCircular<int> B;
    int i = 0;

    ListaCircular<int>::posicion p;
    p = A.inipos();

    A.insertar(3, p);
    A.insertar(4, p);
    A.insertar(6, p);
    A.insertar(7, p);
    A.insertar(8, p);
    A.insertar(9, p);

    B = A;
    A = B;

    for (ListaCircular<int>::posicion q = A.inipos(), i = 0; i == 0 || q != A.inipos(); q = A.siguiente(q), i++)
    {
        if (A.elemento(q) == 6)
            A.eliminar(q);
        cout << A.elemento(q) << " ";
    }
}

void prueba_eliminar()
{
    Lista<int> A;
    Lista<int> B;

    A.insertar(7, A.fin());
    A.insertar(3, A.fin());
    A.insertar(7, A.fin());
    A.insertar(4, A.fin());
    A.insertar(7, A.fin());
    A.insertar(6, A.fin());
    A.insertar(7, A.fin());

    A.insertar(5, A.siguiente(A.siguiente(A.anterior(A.siguiente(A.primera())))));

    imprimir_lista(A);

    eliminar_elemento(A, 7);

    imprimir_lista(A);

    eliminar_elemento(A, 7);

    imprimir_lista(A);
}

void prueba_concatenar_ordenadas()
{
    ListaOrdenada<int> A;
    ListaOrdenada<int> B;
    ListaOrdenada<int> C;

    A.insertar(3);
    A.insertar(2);
    A.insertar(5);
    A.insertar(4);
    A.insertar(9);
    B.insertar(1);
    B.insertar(0);
    B.insertar(-2);
    B.insertar(7);
    B.insertar(9);

    imprimir_lista_ordenada(A);
    imprimir_lista_ordenada(B);

    C = concatenar_ordenadas(A, B);

    imprimir_lista_ordenada(C);
}

int main()
{
    using namespace std;

    prueba_concatenar_ordenadas();

    return 0;
}