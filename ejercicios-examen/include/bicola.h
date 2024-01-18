#ifndef BICOLA
#define BICOLA
#include <stddef.h>
#include <cassert>

template <typename T>
class Bicola
{
public:
    Bicola();                       // Constructor
    bool vacia() const;             // Post: Devuelve si la bicola esta o no vacia
    size_t tama() const;            // Post: Devuelve el numero de elementos que tiene la bicola
    const T& ver_inicio() const;    // Pre: La bicola no debe estar vacia. Post: Devuelve el elemento en el inicio
    const T& ver_fin() const;       // Pre: La bicola no debe estar vacia. Post: Devuelve el elemento en el fin
    void push_inicio(const T &x);   // Post: Agrega el elemento x al inicio de la bicola
    void push_fin(const T &x);      // Post: Agrega el elemento x al final de la bicola
    void pop_inicio();              // Pre: La bicola no debe estar vacia. Post: Elimina el elemento en el fin
    void pop_fin();                 // Pre: La bicola no debe estar vacia. Post: Elimina el elemento en el fin
    Bicola(const Bicola &P);
    Bicola &operator=(const Bicola &P);
    ~Bicola();

private:
    struct nodo
    {
        T elem;
        nodo *sig;
        nodo(const T& x = T(), nodo *s = nullptr) : elem(x), sig(s) {}
    };
    nodo *L;
    size_t n;
    void copiar(const Bicola &P);
};

template <typename T>
Bicola<T>::Bicola() : L(nullptr), n(0) {}

template <typename T>
bool Bicola<T>::vacia() const
{
    return n == 0;
}

template <typename T>
size_t Bicola<T>::tama() const
{
    return n;
}

template <typename T>
const T& Bicola<T>::ver_inicio() const
{
    assert(!vacia());
    return L->sig->elem;
}

template <typename T>
const T& Bicola<T>::ver_fin() const
{
    assert(!vacia());
    return L->elem;
}

template <typename T>
void Bicola<T>::push_inicio(const T& x) 
{
    if (!vacia())
        L->sig = new nodo(x, L->sig);
    else
    {
        L = new nodo(x);
        L->sig = L;
    }
    ++n;
}

template <typename T>
void Bicola<T>::push_fin(const T& x)
{
    if (!vacia())
    {
        L->sig = new nodo(x, L->sig);
        L = L->sig;
    }
    else
    {
        L = new nodo(x);
        L->sig = L;
    }
    ++n;
}

template <typename T>
void Bicola<T>::pop_inicio()
{
    assert(!vacia());
    nodo *q = L->sig;
    L->sig = L->sig->sig;
    delete q;
    --n;
    if (vacia())
        L = nullptr;
}

template <typename T>
void Bicola<T>::pop_fin()
{
    assert(!vacia());
    nodo *p = L;
    while (L->sig != p)
        L = L->sig;
    L->sig = L->sig->sig;
    delete p;
    --n;
    if (vacia())
        L = nullptr;
}

template <typename T>
void Bicola<T>::copiar(const Bicola &P)
{
    if (!P.vacia())
    {
        nodo *p = P.L;
        nodo *q;
        q = new nodo(p->elem);
        L = q;
        p = p->sig;
        while (p != P.L)
        {
            q->sig = new nodo(p->elem);
            p = p->sig;
            q = q->sig;
        }
        q->sig = L;
        n = P.n;
    }
}

template <typename T>
Bicola<T>::Bicola(const Bicola &P)
{
    copiar(P);
}

template <typename T>
Bicola<T> &Bicola<T>::operator=(const Bicola &P)
{
    if (this != &P)
    {
        this->~Bicola();
        copiar(P);
    }
    return *this;
}

template <typename T>
Bicola<T>::~Bicola()
{
    nodo *p;
    while (n != 0)
    {
        p = L;
        L = L->sig;
        delete p;
        --n;
    }
    L = nullptr;
}

#endif