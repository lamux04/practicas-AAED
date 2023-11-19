#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
#include "cronometro.h"

void insercion(int *v, int *w)
{
    int n = w - v;
    while (v<w &&*(w - 1)> * w)
    {
        std::swap(*(w - 1), *w);
        w--;
    }
}

void insercion_directa(int *v, int *w)
{
    int i;
    int n = w - v;
    for (i = 1; i < n; i++)
    {
        insercion(v, v + i);
    }
}

float probar_vector(int[], int, void(int *, int *));

int main()
{
    using namespace std;
    int n, i;
    float promedio;
    int v[20000], w[20000];

    cout << "insercion directa" << endl;
    for (n = 1000; n <= 20000; n += 1000)
    {
        promedio = 0;
        for (i = 0; i < n; i++)
            v[i] = i;
        random_shuffle(v, v + n);
        promedio = probar_vector(v, n, insercion_directa);

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