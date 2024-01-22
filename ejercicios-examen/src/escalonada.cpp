#include <cassert>
#include <iostream>
#include "lista_simplemente_enlazada.h"
#include "escalonada.h"

Escalonada::Escalonada(double x, double y)
{
    escalon aux(x, y);
    lescalonada.insertar(aux, lescalonada.fin());
}

void Escalonada::nuevo_salto(double x, double y)
{
    ListaSimple<escalon>::posicion pos;
    pos = buscar_escalon(x);
    if (pos == lescalonada.fin())
        lescalonada.insertar(escalon(x, y), lescalonada.primera());
    else if (lescalonada.elemento(pos).x == x)
        lescalonada.elemento(pos).x = x;
    else
        lescalonada.insertar(escalon(x, y), lescalonada.siguiente(pos));
}

void Escalonada::eliminar_salto(double x)
{
    ListaSimple<escalon>::posicion pos = buscar_escalon(x);
    assert(pos != lescalonada.fin() && lescalonada.tama() > 1);
    lescalonada.eliminar(pos);
}

double Escalonada::calcular_valor(double x)
{
    ListaSimple<escalon>::posicion pos;
    pos = buscar_escalon(x);
    assert(pos != lescalonada.fin());
    return lescalonada.elemento(pos).y;
}

double Escalonada::minimo()
{
    ListaSimple<escalon>::posicion pos;
    double minimo = lescalonada.elemento(lescalonada.primera()).y;
    for (pos = lescalonada.primera(); pos != lescalonada.fin(); pos = lescalonada.siguiente(pos))
    {
        if (minimo > lescalonada.elemento(pos).y)
            minimo = lescalonada.elemento(pos).y;
    }
    return minimo;
}

double Escalonada::maximo()
{
    ListaSimple<escalon>::posicion pos;
    double maximo = lescalonada.elemento(lescalonada.primera()).y;
    for (pos = lescalonada.primera(); pos != lescalonada.fin(); pos = lescalonada.siguiente(pos))
        if (maximo < lescalonada.elemento(pos).y)
            maximo = lescalonada.elemento(pos).y;
    return maximo;
}

void Escalonada::translacion(double w, double z)
{
    ListaSimple<escalon>::posicion pos;
    for (pos = lescalonada.primera(); pos != lescalonada.fin(); pos = lescalonada.siguiente(pos))
    {
        lescalonada.elemento(pos).x += w;
        lescalonada.elemento(pos).y += z;
    }
}

// post: Devuelve la posicion del elemento de la lista que representa el salto del escalon al que pertenece x. 
//      Si x no esta definida en la funcion, devuelve fin
ListaSimple<Escalonada::escalon>::posicion Escalonada::buscar_escalon(double x)
{
    ListaSimple<escalon>::posicion pos = lescalonada.primera();
    while (lescalonada.siguiente(pos) != lescalonada.fin() && lescalonada.elemento(lescalonada.siguiente(pos)).x <= x)
        pos = lescalonada.siguiente(pos);
    if (lescalonada.elemento(pos).x <= x)
        return pos;
    return lescalonada.fin();
}

void prueba_escalonada()
{
    using namespace std;
    Escalonada A(4, 5);
    A.nuevo_salto(2, 1);
    A.nuevo_salto(17, 15);
    A.nuevo_salto(25, 10);
    A.nuevo_salto(30, 25);
    A.nuevo_salto(40, 35);
    A.nuevo_salto(20, 70);
    A.eliminar_salto(22);

    cout << "MINIMO: " << A.minimo() << endl;
    cout << "MAXIMO: " << A.maximo() << endl;
    cout << A.calcular_valor(20);
}