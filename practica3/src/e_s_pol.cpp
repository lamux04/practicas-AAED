#include <iostream>
#include "polinom.h"
#include "e_s_pol.h"

void entrada(polinomio &a)
{
    using namespace std;
    int grado_a, i, coeficiente;

    do
    {
        cout << "Indique el grado del polinomio (max = 20): ";
        cin >> grado_a;
        if (grado_a > 20)
            cout << endl;
    } while (grado_a > 20);

    for (i = 0; i <= grado_a; i++)
    {
        cout << "Introduzca el coeficiente del monomio x^" << i << ": ";
        cin >> coeficiente;
        cout << endl;
        a.coeficiente(i, coeficiente);
    }
}

void salida(polinomio &a)
{
    using namespace std;
    int grado_a = a.grado();
    int i;

    cout << "El polinomio es el siguiente: ";
    for (i = 0; i <= grado_a; i++)
    {
        cout << a.coeficiente(i) << "x^" << i;
        if (i != grado_a)
            cout << " + ";
    }
}