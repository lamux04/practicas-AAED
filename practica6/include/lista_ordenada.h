#ifndef LISTA_ORDENADA
#define LISTA_ORDENADA
#include "lista_dinamica.h"
#include <cstddef>
#include <cassert>

template <typename T>
class ListaOrdenada
{
public:
    typedef typename Lista<T>::posicion posicion;
    // ListaOrdenada();
    bool vacia() const;
    size_t tama() const;
    void insertar(T x);
    void eliminar(posicion p);
    T elemento(posicion p) const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;

private:
    Lista<T> elementos;
};

template <typename T>
bool ListaOrdenada<T>::vacia() const
{
    return (elementos.vacia());
}

template <typename T>
size_t ListaOrdenada<T>::tama() const
{
    return (elementos.tama());
}

template <typename T>
void ListaOrdenada<T>::insertar(T x)
{
    posicion p = primera();
    while (p != fin() && elementos.elemento(p) < x)
    {
        p = siguiente(p);
    }
    elementos.insertar(x, p);
}

template <typename T>
void ListaOrdenada<T>::eliminar(posicion p)
{
    assert(p != fin());
    elementos.eliminar(p);
}

template <typename T>
T ListaOrdenada<T>::elemento(posicion p) const
{
    assert(p != fin());
    return elementos.elemento(p);
}

template <typename T>
typename ListaOrdenada<T>::posicion ListaOrdenada<T>::siguiente(posicion p) const
{
    assert(p != fin());
    return elementos.siguiente(p);
}

template <typename T>
typename ListaOrdenada<T>::posicion ListaOrdenada<T>::anterior(posicion p) const
{
    assert(p != primera());
    return elementos.anterior(p);
}

template <typename T>
typename ListaOrdenada<T>::posicion ListaOrdenada<T>::primera() const
{
    return elementos.primera();
}

template <typename T>
typename ListaOrdenada<T>::posicion ListaOrdenada<T>::fin() const
{
    return elementos.fin();
}

#endif