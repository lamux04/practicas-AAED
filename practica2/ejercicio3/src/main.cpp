#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
#include "ordenacion.h"
#include "cronometro.h"

float probar_vector(int[], int, void(int *, int *));

int main()
{
    using namespace std;
    int n, i;
    float promedio;
    int v[20000], w[20000];
    cronometro c;
    float d = 0;

    cout << "seleccion directa" << endl;
    for (n = 1000; n < 5000; n += 1000)
    {
        promedio = 0;
        for (i = 0; i < n; i++)
            v[i] = i;

        for (i = 0; i < 4; i++)
        {
            random_shuffle(v, v + n);
            promedio += probar_vector(v, n, seleccion_directa);
        }
        promedio = promedio / 20;
        cout << n << " -> " << promedio << "s" << endl;
    }

    cout << "intercambio directo" << endl;

    for (n = 1000; n < 5000; n += 1000)
    {
        promedio = 0;
        for (i = 0; i < n; i++)
            v[i] = i;

        for (i = 0; i < 4; i++)
        {
            random_shuffle(v, v + n);
            promedio += probar_vector(v, n, intercambio_directo);
        }
        promedio = promedio / 20;
        cout << n << " -> " << promedio << "s" << endl;
    }

    cout << "insercion directa" << endl;

    for (n = 1000; n < 5000; n += 1000)
    {
        promedio = 0;
        for (i = 0; i < n; i++)
            v[i] = i;

        for (i = 0; i < 4; i++)
        {
            random_shuffle(v, v + n);
            promedio += probar_vector(v, n, insercion_directa);
        }
        promedio = promedio / 20;
        cout << n << " -> " << promedio << "s" << endl;
    }

    return 0;
}

// predondicion: v inicializado con un permutacion de los n primeros naturales, k es el numero de veces a ejecutar
// postcondicion: devuelve en segundos el tiempo que tarda en ordenarse
float probar_vector(int v[], int n, void ord(int *, int *))
{
    int w[n];
    cronometro c;
    float err_rel = 0.5e-6, err_abs = 1e-6;
    int veces = 0;
    c.activar();
    do
    {
        veces++;
        memcpy(w, v, n * sizeof *v);
        (*ord)(w, w + n);
    } while (c.tiempo() <= err_abs / err_rel + err_abs);
    c.parar();
    return (c.tiempo() / veces);
}