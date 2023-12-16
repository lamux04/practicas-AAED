#ifndef LISTA_DINAMICA
#define LISTA_DINAMICA
#include <cassert>
#include <cstddef>

template <typename T>
class Lista
{
    struct nodo;

public:
    typedef nodo *posicion;
    Lista();
    bool vacia() const;
    size_t tama() const;
    void insertar(const T &x, posicion p);
    void eliminar(posicion p);
    T elemento(posicion p) const;
    T &elemento(posicion p);
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    Lista(const Lista &P);
    Lista &operator=(const Lista &P);
    ~Lista();

private:
    struct nodo
    {
        T elem;
        nodo *sig;
    };
    nodo *L;
    size_t n_elem;
    void copiar(const Lista<T> &P);

};

template <typename T>
Lista<T>::Lista()
{
    n_elem = 0;
    L = new nodo;
    L->sig = L;
}

template <typename T>
bool Lista<T>::vacia() const
{
    return (n_elem == 0);
}

template <typename T>
size_t Lista<T>::tama() const
{
    return n_elem;
}

template <typename T>
void Lista<T>::insertar(const T &x, posicion p)
{
    nodo *q = p->sig;
    p->sig = new nodo;
    p->sig->elem = x;
    p->sig->sig = q;
    if (p == L)
        L = p->sig;
    ++n_elem;
}

template <typename T>
void Lista<T>::eliminar(posicion p)
{
    assert(p != fin());
    nodo *q = p->sig;
    if (q == fin())
        L = p;
    p->sig = p->sig->sig;
    delete q;
    --n_elem;
}

template <typename T>
T Lista<T>::elemento(posicion p) const
{
    assert(p != fin());
    return p->sig->elem;
}

template <typename T>
T &Lista<T>::elemento(posicion p)
{
    assert(p != fin());
    return p->sig->elem;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const
{
    assert(p != fin());
    return (p->sig);
}

template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
{
    assert(p != primera());
    posicion q = primera();
    while (q->sig != p)
        q = q->sig;
    return (q);
}

template <typename T>
typename Lista<T>::posicion Lista<T>::primera() const
{
    return L->sig;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::fin() const
{
    return L;
}

template <typename T>
void Lista<T>::copiar(const Lista<T> &P)
{
    if (!P.vacia())
    {
        n_elem = P.n_elem;
        posicion p = P.primera();
        nodo *q = new nodo;
        nodo *inicio = q;
        q->sig = new nodo;
        q = q->sig;
        p = p->sig;
        q->elem = p->elem;
        while (p->sig != P.primera())
        {
            p = p->sig;
            q->sig = new nodo;
            q = q->sig;
            q->elem = p->elem;
        }
        L = q;
        L->sig = inicio;
    } else
    {
        Lista();
    }
}

template <typename T>
Lista<T>::Lista(const Lista &P)
{
    copiar(P);
}

template <typename T>
Lista<T> &Lista<T>::operator=(const Lista &P)
{
    if (this != &P)
    {
        this->~Lista();
        copiar(P);
    }
    return *this;
}

template <typename T>
Lista<T>::~Lista()
{
    posicion p;
    posicion q = primera();
    L->sig = nullptr;
    while (q != nullptr)
    {
        p = q;
        q = q->sig;
        delete p;
    }
    n_elem = 0;
    L = nullptr;
}

#endif