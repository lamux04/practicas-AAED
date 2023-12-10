#include <iostream>
#include "lista_pseudoestatica.h"
#include "in_out_lista.h"

void prueba_lista(Lista<int> B) {
    using namespace std;
    Lista<int> A(20);
    A = B;

    imprimir_lista(A);
    
    A.insertar(7, A.primera());
    A.insertar(-3, A.siguiente(A.primera()));
    A.eliminar(A.anterior(A.anterior(A.fin()))); // LISTA: 7 -3 3 2 5 1 7 0 

    imprimir_lista(A);
}

int main() {
    Lista<int> A(20);

    A.insertar(3, A.fin());
    A.insertar(2, A.fin());
    A.insertar(5, A.fin());
    A.insertar(1, A.fin());
    A.insertar(7, A.fin());
    A.insertar(0, A.fin());
    prueba_lista(A);
    return 0;
}