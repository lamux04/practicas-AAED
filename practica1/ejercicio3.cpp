#include <iostream>
#include <cstdlib>

double genera_flotante(double, double);

int main()
{
    using namespace std;
    int i;
    for (i = 0; i < 100; i++)
    {
        cout << genera_flotante(0, 1) << endl;
    }
    return 0;
}

double genera_flotante(double a, double b)
{
    double n;
    n = rand();       // Entero entre 0 y RAND_MAX
    n = n / RAND_MAX; // Flotante entre 0 y 1
    n *= (b - a);     // Flotante entre 0 y b - a + 1
    n += a;
    return n;
}