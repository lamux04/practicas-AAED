#include <iostream>
#include <algorithm>
#include <cstring>
#include "cronometro.h"

// Inserci�n ordenada de *j en el rango ordenado [i, j - 1]
static void inserta(int* i, int* j)
{
  int x = *j;
  while (j != i && x < *(j - 1)) {
    *j = *(j - 1);
    --j;
  }
  *j = x;
}

void ordenacion_insercion(int* p, int* f)
{
  for (int* i = p + 1; i != f; ++i)
    inserta(p, i);
}


double tiempo_ordenacion(int v_desordenado[], int n) {
  cronometro c;
  float err_abs = 1e-6, err_rel = 0.5e-6;
  int w[n], veces = 0;
  c.activar();
  do
  {
    memcpy(w, v_desordenado, n * sizeof *v_desordenado);
    ordenacion_insercion(w, w + n);
    veces++;
  } while (c.tiempo() < err_abs / err_rel + err_abs);
  c.parar();

  return (c.tiempo() / veces);
}

int main () {
  using namespace std;
  int v[20000], w[20000];
  int n, i;
  double tiempo;

  cout << "Ordenacion por insercion" << endl;
  for (n = 1000; n <= 20000; n += 1000)
  {
    for (i = 0; i < n; i++)
      v[i] = i;

    memcpy(w, v, n * sizeof *v);
    tiempo = 0;
    for (i = 0; i < 2; i++)
    {
      random_shuffle(w, w + n);
      tiempo += tiempo_ordenacion(w, n);
    }
    tiempo /= 5;
    cout << n << " -> " << tiempo << endl;
  }

  return 0;
}