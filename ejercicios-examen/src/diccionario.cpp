#include <string>
#include <cassert>
#include <iostream>
#include "lista_simplemente_enlazada.h"
#include "diccionario.h"

void Diccionario::insertar_traduccion(std::string pal_ingles, std::string pal_es)
{
    traduccion aux;
    ListaSimple<traduccion>::posicion pos_ingles = buscar_ingles(pal_ingles);
    if (pos_ingles != lista.fin())
    {
        aux = lista.elemento(pos_ingles);
        aux.lespanol.insertar(pal_es, aux.lespanol.fin());
        lista.eliminar(pos_ingles);
        lista.insertar(aux, pos_ingles);
    }
    else
    {
        aux.ingles = pal_ingles;
        aux.lespanol.insertar(pal_es, aux.lespanol.fin());
        lista.insertar(aux, lista.fin());
    }
}

void Diccionario::eliminar_traduccion(std::string pal_ingles, std::string pal_es)
{
    traduccion aux;
    ListaSimple<std::string>::posicion pos_es;
    ListaSimple<traduccion>::posicion pos_ingles = buscar_ingles(pal_ingles);

    if (pos_ingles != lista.fin())
    {
        aux = lista.elemento(pos_ingles);
        pos_es = buscar_es(aux, pal_es);
        if (pos_es != aux.lespanol.fin())
        {
            aux.lespanol.eliminar(pos_es);
            lista.eliminar(pos_ingles);
            lista.insertar(aux, pos_ingles);
            if (aux.lespanol.vacia())
                lista.eliminar(pos_ingles);
        }
    }
}

bool Diccionario::consultar_traduccion(std::string pal_ingles, std::string pal_es) const
{
    ListaSimple<traduccion>::posicion pos_ingles = buscar_ingles(pal_ingles);
    assert(pos_ingles != lista.fin());
    traduccion aux = lista.elemento(pos_ingles);
    ListaSimple<std::string>::posicion pos_es = buscar_es(aux, pal_es);
    return pos_es != aux.lespanol.fin();
}

ListaSimple<std::string> Diccionario::consultar_todos(std::string pal_ingles) const
{
    ListaSimple<traduccion>::posicion pos_ingles = buscar_ingles(pal_ingles);
    assert(pos_ingles != lista.fin());
    return lista.elemento(pos_ingles).lespanol;
}

ListaSimple<Diccionario::traduccion>::posicion Diccionario::buscar_ingles(std::string pal_ingles) const
{
    ListaSimple<traduccion>::posicion pos = lista.primera();
    while (pos != lista.fin() && lista.elemento(pos).ingles != pal_ingles)
        pos = lista.siguiente(pos);
    return pos;
}

ListaSimple<std::string>::posicion Diccionario::buscar_es(const traduccion &trad, std::string pal_es) const
{
    ListaSimple<std::string>::posicion pos = trad.lespanol.primera();
    while (pos != trad.lespanol.fin() && trad.lespanol.elemento(pos) != pal_es)
        pos = trad.lespanol.siguiente(pos);
    return pos;
}

void Diccionario::imprimir()
{
    using namespace std;
    cout << "DICCIONARIO: " << endl;
    for (ListaSimple<traduccion>::posicion pos = lista.primera(); pos != lista.fin(); pos = lista.siguiente(pos))
    {
        traduccion aux = lista.elemento(pos);
        cout << aux.ingles << endl;
        for (ListaSimple<string>::posicion pos2 = aux.lespanol.primera(); pos2 != aux.lespanol.fin(); pos2 = aux.lespanol.siguiente(pos2))
            cout << "   " << aux.lespanol.elemento(pos2) << endl;
    }
    cout << endl;
}

void prueba_diccionario()
{
    Diccionario A;
    A.insertar_traduccion("hello", "hola");
    A.insertar_traduccion("hello", "saludos");
    A.insertar_traduccion("hello", "hi");
    A.insertar_traduccion("bye", "adios");
    A.insertar_traduccion("car", "coche");
    A.insertar_traduccion("hello", "buenas");
    A.eliminar_traduccion("hello", "hi");
    A.eliminar_traduccion("bye", "adios");
    std::cout << A.consultar_traduccion("hello", "saudos");
    A.imprimir();
}