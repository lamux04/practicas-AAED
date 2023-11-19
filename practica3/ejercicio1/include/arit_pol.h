#ifndef ARIT_POL
#define ARIT_POL

polinomio operator+(polinomio &, polinomio &);
polinomio operator-(polinomio &, polinomio &);
polinomio operator*(polinomio &, polinomio &);
polinomio derivada(polinomio &);

#endif