#include <iostream>
#include "polinom2.h"
#include "arit_pol.h"
#include "e_s_pol.h"

int main()
{
    using namespace std;
    const int GRADO_MAX = 20;
    polinomio a(GRADO_MAX), b(GRADO_MAX), c(GRADO_MAX);
    int op;

    entrada(a);
    entrada(b);

    do {
      cout << endl
          << endl
          << "Que operacion desea realizar (1:+ / 2:- / 3:* / 4: derivada): ";
      cin >> op;
    } while (op > 4 || op < 1);

    switch (op)
    {
    case 1:
      c = a + b;
      break;
    case 2:
      c = a - b;
      break;
    case 3:
      c = a * b;
      break;
    case 4:
      c = derivada(a);
      break;
    default:
      break;
    }

    salida(c);

    return 0;
}