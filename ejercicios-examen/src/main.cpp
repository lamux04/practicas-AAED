#include <iostream>
#include <string>
#include "cola_dinamica.h"
#include "cola_vectorial.h"
#include "lista_doblmente_enlazada.h"
#include "lista_simplemente_enlazada.h"
#include "cocina.h"
#include "hipermercado.h"
#include "diccionario.h"
#include "gestor_impresion.h"
#include "pila_dinamica.h"
#include "cursor.h"
#include "cartelera.h"
#include "token_bus.h"
#include "tres_en_raya.h"
#include "lista_circular.h"

void prueba_lista(ListaCircular<int> A)
{
    using namespace std;
    ListaCircular<int> B = A;
    ListaCircular<int>::posicion pos = B.inipos();

    cout << B.elemento(B.inipos()) << " ";

    for (pos = B.siguiente(pos); pos != B.inipos(); pos = B.siguiente(pos))
    {
        cout << B.elemento(pos) << " ";
    }
}

int main()
{
    using namespace std;
    ListaCircular<int> A;
    A.insertar(3, A.inipos());
    A.insertar(4, A.inipos());
    A.insertar(5, A.siguiente(A.inipos()));
    A.insertar(6, A.siguiente(A.inipos()));

    prueba_lista(A);

    return 0;
}