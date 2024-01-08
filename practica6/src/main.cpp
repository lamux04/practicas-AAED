#include <iostream>
#include "lista_dinamica.h"
#include "lista_doblemente_enlazada.h"
#include "lista_ordenada.h"
#include "lista_circular.h"
#include "in_out_lista.h"
#include "operaciones_lista.h"
#include "imprime_inverso.h"
#include "conjunto.h"
#include "lista_de_listas.h"
#include "numero_binario.h"
#include "juego_circular.h"

#include <string>
#include <cstring>

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
    A.insertar(5, A.anterior(A.siguiente(A.siguiente(A.siguiente(A.primera())))));

    // B = A;
    // A = B;

    for (Lista<int>::posicion q = A.primera(); q != A.fin(); q = A.siguiente(q))
    {
        std::cout << A.elemento(q);
    }
    // imprimir_lista(A);
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
    ListaDinamica<int> A;
    ListaDinamica<int> B;

    A.insertar(7, A.fin());
    A.insertar(3, A.fin());
    A.insertar(7, A.fin());
    A.insertar(4, A.fin());
    A.insertar(7, A.fin());
    A.insertar(6, A.fin());
    A.insertar(7, A.fin());

    A.insertar(5, A.siguiente(A.siguiente(A.anterior(A.siguiente(A.primera())))));

    // imprimir_lista(A);

    // eliminar_elemento(A, 7);

    // imprimir_lista(A);

    // eliminar_elemento(A, 7);

    // imprimir_lista(A);
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

void prueba_imprime_inverso()
{
    ListaDinamica<int> A;
    A.insertar(3, A.fin());
    A.insertar(4, A.fin());
    A.insertar(6, A.fin());
    A.insertar(7, A.fin());
    A.insertar(5, A.anterior(A.siguiente(A.siguiente(A.siguiente(A.primera())))));

    imprime_inverso(A, A.siguiente(A.siguiente(A.primera())));
}

void prueba_conjuntos()
{
    Conjunto<int> A;
    Conjunto<int> B;
    Conjunto<int> C;
    A.agregar(3);
    A.agregar(5);
    A.agregar(4);
    A.agregar(6);

    B.agregar(4);
    B.agregar(3);
    B.agregar(2);
    B.agregar(7);

    A.imprimir();
    B.imprimir();

    C = diferencia(A, B);
    C.imprimir();
}

void prueba_concatenar_listas()
{
    ListaDinamica<int> A;
    A.insertar(3, A.fin());
    A.insertar(5, A.fin());
    A.insertar(7, A.fin());
    A.insertar(2, A.fin());
    A.insertar(1, A.fin());

    ListaDinamica<int> B;
    B.insertar(9, B.fin());
    B.insertar(2, B.fin());
    B.insertar(1, B.fin());
    B.insertar(0, B.fin());
    B.insertar(15, B.fin());

    ListaDinamica<ListaDinamica<int>> LInic;
    LInic.insertar(A, LInic.fin());
    LInic.insertar(B, LInic.fin());

    ListaDinamica<int> LConcat = concatenar_listas(LInic);
    imprimir_lista(LConcat);
}

void prueba_binario()
{
    using namespace std;

    Binario A("10010");
    Binario C("101");
    A.imprimir();

    Binario B("");
    B = ~A;

    cout << "NOT" << endl;
    B.imprimir();

    cout << "AND" << endl;
    B = A & C;
    B.imprimir();

    cout << "OR" << endl;
    B = A | C;
    B.imprimir();

    cout << "XOR" << endl;
    B = A ^ C;
    B.imprimir();

    cout << "DESPLAZAMIENTO i 2" << endl;
    B = A << 2;
    B.imprimir();
    B = C << 1;
    B.imprimir();

    cout << "DESPLAZAMIENTO d 2" << endl;
    B = A >> 2;
    B.imprimir();
    B = C >> 1;
    B.imprimir();
}

void prueba_juego_circular()
{
    tJugadores jugadores;
    pos_jugador pos;
    tJugador j1;
    j1.nombre = "Javier";
    j1.num = 3;

    tJugador j2;
    j2.nombre = "Antonio";
    j2.num = 4;

    tJugador j3;
    j3.nombre = "Javi";
    j3.num = 6;

    tJugador j4;
    j4.nombre = "Robert";
    j4.num = 1;

    tJugador j5;
    j5.nombre = "Lucia";
    j5.num = 3;

    tJugador j6;
    j6.nombre = "Fran";
    j6.num = 2;

    pos = jugadores.inipos();
    jugadores.insertar(j1, pos);
    pos = jugadores.siguiente(pos);
    jugadores.insertar(j2, pos);
    pos = jugadores.siguiente(pos);
    jugadores.insertar(j3, pos);
    pos = jugadores.siguiente(pos);
    jugadores.insertar(j4, pos);
    pos = jugadores.siguiente(pos);
    jugadores.insertar(j5, pos);
    pos = jugadores.siguiente(pos);
    jugadores.insertar(j6, pos);

    pos = jugadores.inipos();
    for (int i = 0; i < 2; ++i)
    {
        pos = jugadores.siguiente(pos);
    }

    tJugador ganador = jugar_juego(jugadores, pos);
    std::cout << "GANADOR: " << ganador.nombre;
}

int main()
{
    using namespace std;

    prueba_juego_circular();

    return 0;
}