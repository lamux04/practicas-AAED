#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
#include "ordenacion.h"

void intercambio_directo(int *v, int *w)
{
    int i;
    int n = (w - v);
    for (i = 0; i < n; i++)
    {
        burbujeo(v + i, v + n);
    }
}

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

void insercion_directa(int *v, int *w)
{
    int i;
    int n = w - v;
    for (i = 1; i < n; i++)
    {
        insercion(v, v + i);
    }
}

void insercion(int *v, int *w)
{
    int n = w - v;
    while (v<w &&*(w - 1)> * w)
    {
        std::swap(*(w - 1), *w);
        w--;
    }
}