#include <string>
#include <iostream>
#include "lista_simplemente_enlazada.h"
#include "cartelera.h"

void Cartelera::nueva_sala(id_sala id)
{
    ListaSimple<sala>::posicion pos_sala = buscar_sala(id);
    sala aux;
    aux.id = id;
    if (pos_sala == lsalas.fin())
        lsalas.insertar(aux, lsalas.fin());
}

void Cartelera::nuevo_espectaculo(id_sala id, espectaculo espect)
{
    ListaSimple<sala>::posicion pos_sala = buscar_sala(id);
    ListaSimple<espectaculo>::posicion pos_espect;

    // Nos aseguramos que exista la sala
    if (pos_sala != lsalas.fin())
    {
        pos_espect = buscar_espectaculo(pos_sala, espect);
        if (pos_espect == lsalas.elemento(pos_sala).lespectaculos.fin())
        {
            lsalas.elemento(pos_sala).lespectaculos.insertar(espect, lsalas.elemento(pos_sala).lespectaculos.fin());
        }
    }
}

void Cartelera::eliminar_sala(id_sala id)
{
    ListaSimple<sala>::posicion pos_sala = buscar_sala(id);
    if (pos_sala != lsalas.fin())
        lsalas.eliminar(pos_sala);
}

void Cartelera::eliminar_espectaculo(id_sala id, espectaculo espect)
{
    ListaSimple<sala>::posicion pos_sala = buscar_sala(id);
    ListaSimple<espectaculo>::posicion pos_espect;
    if (pos_sala != lsalas.fin())
    {
        pos_espect = buscar_espectaculo(pos_sala, espect);
        if (pos_espect != lsalas.elemento(pos_sala).lespectaculos.fin())
        {
            lsalas.elemento(pos_sala).lespectaculos.eliminar(pos_espect);
        }
    }
}

ListaSimple<Cartelera::sala>::posicion Cartelera::buscar_sala(id_sala id)
{
    ListaSimple<sala>::posicion pos = lsalas.primera();
    while (pos != lsalas.fin() && lsalas.elemento(pos).id != id)
        pos = lsalas.siguiente(pos);
    return pos;
}

ListaSimple<espectaculo>::posicion Cartelera::buscar_espectaculo(ListaSimple<sala>::posicion pos_sala, espectaculo espect)
{
    ListaSimple<espectaculo>::posicion pos = lsalas.elemento(pos_sala).lespectaculos.primera();
    while (pos != lsalas.elemento(pos_sala).lespectaculos.fin() && lsalas.elemento(pos_sala).lespectaculos.elemento(pos) != espect)
        pos = lsalas.elemento(pos_sala).lespectaculos.siguiente(pos);
    return pos;
}

void Cartelera::imprimir()
{
    using namespace std;
    ListaSimple<sala>::posicion pos_sala;
    for (pos_sala = lsalas.primera(); pos_sala != lsalas.fin(); pos_sala = lsalas.siguiente(pos_sala))
    {
        sala aux = lsalas.elemento(pos_sala);
        cout << aux.id << endl;
        ListaSimple<espectaculo>::posicion pos_espect;
        for (pos_espect = aux.lespectaculos.primera(); pos_espect != aux.lespectaculos.fin(); pos_espect = aux.lespectaculos.siguiente(pos_espect))
            cout << "   " << aux.lespectaculos.elemento(pos_espect) << endl;
    }
    cout << endl;
}

void prueba_cartelera()
{
    Cartelera A;
    A.nueva_sala(33);
    A.nuevo_espectaculo(33, "Star Wars");
    A.nuevo_espectaculo(33, "Civil War");
    A.nueva_sala(32);
    A.nueva_sala(32);
    A.nuevo_espectaculo(32, "Civil War");
    A.nuevo_espectaculo(32, "MistBorn");
    A.nueva_sala(31);
    A.eliminar_espectaculo(32, "Civil War");
    A.imprimir();
}