#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <cstring>

int main()
{
    using namespace std;
    int v[] = {0, 1, 2, 3, 4, 5};
    int w[] = {0, 1, 2, 3, 4, 5};
    int veces, i;
    const int N = 6;

    veces = 0;
    for (i = 0; i < 10000000; i++)
    {
        random_shuffle(v, v + N);
        if (memcmp(v, w, sizeof v) == 0)
            veces++;
    }

    cout << veces;
}