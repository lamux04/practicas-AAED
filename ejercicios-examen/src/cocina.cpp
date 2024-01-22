#include <cassert>
#include <iostream>
#include "lista_simplemente_enlazada.h"
#include "cocina.h"

void prueba_cocina()
{
    using namespace std;
    Cocina A(50);
    A.nuevo_mueble(tmueble(2, 10));
    A.nuevo_mueble(tmueble(12, 4));
    A.nuevo_mueble(tmueble(20, 4));
    A.nuevo_mueble(tmueble(25, 4));
    A.mover_mueble(3);
    A.eliminar_mueble(1);
    A.imprimir();
}

Cocina::Cocina(double tama) : tam_max(tama) {}

bool Cocina::puede_colocarse(tmueble mueble)
{
    ListaSimple<tmueble>::posicion pos = buscar_hueco(mueble.posicion);
    if (pos == nullptr)
    {   
        if (lmuebles.vacia() && mueble.posicion + mueble.anchura <= tam_max)
            return true;
        else
            return false;
        if (lmuebles.elemento(lmuebles.primera()).posicion >= mueble.posicion + mueble.anchura)
            return true;
        else
            return false;
    }
    if (pos == lmuebles.fin())
        return false;
    if (lmuebles.siguiente(pos) == lmuebles.fin())
    {
        if (lmuebles.elemento(pos).anchura + lmuebles.elemento(pos).posicion <= mueble.posicion && mueble.posicion <= tam_max)
            return true;
        else
            return false;
    }
    if (lmuebles.elemento(lmuebles.siguiente(pos)).posicion >= mueble.posicion + mueble.anchura && lmuebles.elemento(pos).anchura + lmuebles.elemento(pos).posicion <= mueble.posicion)
        return true;
    else
        return false;
}

void Cocina::nuevo_mueble(tmueble mueble)
{
    assert(puede_colocarse(mueble));
    ListaSimple<tmueble>::posicion pos = buscar_hueco(mueble.posicion);
    if (pos == nullptr)
        lmuebles.insertar(mueble, lmuebles.primera());
    else
        lmuebles.insertar(mueble, lmuebles.siguiente(pos));
}

ListaSimple<tmueble>::posicion Cocina::buscar_hueco(double pos)
{
    ListaSimple<tmueble>::posicion pos_mueble = lmuebles.primera();
    if (!lmuebles.vacia())
    {
        if (lmuebles.elemento(lmuebles.primera()).posicion > pos)
            return nullptr;
        while (lmuebles.siguiente(pos_mueble) != lmuebles.fin() && lmuebles.elemento(lmuebles.siguiente(pos_mueble)).posicion <= pos)
            pos_mueble = lmuebles.siguiente(pos_mueble);
        if (pos > tam_max)
            return lmuebles.fin();
    }
    else
    {
        if (pos < tam_max)
            pos_mueble = nullptr;
        else
            pos_mueble = lmuebles.fin();
    }
    return pos_mueble;
}

tmueble Cocina::mueble_iesimo(size_t i)
{
    assert(i > 0 && i <= lmuebles.tama());
    ListaSimple<tmueble>::posicion pos = buscar_iesimo(i);
    return lmuebles.elemento(pos);
}

void Cocina::eliminar_mueble(size_t i)
{
    ListaSimple<tmueble>::posicion pos = buscar_iesimo(i);
    if (pos != lmuebles.fin())
        lmuebles.eliminar(pos);
}

void Cocina::mover_mueble(size_t i)
{
    ListaSimple<tmueble>::posicion pos;
    if (i == 1 && lmuebles.tama() >= 1)
        lmuebles.elemento(lmuebles.primera()).posicion = 0;
    else
    {
        pos = buscar_iesimo(i - 1);
        if (lmuebles.tama() >= i)
            lmuebles.elemento(lmuebles.siguiente(pos)).posicion = lmuebles.elemento(pos).posicion + lmuebles.elemento(pos).anchura;
    }
}

ListaSimple<tmueble>::posicion Cocina::buscar_iesimo(size_t i)
{
    ListaSimple<tmueble>::posicion pos;
    for (pos = lmuebles.primera(); pos != lmuebles.fin() && i > 1; pos = lmuebles.siguiente(pos))
        --i;
    return pos;
}

void Cocina::imprimir()
{
    using namespace std;
    ListaSimple<tmueble>::posicion pos;
    for (pos = lmuebles.primera(); pos != lmuebles.fin(); pos = lmuebles.siguiente(pos))
        cout << "   - " << lmuebles.elemento(pos).posicion << " / " << lmuebles.elemento(pos).anchura + lmuebles.elemento(pos).posicion << endl;
}