#include <iostream>
#include "pila-dinamica.h"
#include "cola-dinamica.h"
#include "in-out-cola.h"
#include "in_out_pila.h"
#include "pila-cola-isomorfica.h"
#include "invertir_cola.h"
#include "bicola.h"
#include "pila_bicola.h"
#include "cola_bicola.h"
#include "aerodromo.h"

void prueba_colas(Cola<int> B)
{
    using namespace std;
    while (!B.vacia())
    {
        std::cout << B.frente() << " ";
        B.pop();
    }

    B.push(3);
    cout << endl;
    cout << B.tama();
    cout << B.frente();
}

void prueba_in_out()
{
    using namespace std;
    Cola<int> A;
    leer_cola(A);
    cout << endl
         << A.frente() << A.tama() << endl;
    imprimir_cola(A);
}

void prueba_isomorfica()
{
    Pila<int> A;
    Cola<int> B;

    A.push(2);
    A.push(3);
    A.push(5);
    A.push(3);
    A.push(2);
    A.push(7);
    A.push(3);
    B.push(3);
    B.push(3);

    std::cout << pila_cola_isomorfica(A, B);
}

void prueba_invertir_cola()
{
    Cola<int> A;
    leer_cola(A);
    invertir_cola(A, 1, 2);
    imprimir_cola(A);
}

void prueba_bicola()
{
    using namespace std;
    Bicola<int> A;
    Bicola<int> B;

    A.push_final(1);
    A.push_final(2);
    A.push_final(3);
    A.push_final(4);
    A.push_final(5);
    A.push_frente(0);
    A.pop_final();
    A.pop_frente();
    A.pop_frente();

    B = A;
    A = B;

    while (!A.vacia())
    {
        cout << A.frente();
        A.pop_frente();
    }
}

void prueba_pila_bicola()
{
    using namespace std;
    int a;
    PilaBicola<int> A;
    A.push(2);
    A.push(3);
    A.push(5);
    A.push(1);
    A.push(3);
    A.push(6);
    A.push(7);

    while (!A.vacia())
    {
        cout << A.tope();
        A.pop();
    }
}

void prueba_cola_bicola()
{
    using namespace std;
    ColaBicola<int> A;
    ColaBicola<int> B;
    A.push(2);
    A.push(3);
    A.push(5);
    A.push(1);
    A.push(3);
    A.push(6);
    A.push(7);

    B = A;
    A = B;

    while (!A.vacia())
    {
        cout << A.frente();
        A.pop();
    }
}

void prueba_aerodromo()
{
    using namespace std;
    Aerodromo A;
    avioneta a;
    int x;
    do
    {
        cout << "Introduce un numero (1 estacionar / 2 sacar avioneta / 0 salir): ";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Introduce la matricula de la avioneta a estacionar: ";
            cin >> a;
            A.estacionar_avioneta(a);
            break;
        case 2:
            cout << "Introduce la matricula de la avioneta a sacar: ";
            cin >> a;
            A.sacar_avioneta(a);
            break;
        }

        A.imprimir();
    } while (x != 0);
}

int main()
{
    using namespace std;

    prueba_aerodromo();
    return 0;
}