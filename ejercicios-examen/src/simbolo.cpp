#include <iostream>
#include "pila_pseudoestatica.h"
#include "lista_simplemente_enlazada.h"
#include "simbolo.h"

void Simbolo::push_trazo(trazado trazo)
{
    trazos.insertar(trazo, trazos.primera());
}

void Simbolo::retroceder(unsigned n)
{
    while (n > 0 && !trazos.vacia())
    {
        trazos.eliminar(trazos.primera());
        n--;
    }
}

Simbolo simetriaX(const Simbolo &original)
{
    Simbolo resultado;
    for (ListaSimple<trazado>::posicion pos = original.trazos.primera(); pos != original.trazos.fin(); pos = original.trazos.siguiente(pos))
    {
        if (original.trazos.elemento(pos) == Derecha)
            resultado.trazos.insertar(Izquierda, resultado.trazos.fin());
        else if (original.trazos.elemento(pos) == Izquierda)
            resultado.trazos.insertar(Derecha, resultado.trazos.fin());
        else
            resultado.trazos.insertar(original.trazos.elemento(pos), resultado.trazos.fin());
    }
    return resultado;
}

Simbolo simetriaY(const Simbolo &original)
{
    Simbolo resultado;
    for (ListaSimple<trazado>::posicion pos = original.trazos.primera(); pos != original.trazos.fin(); pos = original.trazos.siguiente(pos))
    {
        if (original.trazos.elemento(pos) == Arriba)
            resultado.trazos.insertar(Abajo, resultado.trazos.fin());
        else if (original.trazos.elemento(pos) == Abajo)
            resultado.trazos.insertar(Arriba, resultado.trazos.fin());
        else
            resultado.trazos.insertar(original.trazos.elemento(pos), resultado.trazos.fin());
    }
    return resultado;
}

Simbolo simetriaXY(const Simbolo &original)
{
    Simbolo resultado;
    for (ListaSimple<trazado>::posicion pos = original.trazos.primera(); pos != original.trazos.fin(); pos = original.trazos.siguiente(pos))
    {
        switch (original.trazos.elemento(pos))
        {
        case Arriba:
            resultado.trazos.insertar(Abajo, resultado.trazos.fin());
            break;
        case Abajo:
            resultado.trazos.insertar(Arriba, resultado.trazos.fin());
            break;
        case Derecha:
            resultado.trazos.insertar(Izquierda, resultado.trazos.fin());
            break;
        case Izquierda:
            resultado.trazos.insertar(Derecha, resultado.trazos.fin());
            break;
        }
    }
    return resultado;
}

void Simbolo::imprimir()
{
    using namespace std;
    for (ListaSimple<trazado>::posicion pos = trazos.primera(); pos != trazos.fin(); pos = trazos.siguiente(pos))
        switch (trazos.elemento(pos))
        {
        case Arriba:
            cout << "Arriba"
                 << " ";
            break;
        case Izquierda:
            cout << "Izquierda"
                 << " ";
            break;
        case Derecha:
            cout << "Derecha"
                 << " ";
            break;
        case Abajo:
            cout << "Abajo"
                 << " ";
            break;

        default:
            break;
        }
    cout << endl;
}

void prueba_simbolo()
{
    Simbolo A;
    A.push_trazo(Izquierda);
    A.push_trazo(Abajo);
    A.push_trazo(Abajo);
    A.push_trazo(Derecha);
    A.push_trazo(Arriba);
    A.push_trazo(Izquierda);
    A.push_trazo(Izquierda);
    A.retroceder(1);
    A.imprimir();
    Simbolo B = simetriaX(A);
    B.imprimir();
    B = simetriaY(A);
    B.imprimir();
    B = simetriaXY(A);
    B.imprimir();
}