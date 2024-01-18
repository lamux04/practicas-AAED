#ifndef LISTA_CIRCULAR
#define LISTA_CIRCULAR
#include <cassert>
#include <stddef.h>

template <typename T>
class ListaCircular
{
private:
    struct nodo;

public:
    typedef nodo *posicion;
    const posicion POS_NULA = nullptr;
    ListaCircular();
    bool vacia() const;
    size_t tama() const;
    void insertar(const T &x, posicion p);
    void eliminar(posicion p);
    const T &elemento(posicion p) const;
    T &elemento(posicion p);
    posicion inipos() const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    ListaCircular(const ListaCircular &P);
    ListaCircular &operator=(const ListaCircular &P);
    ~ListaCircular();

private:
    struct nodo
    {
        T elem;
        nodo *sig;
        nodo *ant;
        nodo(const T &el = T(), nodo *siguiente = nullptr, nodo *anterior = nullptr) : elem(el), sig(siguiente), ant(anterior) {}
    };
    nodo *L;
    size_t n;
    void copiar(const ListaCircular &P);
};

template <typename T>
ListaCircular<T>::ListaCircular() : n(0), L(POS_NULA) {}

template <typename T>
bool ListaCircular<T>::vacia() const
{
    return (n == 0);
}

template <typename T>
size_t ListaCircular<T>::tama() const
{
    return n;
}

template <typename T>
void ListaCircular<T>::insertar(const T &x, posicion p)
{
    if (vacia())
    {
        L = new nodo(x);
        L->sig = L;
        L->ant = L;
    }
    else
    {
        p->sig = new nodo(x, p->sig, p);
    }
    ++n;
}

template <typename T>
void ListaCircular<T>::eliminar(posicion p)
{
    assert(!vacia());
    nodo *q = p->sig;
    if (n == 1 && p == L)
    {
        delete L;
        L = POS_NULA;
    }
    else
    {
        p->sig = p->sig->sig;
        p->sig->ant = p;
        if (q == L)
        {
            L = p;
        }
        delete q;
    }
    --n;
}

template <typename T>
const T &ListaCircular<T>::elemento(posicion p) const
{
    assert(!vacia());
    return p->sig->elem;
}

template <typename T>
T &ListaCircular<T>::elemento(posicion p)
{
    assert(!vacia());
    return p->sig->elem;
}

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::inipos() const
{
    return L;
}

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::siguiente(posicion p) const
{
    return p->sig;
}

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::anterior(posicion p) const
{
    return p->ant;
}

template <typename T>
void ListaCircular<T>::copiar(const ListaCircular &P)
{
    nodo *p = P.L;
    nodo *q;
    L = new nodo(p->elem);
    q = L;
    for (p = p->sig; p != P.L; p = p->sig)
    {
        q->sig = new nodo(p->elem, nullptr, q);
        q = q->sig;
    }
    q->sig = L;
    L->ant = q;
    n = P.n;
}

template <typename T>
ListaCircular<T>::ListaCircular(const ListaCircular &P)
{
    copiar(P);
}

template <typename T>
ListaCircular<T> &ListaCircular<T>::operator=(const ListaCircular &P)
{
    if (this != &P)
    {
        this->~ListaCircular();
        copiar(P);
    }
    return *this;
}

template <typename T>
ListaCircular<T>::~ListaCircular()
{
    nodo *q;
    while (n != 0)
    {
        q = L;
        if (n != 1)
            L = L->sig;
        delete q;
        --n;
    }
    L = POS_NULA;
    n = 0;
}

#endif