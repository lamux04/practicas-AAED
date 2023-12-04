#ifndef COLA_PSEUDOESTATICA
#define COLA_PSEUDOESTATICA

#include <cassert>
#include <cstddef>

template <typename T>
class Cola {
    public:
        Cola(size_t elem);
        bool vacia() const;
        size_t tama() const;
        size_t tamaMax() const;
        T frente() const;
        void push(const T& x);
        void pop();
        Cola(const Cola &P);
        Cola &operator=(const Cola &P);
        ~Cola();
    private:
        T *elementos;
        int inicio;
        size_t n_elem, n_max;
        void copiar(const Cola& P);
};

template <typename T>
Cola<T>::Cola(size_t elem) {
    elementos = new T[elem];
    n_elem = 0;
    n_max = elem;
    inicio = 0;
}

template <typename T>
bool Cola<T>::vacia() const {
    return (n_elem == 0);
}

template <typename T>
size_t Cola<T>::tama() const {
    return n_elem;
}

template <typename T>
size_t Cola<T>::tamaMax() const {
    return n_max;
}

template <typename T>
T Cola<T>::frente() const {
    assert(!vacia());
    return elementos[inicio];
}

template <typename T>
void Cola<T>::push(const T& x) {
    assert(n_elem < n_max);
    elementos[(inicio + n_elem) % n_max] = x;
    n_elem++;
}

template <typename T>
void Cola<T>::pop() {
    assert(!vacia());
    n_elem--;
    inicio = (inicio + 1) % n_max;
}

template <typename T>
Cola<T>::Cola(const Cola& P) {
    copiar(P);
}

template <typename T>
Cola<T>& Cola<T>::operator=(const Cola& P) {
    if (this != &P) {
        this->~Cola();
        copiar(P);
    }
    return *this;
}

template <typename T>
Cola<T>::~Cola() {
    delete[] elementos;
    n_elem = 0;
    n_max = 0;
    inicio = 0;
}

template <typename T>
void Cola<T>::copiar(const Cola& P) {
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