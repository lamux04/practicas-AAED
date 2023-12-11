#include <iostream>
#include "pila-dinamica.h"
#include "cola-dinamica.h"
#include "in-out-cola.h"
#include "in_out_pila.h"
#include "pila-cola-isomorfica.h"
#include "invertir_cola.h"

void prueba_colas(Cola<int> B) {
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

void prueba_in_out() {
    using namespace std;
    Cola<int> A;
    leer_cola(A);
    cout << endl
         << A.frente() << A.tama() << endl;
    imprimir_cola(A);
}

void prueba_isomorfica () {
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

void prueba_invertir_cola () {
    Cola<int> A;
    leer_cola(A);
    invertir_cola(A, 1, 2);
    imprimir_cola(A);
}

int main() {
    using namespace std;

    prueba_invertir_cola();
    return 0;
}