#include <iostream>
#include "lista_dinamica.h"
#include "lista_ordenada.h"
#include "in_out_lista.h"

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

    Lista<int>::posicion p = A.primera();  // Obtener la posición del primer elemento

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

int main()
{
    using namespace std;

    prueba_lista_ordenada();

    return 0;
}