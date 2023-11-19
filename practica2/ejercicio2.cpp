#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>

void intercambio_directo(int *, int *);
void burbujeo(int *, int *);
void seleccion_directa(int *, int *);
void insercion_directa(int *, int *);
void insercion(int *, int *);

bool prueba_ordena(int[], int[], int);
int pruebas_caja_negra();

int main()
{
    using namespace std;
    return pruebas_caja_negra();
}

bool prueba_ordena(int e[], int s[], int n)
{
    using namespace std;
    int v[n];
    int w[n];
    int x[n];

    memcpy(v, e, n * sizeof *e);
    memcpy(w, e, n * sizeof *e);
    memcpy(x, e, n * sizeof *e);

    insercion_directa(v, v + n);
    intercambio_directo(w, w + n);
    seleccion_directa(x, x + n);

    if (memcmp(v, s, n * sizeof *e) != 0)
        return false;
    if (memcmp(w, s, n * sizeof *e) != 0)
        return false;
    if (memcmp(x, s, n * sizeof *e) != 0)
        return false;
    return true;
}

int pruebas_caja_negra()
{
    using namespace std;
    int v[9], w[9];
    int n, i = 0;
    for (n = 1; n <= 9; n++)
    {
        v[n - 1] = n - 1;
        memcpy(w, v, n * sizeof *v);
        do
        {
            cout << ++i << " ";
            if (!prueba_ordena(v, w, n))
            {
                cout << "ERROR" << endl;
                for (int j = 0; j < n; j++)
                    cout << v[j] << " ";
                return 1;
            }
        } while (std::next_permutation(v, v + n));
    }
    return 0;
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