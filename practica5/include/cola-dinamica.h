#ifndef COLA_DINAMICA
#define COLA_DINAMICA
#include <cassert>
#include <cstddef>

template <typename T> class Cola {
    public:
        Cola();
        bool vacia() const;
        T frente() const;
        size_t tama() const;
        void push(const T &x);
        void pop();
        Cola(const Cola& P);
        Cola &operator=(const Cola &P);
        ~Cola();

    private:
        struct nodo {
            T elem;
            nodo *sig;
        };
        nodo *inicio;
        nodo *fin;
        size_t n_elem;
        void copiar(const Cola &P);
};

template <typename T>
Cola<T>::Cola() {
    inicio = nullptr;
    n_elem = 0;
}

template <typename T>
bool Cola<T>::vacia() const {
    return (n_elem == 0);
}

template <typename T>
T Cola<T>::frente() const {
    assert(!vacia());
    return (inicio->elem);
}

template <typename T>
size_t Cola<T>::tama() const {
    return (n_elem);
}

template <typename T>
void Cola<T>::push(const T& x) {
    if (!vacia())
    {
        fin->sig = new nodo;
        fin = fin->sig;
        fin->elem = x;
        fin->sig = nullptr;
    } else 
    {
        inicio = new nodo;
        inicio->elem = x;
        inicio->sig = nullptr;
        fin = inicio;
    }
    n_elem++;
}

template <typename T>
void Cola<T>::pop() {
    assert(!vacia());
    nodo *p = inicio;
    inicio = inicio->sig;
    delete p;
    n_elem--;
}

template <typename T>
Cola<T>::Cola(const Cola& P) {
    copiar(P);
}

template <typename T>
Cola<T>& Cola<T>::operator=(const Cola& P) {
    if (this != &P)
    {
        this->~Cola();
        copiar(P);
    }
    return *this;
}

template <typename T>
Cola<T>::~Cola() {
    nodo *p;
    while (inicio != nullptr)
    {
        p = inicio;
        inicio = inicio->sig;
        delete p;
    }
    fin = nullptr;
    n_elem = 0;
}

template <typename T>
void Cola<T>::copiar(const Cola& P) {
    if (!P.vacia())
    {
        nodo *p = P.inicio;
        nodo *q;
        q = new nodo;
        inicio = q;
        q->elem = p->elem;
        p = p->sig;
        while (p != nullptr)
        {
            q->sig = new nodo;
            q = q->sig;
            q->elem = p->elem;
            p = p->sig;
        }
        fin = q;
        fin->sig = nullptr;
    }
    n_elem = P.n_elem;
}

#endif