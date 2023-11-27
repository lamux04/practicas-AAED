#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include "pila-dinamica.h"
#include "in_out_pila.h"
#include "pilas-oper.h"
#include "linea-texto.h"
#include "suma_ficheros.h"
#include "solitario.h"

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

void prueba_solitario()
{
    using namespace std;
    int i, j, n_intento = 0;
    tCarta baraja[40];
    tBase base;
    bool victoria;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 10; j++)
        {
            baraja[10 * i + j].num = (num_carta) (j + 1);
            baraja[10 * i + j].palo = (num_palo) i;
        }
    srand(time(nullptr));

    do 
    {
        std::random_shuffle(baraja, baraja + 40);
        base[0] = VACIA;
        base[1] = VACIA;
        base[2] = VACIA;
        base[3] = VACIA;
        victoria = jugar_solitario(baraja, base);
        n_intento++;
        cout << "Intento: " << n_intento << endl;
        if (victoria)
            cout << "Has ganado" << endl;
        else
            cout << "Has perdido" << endl;
        cout << "OROS -> " << base[0] << endl;
        cout << "COPAS -> " << base[1] << endl;
        cout << "ESPADAS -> " << base[2] << endl;
        cout << "BASTOS -> " << base[3] << endl;
        cout << endl;
    } while (!victoria);
}

int main()
{
    using namespace std;
    prueba_solitario();
    return 0;
}