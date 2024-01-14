#ifndef PILA_DINAMICA
#define PILA_DINAMICA
#include <cstddef>
#include <cassert>

template <typename T>
class PilaDinamica
{
public:
    explicit PilaDinamica();
    bool vacia() const;  // Devuelve true si n_elem == 0
    size_t tama() const; // Devuelve n_elem
    const T &tope() const;
    void pop();
    void push(const T &x);                          // Agrega x a la PilaDinamica
    PilaDinamica(const PilaDinamica &P);            // Constructor de copia
    PilaDinamica &operator=(const PilaDinamica &P); // Asignacion entre PilaDinamicas
    ~PilaDinamica();                                // Destructor
private:
    struct nodo
    {
        T elem;
        nodo *sig;
    };

    nodo *tope_;
    size_t n_elem;

    void copiar(const PilaDinamica &P); // Copia P a la PilaDinamica implicita
};

template <typename T>
PilaDinamica<T>::PilaDinamica()
{
    n_elem = 0;
    tope_ = nullptr;
}

template <typename T>
bool PilaDinamica<T>::vacia() const
{
    return (n_elem == 0);
}

template <typename T>
size_t PilaDinamica<T>::tama() const
{
    return (n_elem);
}

template <typename T>
const T &PilaDinamica<T>::tope() const
{
    assert(n_elem > 0);
    return (tope_->elem);
}

template <typename T>
void PilaDinamica<T>::pop()
{
    assert(n_elem > 0);
    nodo *p = tope_;
    tope_ = p->sig;
    delete p;
    n_elem--;
}

template <typename T>
void PilaDinamica<T>::push(const T &x)
{
    nodo *p;
    p = tope_;
    tope_ = new nodo;
    tope_->elem = x;
    tope_->sig = p;
    n_elem++;
}

template <typename T>
void PilaDinamica<T>::copiar(const PilaDinamica &P)
{
    if (!P.vacia())
    {
        nodo *p = P.tope_;
        nodo *q = new nodo;
        tope_ = q;
        n_elem = 1;
        q->elem = p->elem;
        q->sig = nullptr;
        p = p->sig;
        while (p != nullptr)
        {
            n_elem++;
            q->sig = new nodo;
            q = q->sig;
            q->elem = p->elem;
            q->sig = nullptr;
            p = p->sig;
        }
    }
}

template <typename T>
PilaDinamica<T>::PilaDinamica(const PilaDinamica &P)
{
    copiar(P);
}

template <typename T>
PilaDinamica<T> &PilaDinamica<T>::operator=(const PilaDinamica &P)
{
    if (this != &P)
    {
        this->~PilaDinamica();
        copiar(P);
    }

    return *this;
}

template <typename T>
PilaDinamica<T>::~PilaDinamica()
{
    nodo *p;
    while (tope_ != nullptr)
    {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
    n_elem = 0;
}

#endif