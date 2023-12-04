#include <iostream>
#include "cola-dinamica.h"
#include "in-out-cola.h"

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

int main() {
    using namespace std;
    Cola<int> A;
    Cola<int> B;

    prueba_in_out();

    return 0;
}