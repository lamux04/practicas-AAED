#include <iostream>
#include "cola-dinamica.h"
#include "in-out-cola.h"

void leer_cola(Cola<int> &C) {
    using namespace std;
    char a;
    cout << "Introduce la cola: ";
    while (cin >> a)
    {
        C.push(a - '0');
    }
    cout << endl;
}
void imprimir_cola(Cola<int> C) {
    using namespace std;
    cout << "COLA: ";
    while (!C.vacia())
    {
        cout << C.frente();
        C.pop();
    }
    cout << endl;
}