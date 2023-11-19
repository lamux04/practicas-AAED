#include <iostream>
#include "polinom.h"
#include "arit_pol.h"
#include "e_s_pol.h"

int main()
{
    using namespace std;
    const int GRADO_MAX = 20;
    polinomio a(GRADO_MAX);

    entrada(a);
    salida(a);
    return 0;
}