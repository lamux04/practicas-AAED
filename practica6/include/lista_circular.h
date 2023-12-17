#ifndef LISTA_CIRCULAR
#define LISTA_CIRCULAR
#include "lista_dinamica.h"
#include <cstddef>
#include <cassert>

template <typename T>
class ListaCircular
{
public:
    typedef typename Lista<T>::posicion posicion;
    // ListaCircular();
    bool vacia() const;
    size_t tama() const;
    void insertar(const T &x, posicion p);
    void eliminar(posicion p);
    const T &elemento(posicion p) const;
    T &elemento(posicion p);
    posicion inipos() const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;

private:
    Lista<T> elementos;
};

template <typename T>
bool ListaCircular<T>::vacia() const
{
    return elementos.vacia();
}

template <typename T>
size_t ListaCircular<T>::tama() const
{
    return elementos.tama();
}

template <typename T>
void ListaCircular<T>::insertar(const T& x, posicion p)
{
    if (vacia())
        elementos.insertar(x, elementos.primera());
    else
        elementos.insertar(x, p);
}

template <typename T>
void ListaCircular<T>::eliminar(posicion p)
{
    elementos.eliminar(p);
}

template <typename T>
const T& ListaCircular<T>::elemento(posicion p) const
{
    return elementos.elemento(p);
}

template <typename T>
T& ListaCircular<T>::elemento(posicion p)
{
    return elementos.elemento(p);
}

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::inipos() const
{
    if (!vacia())
        return elementos.primera();
    return elementos.fin();
}

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::siguiente(posicion p) const
{
    if (elementos.siguiente(p) == elementos.fin())
        return elementos.primera();
    return elementos.siguiente(p);
}

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::anterior(posicion p) const
{
    if (p == elementos.primera())
        return elementos.anterior(elementos.fin());
    return elementos.anterior(p);
}

#endif