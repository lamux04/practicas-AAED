#include <iostream>
#include "pilas-oper.h"
#include "linea-texto.h"

void prueba_ejercicio1()
{
    using namespace std;
    char a[] = "Hola&aloH";
    char b[] = "";
    char c[] = "HolaloH";
    cout << a << " -> " << Y_inverso_X(a) << endl;
    cout << b << " -> " << Y_inverso_X(b) << endl;
    cout << c << " -> " << Y_inverso_X(c) << endl;
}

void prueba_lineas_texto()
{
    Linea_texto A;
    A.insertar_caracter_cursor('d');
    A.insertar_caracter_cursor('e');
    A.retrasar();
    A.insertar_caracter_cursor('i');
}

int main()
{
    using namespace std;
    prueba_lineas_texto();
    return 0;
}