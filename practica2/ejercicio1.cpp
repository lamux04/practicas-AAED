#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>

void intercambio_directo(int *, int);
void burbujeo(int *, int, int);
void seleccion_directa(int[], int);
void insercion_directa(int v[], int n);
void insercion(int v[], int i, int j);

int main()
{
    using namespace std;
    int v[] = {2, 3, 5, 6, 1, 2};

    insercion_directa(v, 6);

    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << " " << v[5] << endl;
}

void intercambio_directo(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        burbujeo(v, i, n - 1);
    }
}

void burbujeo(int v[], int i, int j)
{
    using namespace std;
    int k;
    for (k = j; k > i; k--)
    {
        if (v[k] < v[k - 1])
            swap(v[k], v[k - 1]);
    }
}

void seleccion_directa(int v[], int n)
{
    int i;
    int *p;
    for (i = 0; i < n; i++)
    {
        p = std::min_element(v + i, v + n);
        std::swap(v[i], *p);
    }
}

void insercion_directa(int v[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        insercion(v, 0, i);
    }
}

void insercion(int v[], int i, int j)
{
    while (i < j && v[j - 1] > v[j])
    {
        std::swap(v[j - 1], v[j]);
        j--;
    }
}