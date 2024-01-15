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
        sala aux_sala = lsalas.elemento(pos_sala);
        pos_espect = buscar_espectaculo(aux_sala, espect);
        if (pos_espect == aux_sala.lespectaculos.fin())
        {
            aux_sala.lespectaculos.insertar(espect, aux_sala.lespectaculos.fin());
            lsalas.eliminar(pos_sala);
            lsalas.insertar(aux_sala, pos_sala);
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
    sala aux_sala;
    if (pos_sala != lsalas.fin())
    {
        aux_sala = lsalas.elemento(pos_sala);
        pos_espect = buscar_espectaculo(aux_sala, espect);
        if (pos_espect != aux_sala.lespectaculos.fin())
        {
            aux_sala.lespectaculos.eliminar(pos_espect);
            lsalas.eliminar(pos_sala);
            lsalas.insertar(aux_sala, pos_sala);
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

ListaSimple<espectaculo>::posicion Cartelera::buscar_espectaculo(const sala &sala_aux, espectaculo espect)
{
    ListaSimple<espectaculo>::posicion pos = sala_aux.lespectaculos.primera();
    while (pos != sala_aux.lespectaculos.fin() && sala_aux.lespectaculos.elemento(pos) != espect)
        pos = sala_aux.lespectaculos.siguiente(pos);
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