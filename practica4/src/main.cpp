#include <iostream>
#include "ejercicio1.h"

void prueba_ejercicio1()
{
    using namespace std;
    string a = "Hola&aloH";
    string b = "";
    string c = "HolaloH";
    cout << a << " -> " << Y_inverso_X(a) << endl;
    cout << b << " -> " << Y_inverso_X(b) << endl;
    cout << c << " -> " << Y_inverso_X(c) << endl;
}

int main()
{
    using namespace std;
    prueba_ejercicio1();

    return 0;
}