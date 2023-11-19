#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
#include "cronometro.h"

float probar_vector(int[], int, void(int *, int *));

void burbujeo(int *v, int *w)
{
    using namespace std;
    int k;
    int n = w - v;
    for (k = n - 1; k > 0; k--)
    {
        if (v[k] < v[k - 1])
            swap(v[k], v[k - 1]);
    }
}

void intercambio_directo(int *v, int *w)
{
    int i;
    int n = (w - v);
    for (i = 0; i < n; i++)
    {
        burbujeo(v + i, v + n);
    }
}

int main()
{
    using namespace std;
    int n, i;
    float promedio;
    int v[20000], w[20000];

    cout << "intercambio directo" << endl;
    for (n = 1000; n <= 20000; n += 1000)
    {
        promedio = 0;
        for (i = 0; i < n; i++)
            v[i] = i;
        random_shuffle(v, v + n);
        promedio = probar_vector(v, n, intercambio_directo);

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