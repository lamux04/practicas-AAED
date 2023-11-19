#include <iostream>
#include <cstring>
#include <algorithm>

static void inserta(int* i, int* j)
{
  int x = *j;
  while (j != i && x < *(j - 1)) {
    *j = *(j - 1);
    --j;
  }
  *j = x;
}

void ordena(int* p, int* f)
{
  for (int* i = p + 1; i != f; ++i)
    inserta(p, i);
}

// cabecera: bool prueba_ordena(int v[], int w[], int n)
// precondicion: n > 0, w tiene los mismos elementos que v pero ordenados
// postcondicion: devuelve true si la funcion ordena ordena el vector v correctamente
bool prueba_ordena(int v[], int w[], int n) {
  using namespace std;
  int x[n];
  memcpy(x, v, n * sizeof *v);
  ordena(x, x + n);
  return (memcmp(x, w, n * sizeof *x) == 0);
}

int main () {
  using namespace std;
  int n;
  int v[9], w[9];
  for (n = 1; n <= 9; n++) {
    v[n - 1] = n - 1;
    w[n - 1] = n - 1;
    do {
      if (!prueba_ordena(v, w, n)) {
        cout << "Error";
        return 1;
      }
    } while (next_permutation(v, v + n));
  }
  return 0;
}