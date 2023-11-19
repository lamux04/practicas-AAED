#include "polinom2.h"
#include "arit_pol.h"

polinomio operator+(polinomio &a, polinomio &b)
{
  int grado_max = a.grado() > b.grado() ? a.grado() : b.grado();
  int i;
  polinomio resultado(20);

  for (i = 0; i <= grado_max; i++) {
    resultado.coeficiente(i, a.coeficiente(i) + b.coeficiente(i));
  }

  return resultado;
}

polinomio operator-(polinomio &a, polinomio &b)
{
  int grado_max = a.grado() > b.grado() ? a.grado() : b.grado();
  int i;
  polinomio resultado(20);

  for (i = 0; i <= grado_max; i++) {
    resultado.coeficiente(i, a.coeficiente(i) - b.coeficiente(i));
  }

  return resultado;
}

polinomio operator*(polinomio &a, polinomio &b)
{
  int grado_a = a.grado(), grado_b = b.grado();
  int i, j;
  polinomio resultado(20);

  for (i = 0; i <= grado_a; i++)
    for (j = 0; j <= grado_b; j++) {
      resultado.coeficiente(i + j, resultado.coeficiente(i + j) + a.coeficiente(i) * b.coeficiente(j));
    }

  return resultado;
}

polinomio derivada(polinomio &inicial) {
  polinomio final(20);
  int i, grado_inicial = inicial.grado();
  for (i = 1; i <= grado_inicial; i++) {
    final.coeficiente(i - 1, inicial.coeficiente(i) * i);
  }

  return final;
}