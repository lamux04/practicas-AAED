#include <cassert>
#include "polinom2.h"

polinomio::polinomio(unsigned tamMax) {
  unsigned i;
  gradoMax = tamMax;
  // v = new double[gradoMax + 1];
  for (i = 0; i <= gradoMax; i++)
    v[i] = 0;
  grado_pol = 0;
}

unsigned polinomio::grado() {
  return (grado_pol);
}

double polinomio::coeficiente(unsigned n) {
  if (n > grado_pol)
    return 0;
  return v[n];
}

void polinomio::coeficiente(unsigned n, double c) {
  assert(n <= gradoMax);
  v[n] = c;
  unsigned i;
  if (c == 0) {
    if (n == grado_pol) {
      for (i = 0; i < grado_pol; i++) {
        if (v[n] != 0)
          grado_pol = i;
      }
    }
  } else if (n > grado_pol)
    grado_pol = n;
}

// polinomio::polinomio(const polinomio& P) {
//   unsigned i;
//   v = new double[P.gradoMax];
//   gradoMax = P.gradoMax;
//   grado_pol = P.grado_pol;
//   for (i = 0; i <= grado_pol; i++)
//     v[i] = P.v[i];
// }

// polinomio& polinomio::operator=(const polinomio& P) {
//   unsigned i;
//   if (this != &P)
//   {
//     v = new double[P.gradoMax];
//     gradoMax = P.gradoMax;
//     grado_pol = P.grado_pol;
//     for (i = 0; i <= grado_pol; i++)
//       v[i] = P.v[i];
//     delete[] P.v;
//   }

//   return *this;
// }

// polinomio::~polinomio() {
//   delete[] v;
// }