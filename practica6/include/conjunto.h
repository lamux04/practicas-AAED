#ifndef CONJUNTO
#define CONJUNTO
#include <iostream>

template <typename T>
class Conjunto
{
    public:
        Conjunto();
        bool vacio() const;
        void agregar(const T &x);       // pre: ninguna     post: Si el elemento no esta, lo agrega al conjunto
        void quitar(const T &x);        // pre: ninguna     post: Si el elemento esta lo elimina
        void imprimir();

        template <typename U>
        friend Conjunto<U> union_conjuntos(const Conjunto<U> &A, const Conjunto<U> &B);

        template <typename U>
        friend Conjunto<U> interseccion(const Conjunto<U> &A, const Conjunto<U> &B);
        
        template <typename U>
        friend Conjunto<U> diferencia(const Conjunto<U> &A, const Conjunto<U> &B);

        Conjunto(const Conjunto &P);
        Conjunto &operator=(const Conjunto &P);
        ~Conjunto();

    private:
        struct nodo
        {
            T elem;
            nodo *sig;
            nodo(const T& x = T(), nodo *siguiente = nullptr) : elem(x), sig(siguiente) {}
        };
        nodo *L;
        size_t n;

        // pre: El conjunto no puede ser el conjunto vacio
        // post: Devuelve la direccion al nodo anterior al elemento x. Si no esta x, devuelve la direccion del ultimo nodo. Si esta en la primera posicion, devuelve nulo
        nodo *buscar(const T &x) const;

        void copiar(const Conjunto &P);
};

template <typename T>
Conjunto<T>::Conjunto()
{
    L = nullptr;
    n = 0;
}

template <typename T>
bool Conjunto<T>::vacio() const
{
    return L == nullptr;
}

template <typename T>
void Conjunto<T>::agregar(const T& x)
{
    nodo *p;
    if (!vacio())
        p = buscar(x);
    if (vacio() || (p != nullptr && p->sig == nullptr)) // El elemento no se encuentra en el conjunto
    {
        L = new nodo(x, L);
        n++;
    }
}

template <typename T>
void Conjunto<T>::quitar(const T &x)
{
    if (!vacio()) {
        nodo *p = buscar(x);
        nodo *q;
        if (p == nullptr)
        {
            q = L;
            L = L->sig;
            delete q;
            --n;
        }
        else if (p->sig != nullptr)
        {
            q = p->sig;
            p->sig = p->sig->sig;
            delete q;
            --n;
        }
    }
}

template <typename T>
typename Conjunto<T>::nodo* Conjunto<T>::buscar(const T& x) const
{
    nodo *p = L;
    if (!vacio())
    {
        if (p->elem == x)
            return nullptr;
        while (p->sig != nullptr && p->sig->elem != x)
        {
            p = p->sig;
        }
        
        return p;
    }
}

template <typename T>
Conjunto<T> union_conjuntos(const Conjunto<T> &A, const Conjunto<T> &B)
{
    Conjunto<T> C;
    C = A;
    typename Conjunto<T>::nodo *p = B.L;
    while (p != nullptr)
    {
        C.agregar(p->elem);
        p = p->sig;
    }
    return C;
}

template <typename T>
Conjunto<T> interseccion(const Conjunto<T> &A, const Conjunto<T> &B)
{
    Conjunto<T> C;
    if (!A.vacio() && !B.vacio()) {
        typename Conjunto<T>::nodo *p = A.L;
        typename Conjunto<T>::nodo *q;
        while (p != nullptr)
        {
            q = B.buscar(p->elem);
            if (q == nullptr || q->sig != nullptr)
            {
                C.L = new typename Conjunto<T>::nodo(p->elem, C.L);
                C.n++;
            }
            p = p->sig;
        }
    }
    return C;
}

template <typename T>
Conjunto<T> diferencia(const Conjunto<T> &A, const Conjunto<T> &B)
{
    Conjunto<T> C;
    C = A;
    typename Conjunto<T>::nodo *p = B.L;
    while (p != nullptr)
    {
        C.quitar(p->elem);
        p = p->sig;
    }
    return C;
}

template <typename T>
void Conjunto<T>::copiar(const Conjunto& P)
{
    if (!P.vacio())
    {
        nodo *p = P.L;
        nodo *q;
        L = new nodo(p->elem);
        q = L;
        p = p->sig;
        n = 1;
        while (p != nullptr)
        {
            q->sig = new nodo(p->elem);
            ++n;
            p = p->sig;
            q = q->sig;
        }
    } else
    {
        n = 0;
        L = nullptr;
    }
}

template <typename T>
Conjunto<T>::Conjunto(const Conjunto& P)
{
    copiar(P);
}

template <typename T>
Conjunto<T> &Conjunto<T>::operator=(const Conjunto& P)
{
    if (this != &P)
    {
        this->~Conjunto();
        copiar(P);
    }
    return *this;
}

template <typename T>
Conjunto<T>::~Conjunto()
{
    nodo *p;
    while (L != nullptr)
    {
        p = L;
        L = L->sig;
        delete p;
    }
    n = 0;
}

template <typename T>
void Conjunto<T>::imprimir()
{
    using namespace std;
    nodo *p = L;
    cout << "CONJUNTO: ";
    while (p != nullptr)
    {
        cout << p->elem << " ";
        p = p->sig;
    }
    cout << endl;
}

#endif