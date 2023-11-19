#include <iostream>
#include <cstdlib>
#include <math.h>

double genera_flotante(double, double);

int main()
{
    using namespace std;
    int i;
    double x, media;

    media = 0;
    for (i = 0; i < 10000000; i++)
    {
        x = genera_flotante(0, 1);
        media += 4 * sqrt(1 - x * x);
    }
    media /= 10000000;

    cout << media;
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