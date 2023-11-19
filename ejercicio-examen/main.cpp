#include "cronometro.h"
#include <algorithm>
#include <iostream>
#include <cstring>

void ordenar(int *, int *);
bool prueba_ordena(int[], int[], int);
double tiempo_promedio(int);

int main () {
  using namespace std;
  const int n = 11;
  int i;
  int v[n], w[n];
  for (i = 0; i < n; i++)
    v[i] = i;
  memcpy(w, v, n * sizeof *v);
  do {
    if (!prueba_ordena(v, w, n)) {
      cout << "Falla el ejemplar: ";
      for (i = 0; i < n; i++)
        cout << v[i] << " ";
      return 1;
    }
  } while (next_permutation(v, v + n));
  cout << "Tiempo: " << tiempo_promedio(n) << endl;
  return 0;
}

bool prueba_ordena(int v[], int w[], int n) {
  int x[n];
  memcpy(x, v, n * sizeof *v);
  ordenar(x, x + n);
  return (memcmp(x, w, n * sizeof *v) == 0);
}

void ordenar(int* p, int* f)
{
  for (int* i = p; i != f - 1; ++i) {
    int* p = std::min_element(i, f); // pos. m�n. del rango [i, f)
    std::swap(*i, *p);
  }
} 

double tiempo_promedio(int n) {
  int v[n], w[n];
  int i;
  double promedio = 0;
  const int veces = 1000;
  cronometro c;
  for (i = 0; i < n; i++)
    v[i] = i;
  for (i = 1; i <= veces; i++) {
    std::random_shuffle(v, v + n);
    memcpy(w, v, n * sizeof *v);
    c.activar();
    ordenar(w, w + n);
    c.parar();
    promedio += c.tiempo();
  }
  return (promedio / (float) veces);
}