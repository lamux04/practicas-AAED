// #include <iostream>
// #include <math.h>
// #include "cola-dinamica.h"
// #include "pila-dinamica.h"
// #include "pila-cola-isomorfica.h"

// bool pila_cola_isomorfica(const Pila<int>& pila, const Cola<int>& cola) {
//     // PILA PARES
//     // COLA IMPARES
//     Pila<int> pila_al_reves;
//     Pila<int> pila_auxiliar = pila;
//     Cola<int> cola_auxiliar = cola;
//     bool isomorfica = true;
//     bool impar = true;

//     while (!pila_auxiliar.vacia())
//     {
//         pila_al_reves.push(pila_auxiliar.tope());
//         pila_auxiliar.pop();
//     }
//     if (!pila_al_reves.vacia())
//         pila_al_reves.pop();
//     if (ceil(pila_al_reves.tama() / 2.0) != ceil(cola_auxiliar.tama() / 2.0))
//         isomorfica = false;

//     while (!pila_al_reves.vacia() && !cola_auxiliar.vacia() && isomorfica)
//     {
//         if (impar)
//             isomorfica = cola_auxiliar.frente() == pila_al_reves.tope();
//         impar = !impar;
//         pila_al_reves.pop();
//         cola_auxiliar.pop();
//     }

//     return isomorfica;
// }