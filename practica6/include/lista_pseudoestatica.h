#ifndef LISTA_PSEUDOESTATICA
#define LISTA_PSEUDOESTATICA
#include <cassert>
#include <cstddef>

template <typename T>
class Lista {
    public:
        typedef size_t posicion;
        Lista(size_t t_max);
        bool vacia() const;
        size_t tama() const;
        size_t tamaMax() const;
        void insertar(const T &x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const;
        T &elemento(posicion p);
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const;
        Lista(const Lista &L);
        Lista &operator=(const Lista &L);
        ~Lista();
    private:
        T *elementos;
        size_t n_elem;
        size_t n_max;
};

template <typename T>
Lista<T>::Lista(size_t t_max) {
    elementos = new T[t_max];
    n_max = t_max;
    n_elem = 0;
}

template <typename T>
bool Lista<T>::vacia() const {
    return (n_elem == 0);
}

template <typename T>
size_t Lista<T>::tama() const {
    return n_elem;
}

template <typename T>
size_t Lista<T>::tamaMax() const {
    return n_max;
}

template <typename T>
void Lista<T>::insertar(const T& x, posicion p) {
    assert(p >= primera() && p <= fin());
    assert(tama() < tamaMax());
    for (posicion q = fin(); q > p; --q)
        elementos[q] = elementos[q - 1];
    elementos[p] = x;
    ++n_elem;
}

template <typename T>
void Lista<T>::eliminar(posicion p) {
    assert(p >= primera() && p < fin());
    for (posicion q = p; q < fin() - 1; ++q)
        elementos[q] = elementos[q + 1];
    --n_elem;
}

template <typename T>
const T& Lista<T>::elemento(posicion p) const {
    assert(p >= primera() && p < fin());
    return elementos[p];
}

template <typename T>
T& Lista<T>::elemento(posicion p) {
    assert(p >= primera() && p < fin());
    return elementos[p];
}

template <typename T>
typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const
{
    assert(p >= primera() && p < fin());
    return (p + 1);
}

template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(posicion p) const {
    assert(p > primera() && p <= fin());
    return (p -1 );
}

template <typename T>
typename Lista<T>::posicion Lista<T>::primera() const {
    return 0;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::fin() const {
    return n_elem;
}

template <typename T>
Lista<T>::Lista(const Lista &L) {
    n_elem = L.n_elem;
    n_max = L.n_max;
    elementos = new T[n_max];

    for (posicion i = primera(); i < fin(); ++i)
        elementos[i] = L.elementos[i];
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista &L)
{
    if (this != &L)
    {
        if (n_max != L.n_max)
        {
            T *p = elementos;
            n_elem = L.n_elem;
            elementos = new T[n_max];
            delete[] p;
        }
        n_elem = L.n_elem;
        for (posicion i = primera(); i < fin(); ++i)
            elementos[i] = L.elementos[i];
    }

    return *this;
}

template <typename T>
Lista<T>::~Lista()
{
    delete[] elementos;
}

#endif