#include <iostream>
#include <cstdlib>

int genera_numero(int, int);

int main()
{
    using namespace std;
    int a = 10, b = 15;
    for (int i = 0; i < 100; i++)
        cout
            << genera_numero(a, b) << " ";
    return 0;
}

int genera_numero(int a, int b)
{
    return ((rand() % (b - a + 1)) + a);
}