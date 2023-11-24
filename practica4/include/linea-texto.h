#ifndef LINEAS_TEXTO
#define LINEAS_TEXTO
#include "pila-dinamica.h"

class Linea_texto
{
public:
    void avanzar();
    void retrasar();
    void ir_al_final();
    void ir_al_principio();
    void borrar_caracter_cursor();
    void borrar_caracter_anterior();
    void insertar_caracter_cursor(char x);
    void sobreescribir_caracter(char x);
    void linea();

  private:
    Pila<char> Izquierda;
    Pila<char> Derecha;
};

#endif