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
#include "bicola.h"

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

void prueba_bicola(Bicola<int> A)
{
    using namespace std;
    Bicola<int> B = A;
    A = B;

    while(!A.vacia())
    {
        cout << A.ver_inicio() << " ";
        A.pop_inicio();
    }
}

int main()
{
    using namespace std;
    prueba_gestor_impresion();
    return 0;
}