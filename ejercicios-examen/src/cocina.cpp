#include <cassert>
#include <iostream>
#include "lista_doblmente_enlazada.h"
#include "cocina.h"

void prueba_cocina()
{
    using namespace std;
    Cocina A(50);
    Cocina::tmueble mueble(10, 5);
    A.colocar_mueble(mueble);
    Cocina::tmueble muebleb(10, 20);
    A.colocar_mueble(muebleb);
    Cocina::tmueble mueblec(5, 15);
    A.colocar_mueble(mueblec);
    cout << A.ver_mueble(2).pos << " " << A.ver_mueble(2).anchura;
}

Cocina::Cocina(double len) : longitud(len) {}

bool Cocina::comprobar_mueble(tmueble mueble)
{
    bool colocar = false;
    Lista<tmueble>::posicion pos = obtener_posicion(mueble);

    if (pos != muebles.fin()) // No queremos añadir el mueble al final
    {
        tmueble aux = muebles.elemento(pos);
        colocar = aux.pos >= mueble.anchura + mueble.pos;
    }
    else // Queremos añadir el mueble al final
    {
        colocar = longitud >= mueble.anchura + mueble.pos;
    }

    return colocar;
}

void Cocina::colocar_mueble(tmueble mueble)
{
    Lista<tmueble>::posicion pos = obtener_posicion(mueble);
    assert(comprobar_mueble(mueble));
    muebles.insertar(mueble, pos);
}

Lista<Cocina::tmueble>::posicion Cocina::obtener_posicion(tmueble mueble)
{
    Lista<tmueble>::posicion pos = muebles.primera();
    tmueble aux;
    if (pos != muebles.fin())
        aux = muebles.elemento(pos);

    // Obtenemos el mueble que está justo antes de donde intentariamos colocar el mueble
    while (pos != muebles.fin() && aux.pos < mueble.pos)
    {
        pos = muebles.siguiente(pos);
        if (pos != muebles.fin())
            aux = muebles.elemento(pos);
    }

    return pos;
}

Cocina::tmueble Cocina::ver_mueble(unsigned i)
{
    Lista<tmueble>::posicion pos = buscar(i);
    tmueble mueble;
    if (pos != muebles.fin())
        return muebles.elemento(pos);
    else
        return mueble;
}

void Cocina::eliminar_mueble(unsigned i)
{
    Lista<tmueble>::posicion pos = buscar(i);
    if (pos != muebles.fin())
        muebles.elemento(pos);
}

void Cocina::mover_mueble(unsigned i)
{
    Lista<tmueble>::posicion pos = buscar(i);
    if (pos != muebles.fin())
    {
        if (pos == muebles.primera())
            muebles.elemento(pos).pos = 0;
        else
        {
            tmueble mueble_anterior = muebles.elemento(muebles.anterior(pos));
            muebles.elemento(pos).pos = mueble_anterior.pos + mueble_anterior.anchura;
        }
    }
}

Lista<Cocina::tmueble>::posicion Cocina::buscar(unsigned i)
{
    int j = 1;
    Lista<tmueble>::posicion pos;
    for (pos = muebles.primera(); j < i && pos != muebles.fin(); pos = muebles.siguiente(pos), ++j)
    {
    }
    return pos;
}
