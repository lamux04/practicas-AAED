#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
#include "../include/cronometro.h"

float probar_vector(int[], int, void(int *, int *));

void seleccion_directa(int *v, int *w)
{
    int i;
    int *p;
    int n = w - v;
    for (i = 0; i < n; i++)
    {
        p = std::min_element(v + i, v + n);
        std::swap(v[i], *p);
    }
}

int main()
{
    using namespace std;
    int n, i;
    float promedio;
    int v[20000], w[20000];

    cout << "seleccion directa" << endl;
    for (n = 1000; n <= 20000; n += 1000)
    {
        promedio = 0;
        for (i = 0; i < n; i++)
            v[i] = i;
        random_shuffle(v, v + n);
        promedio = probar_vector(v, n, seleccion_directa);

        cout << n << " -> " << promedio << "s" << endl;
    }

    return 0;
}

// predondicion: v inicializado con un permutacion de los n primeros naturales, k es el numero de veces a ejecutar
// postcondicion: devuelve en segundos el tiempo que tarda en ordenarse
float probar_vector(int v[], int n, void ord(int *, int *))
{
    int i, w[n];
    cronometro c;
    c.activar();
    memcpy(w, v, n * sizeof *v);
    (*ord)(w, w + n);
    c.parar();
    return (c.tiempo());
}