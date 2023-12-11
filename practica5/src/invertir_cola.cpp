#include "cola-dinamica.h"
#include "pila-dinamica.h"
#include "invertir_cola.h"

void invertir_cola(Cola<int>& cola, int a, int b) {
    Cola<int> cola_final;
    Pila<int> pila_aux;
    Cola<int> cola_aux;

    while (!cola.vacia() && cola.frente() != a)
    {
        cola_final.push(cola.frente());
        cola.pop();
    }

    while (!cola.vacia() && cola.frente() != b)
    {
        pila_aux.push(cola.frente());
        cola_aux.push(cola.frente());
        cola.pop();
    }

    if (!cola.vacia())
    {
        cola_final.push(cola.frente());
        cola.pop();

        while (!pila_aux.vacia())
        {
            cola_final.push(pila_aux.tope());
            pila_aux.pop();
        }
    } else
    {
        while (!cola_aux.vacia())
        {
            cola_final.push(cola_aux.frente());
            cola_aux.pop();
        }
    }

    while (!cola.vacia())
    {
        cola_final.push(cola.frente());
        cola.pop();
    }

    cola = cola_final;
}