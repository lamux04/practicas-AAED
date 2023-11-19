#include <iostream>
#include <cstdlib>

int genera_numero(int, int);

int main()
{
    using namespace std;
    int i, n;
    float v[6] = {0, 0, 0, 0, 0, 0};

    for (i = 0; i < 10000000.0; i++)
    {
        n = genera_numero(1, 6);
        v[n - 1]++;
    }

    for (i = 0; i < 6; i++)
    {
        v[i] = v[i] / 10000000.0;
        cout << v[i] << " ";
    }

    return 0;
}

int genera_numero(int a, int b)
{
    return ((rand() % (b - a + 1)) + a);
}