#ifndef LISTA_DOBLEMENTE_ENLAZADA
#define LISTA_DOBLEMENTE_ENLAZADA
#include <cstddef>
#include <cassert>

template <typename T>
class Lista
{
    struct nodo;

public:
    typedef nodo *posicion; // La posicion es la dirección del nodo anterior
    Lista();
    bool vacia() const;
    size_t tama() const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion fin() const;
    posicion primera() const;
    const T &elemento(posicion p) const;
    T &elemento(posicion p);
    void insertar(const T &x, posicion p);
    void eliminar(posicion p);
    Lista(const Lista &P);
    Lista &operator=(const Lista &P);
    ~Lista();

private:
    struct nodo
    {
        nodo *sig;
        nodo *ant;
        T elem;
        nodo(const T &x = T(), nodo *siguiente = nullptr, nodo *anterior = nullptr) : elem(x), sig(siguiente), ant(anterior) {}
    };
    posicion L;
    size_t n;
    void copiar(const Lista &P);
};

template <typename T>
Lista<T>::Lista()
{
    L = new nodo;
    L->sig = L;
    L->ant = L;
    n = 0;
}

template <typename T>
bool Lista<T>::vacia() const
{
    return (n == 0);
}

template <typename T>
size_t Lista<T>::tama() const
{
    return n;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::primera() const
{
    return L;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::fin() const
{
    return L->ant;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const
{
    assert(p != fin());
    return p->sig;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
{
    assert(p != primera());
    return p->ant;
}

template <typename T>
const T &Lista<T>::elemento(posicion p) const
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
void Lista<T>::insertar(const T &x, posicion p)
{
    nodo *q = p->sig;
    p->sig = new nodo(x, q, p);
    q->ant = p->sig;
    n++;
}

template <typename T>
void Lista<T>::eliminar(posicion p)
{
    nodo *q = p->sig;
    p->sig = p->sig->sig;
    delete q;
    p->sig->ant = p;
    n--;
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
    nodo *p;
    while (L != L->sig)
    {
        p = L->sig;
        L->sig = p->sig;
        delete p;
    }
    delete L;
}

template <typename T>
void Lista<T>::copiar(const Lista &P)
{
    nodo *p = P.L->sig;
    L = new nodo();
    nodo *q = L;
    while (p != P.L)
    {
        q->sig = new nodo(p->elem, nullptr, q);
        p = p->sig;
        q = q->sig;
    }
    q->sig = L;
    q->sig->ant = q;
    n = P.n;
}

#endif