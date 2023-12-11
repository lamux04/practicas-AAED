#ifndef PILA_BICOLA
#define PILA_BICOLA
#include <cstddef>
#include <cassert>
#include "bicola.h"

template <typename T>
class PilaBicola
{
public:
    explicit PilaBicola();
    bool vacia() const;  // Devuelve true si n_elem == 0
    size_t tama() const; // Devuelve n_elem
    const T tope() const;
    void pop();
    void push(const T &x);          // Agrega x a la pila
private:
    Bicola<T> elementos;
};

template <typename T>
PilaBicola<T>::PilaBicola()
{
}

template <typename T>
bool PilaBicola<T>::vacia() const
{
    return (elementos.tama() == 0);
}

template <typename T>
size_t PilaBicola<T>::tama() const
{
    return (elementos.tama());
}

template <typename T>
const T PilaBicola<T>::tope() const
{
    assert(!vacia());
    return (elementos.frente());
}

template <typename T>
void PilaBicola<T>::pop()
{
    assert(!vacia());
    elementos.pop_frente();
}

template <typename T>
void PilaBicola<T>::push(const T &x)
{
    elementos.push_frente(x);
}

#endif