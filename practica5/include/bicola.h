#ifndef BICOLA
#define BICOLA
#include <cassert>
#include <cstddef>

template <typename T> class Bicola {
    public:
        Bicola();
        bool vacia() const;
        T frente() const;
        T final() const;
        size_t tama() const;
        void push_frente(const T &x);
        void push_final(const T &x);
        void pop_frente();
        void pop_final();
        Bicola(const Bicola& P);
        Bicola &operator=(const Bicola &P);
        ~Bicola();

    private:
        struct nodo {
            T elem;
            nodo *sig;
        };
        nodo *inicio;
        nodo *fin;
        size_t n_elem;
        void copiar(const Bicola &P);
};

template <typename T>
Bicola<T>::Bicola() {
    inicio = nullptr;
    fin = nullptr;
    n_elem = 0;
}

template <typename T>
bool Bicola<T>::vacia() const {
    return (n_elem == 0);
}

template <typename T>
T Bicola<T>::frente() const {
    assert(!vacia());
    return (inicio->elem);
}

template <typename T>
size_t Bicola<T>::tama() const {
    return (n_elem);
}

template <typename T>
void Bicola<T>::push_final(const T& x) {
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
void Bicola<T>::push_frente(const T& x) {
    nodo *p = inicio;
    inicio = new nodo;
    inicio->elem = x;
    inicio->sig = p;
    n_elem++;
}

template <typename T>
void Bicola<T>::pop_frente() {
    assert(!vacia());
    nodo *p = inicio;
    inicio = inicio->sig;
    delete p;
    n_elem--;
}

template <typename T>
void Bicola<T>::pop_final() {
    assert(!vacia());
    nodo *p = inicio;
    while (p->sig != fin)
        p = p->sig;
    delete fin;
    p->sig = nullptr;
    fin = p;
    n_elem--;
}

template <typename T>
Bicola<T>::Bicola(const Bicola& P) {
    copiar(P);
}

template <typename T>
 Bicola<T>& Bicola<T>::operator=(const Bicola& P) {
    if (this != &P)
    {
        this->~Bicola();
        copiar(P);
    }
    return *this;
}

template <typename T>
Bicola<T>::~Bicola() {
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
void Bicola<T>::copiar(const Bicola& P) {
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