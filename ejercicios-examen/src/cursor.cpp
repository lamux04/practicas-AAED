#include "pila_dinamica.h"
#include "cursor.h"

void Cursor::avanzar()
{
    if (!derecha.vacia())
    {
        izquierda.push(derecha.tope());
        derecha.pop();
    }
}

void Cursor::borrar_cursor()
{
    if (!derecha.vacia())
        derecha.pop();
}

void Cursor::retrasar()
{
    if (!izquierda.vacia())
    {
        derecha.push(izquierda.tope());
        izquierda.pop();
    }
}

void Cursor::borrar_anterior()
{
    if (!izquierda.vacia())
        izquierda.pop();
}

void Cursor::ir_al_final()
{
    while (!derecha.vacia())
    {
        izquierda.push(derecha.tope());
        derecha.pop();
    }
}

void Cursor::insertar_cursor(char c)
{
    derecha.push(c);
}

void Cursor::ir_al_principio()
{
    while (!izquierda.vacia())
    {
        derecha.push(izquierda.tope());
        izquierda.pop();
    }
}

void Cursor::sobreescribir(char c)
{
    if (!derecha.vacia())
        derecha.pop();
    derecha.push(c);
}