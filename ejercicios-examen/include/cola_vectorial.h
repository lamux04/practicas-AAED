#ifndef COLA_PSEUDOESTATICA
#define COLA_PSEUDOESTATICA

#include <cassert>
#include <cstddef>

template <typename T>
class ColaVec
{
public:
    ColaVec(size_t elem);
    bool vacia() const;
    size_t tama() const;
    size_t tamaMax() const;
    T frente() const;
    void push(const T &x);
    void pop();
    ColaVec(const ColaVec &P);
    ColaVec &operator=(const ColaVec &P);
    ~ColaVec();

private:
    T *elementos;
    int inicio;
    size_t n_elem, n_max;
    void copiar(const ColaVec &P);
};

template <typename T>
ColaVec<T>::ColaVec(size_t elem)
{
    elementos = new T[elem];
    n_elem = 0;
    n_max = elem;
    inicio = 0;
}

template <typename T>
bool ColaVec<T>::vacia() const
{
    return (n_elem == 0);
}

template <typename T>
size_t ColaVec<T>::tama() const
{
    return n_elem;
}

template <typename T>
size_t ColaVec<T>::tamaMax() const
{
    return n_max;
}

template <typename T>
T ColaVec<T>::frente() const
{
    assert(!vacia());
    return elementos[inicio];
}

template <typename T>
void ColaVec<T>::push(const T &x)
{
    assert(n_elem < n_max);
    elementos[(inicio + n_elem) % n_max] = x;
    n_elem++;
}

template <typename T>
void ColaVec<T>::pop()
{
    assert(!vacia());
    n_elem--;
    inicio = (inicio + 1) % n_max;
}

template <typename T>
ColaVec<T>::ColaVec(const ColaVec &P)
{
    copiar(P);
}

template <typename T>
ColaVec<T> &ColaVec<T>::operator=(const ColaVec &P)
{
    if (this != &P)
    {
        this->~ColaVec();
        copiar(P);
    }
    return *this;
}

template <typename T>
ColaVec<T>::~ColaVec()
{
    delete[] elementos;
    n_elem = 0;
    n_max = 0;
    inicio = 0;
}

template <typename T>
void ColaVec<T>::copiar(const ColaVec &P)
{
    size_t i;
    elementos = new T[P.n_max];
    n_elem = 0;
    n_max = P.n_max;
    inicio = 0;
    for (i = 0; i < P.n_elem; i++)
    {
        n_elem++;
        elementos[i] = P.elementos[(P.inicio + i) % n_max];
    }
}

#endif