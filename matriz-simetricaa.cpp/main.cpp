#include <iostream>
#include "cronometro.h"
#define N 1000

double medir_tiempo(int[N][N], int);
bool simetrica(int[N][N], int);

int main () {
  using namespace std;
  int n = 50;
  int m[N][N];
  int i, j;

  for (n = 50; n <= 1000; n += 50)
  {
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        m[i][j] = 0;

    cout << n << " -> " << medir_tiempo(m, n);
  }
  return 0;
}

double medir_tiempo(int m[N][N], int n) {
  cronometro c;
  int veces = 0;
  float err_abs = 0.01, err_rel = 0.1e-2;

  c.activar();
  do {
    simetrica(m, n);
    veces++;
  } while (c.tiempo() <= err_abs / err_rel + err_abs);
  c.parar();

  return (c.tiempo() / veces);
}

bool simetrica(int m[N][N], int n) {
  bool b = true;
  int i = 0;
  while (b && i < n) {
    int j = i + 1;
    while (b && j < n) {
      b = (m[i][j] == m[j][i]);
      ++j;
    }
    ++i;
  }
  return b;
}