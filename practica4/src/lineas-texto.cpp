#include "pila-dinamica.h"
#include "in_out_pila.h"
#include "linea-texto.h"

void Linea_texto::avanzar()
{
    if (!Derecha.vacia())
    {
        Izquierda.push(Derecha.tope());
        Derecha.pop();
    }
}

void Linea_texto::retrasar()
{
    if (!Izquierda.vacia())
    {
        Derecha.push(Izquierda.tope());
        Izquierda.pop();
    }
}

void Linea_texto::ir_al_final()
{
    while (!Derecha.vacia())
    {
        Izquierda.push(Derecha.tope());
        Derecha.pop();
    }
}

void Linea_texto::ir_al_principio()
{
    while (!Izquierda.vacia())
    {
        Derecha.push(Izquierda.tope());
        Izquierda.pop();
    }
}

void Linea_texto::borrar_caracter_cursor()
{
    if (!Derecha.vacia())
        Derecha.pop();
}

void Linea_texto::borrar_caracter_anterior()
{
    if (!Izquierda.vacia())
        Izquierda.pop();
}

void Linea_texto::insertar_caracter_cursor(char x)
{
    Izquierda.push(x);
}

void Linea_texto::sobreescribir_caracter(char x)
{
    Izquierda.push(x);
    if (!Derecha.vacia())
        Derecha.pop();
}

void Linea_texto::linea()
{
    imprimir_pila_tope_derecha(Izquierda);
    imprimir_pila_tope_izquierda(Derecha);
}