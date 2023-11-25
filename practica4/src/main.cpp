#include <iostream>
#include <string>
#include "pila-dinamica.h"
#include "in_out_pila.h"
#include "pilas-oper.h"
#include "linea-texto.h"
#include "suma_ficheros.h"

void prueba_pilas()
{
    Pila<char> A;
    leer_pila(A);
    imprimir_pila_tope_derecha(A);
    imprimir_pila_tope_izquierda(A);
}

void prueba_ejercicio1()
{
    using namespace std;
    char a[] = "Hola&aloH";
    char b[] = "";
    char c[] = "HolaloH";
    cout << a << " -> " << Y_inverso_X(a) << endl;
    cout << "Cadena vacia" << " -> " << Y_inverso_X(b) << endl;
    cout << c << " -> " << Y_inverso_X(c) << endl;
}

void prueba_ejercicio2()
{
    using namespace std;
    char a[] = "Hola&aloH#Hola&aloH#Hola&aloH#Hola&aloH";
    char b[] = "Hola&aloH#Hoa&aloH#Hola&aloH#Hola&aloH";
    char c[] = "Hola&aloH";
    char d[] = "";
    cout << a << " -> " << A_sostenido_B(a) << endl;
    cout << b << " -> " << A_sostenido_B(b) << endl;
    cout << c << " -> " << A_sostenido_B(c) << endl;
    cout << "Cadena vacia" << " -> " << A_sostenido_B(d) << endl;
}

void prueba_lineas_texto()
{
    Linea_texto A;
    A.insertar_caracter_cursor('d');
    A.insertar_caracter_cursor('e');
    A.retrasar();
    A.insertar_caracter_cursor('a');
    A.insertar_caracter_cursor('i');
    A.insertar_caracter_cursor('i');
    A.insertar_caracter_cursor('i');
    A.retrasar();
    A.insertar_caracter_cursor('i');
    A.avanzar();
    A.sobreescribir_caracter('o');
    A.sobreescribir_caracter('o');
    A.retrasar();
    A.borrar_caracter_cursor();
    A.linea();
}

void prueba_suma_ficheros()
{
    std::string a = "/home/lamux/practicas-AAED/practica4/src/f.txt";
    suma(a);
}

int main()
{
    using namespace std;
    prueba_suma_ficheros();
    return 0;
}