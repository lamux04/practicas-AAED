#ifndef COLA_BICOLA
#define COLA_BICOLA
#include <cassert>
#include <cstddef>
#include "bicola.h"

template <typename T>
class ColaBicola
{
public:
    ColaBicola();
    bool vacia() const;
    T frente() const;
    size_t tama() const;
    void push(const T &x);
    void pop();

private:
    Bicola<T> elementos;
};

template <typename T>
ColaBicola<T>::ColaBicola()
{
}

template <typename T>
bool ColaBicola<T>::vacia() const
{
    return (elementos.vacia());
}

template <typename T>
T ColaBicola<T>::frente() const
{
    assert(!vacia());
    return (elementos.frente());
}

template <typename T>
size_t ColaBicola<T>::tama() const
{
    return (elementos.tama());
}

template <typename T>
void ColaBicola<T>::push(const T &x)
{
    elementos.push_final(x);
}

template <typename T>
void ColaBicola<T>::pop()
{
    assert(!vacia());
    elementos.pop_frente();
}

#endif