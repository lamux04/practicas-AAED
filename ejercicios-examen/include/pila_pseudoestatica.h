#ifndef PILA_PSEUDOESTATICA
#define PILA_PSEUDOESTATICA
#include <cstddef> // size_t
#include <cassert>

template <typename T>
class PilaVectorial
{
public:
    explicit PilaVectorial(size_t lmax);
    bool vacia() const;  // Devuelve true si n_elem == 0
    size_t tama() const; // Devuelve n_elem
    size_t tamaMax() const;
    const T &tope() const;
    void pop();
    void push(const T &x);                            // Agrega x a la PilaVectorial
    PilaVectorial(const PilaVectorial &P);            // Constructor de copia
    PilaVectorial &operator=(const PilaVectorial &P); // Asignacion entre PilaVectorials
    ~PilaVectorial();                                 // Destructor
private:
    T *elementos;   // Puntero al vector de los elementos de la PilaVectorial
    size_t n_elem;  // Numero de elementos
    size_t tam_max; // Tamano maximo del vector
};

template <typename T>
PilaVectorial<T>::PilaVectorial(size_t lmax)
{
    n_elem = 0;
    tam_max = lmax;
    elementos = new T[lmax];
}

template <typename T>
bool PilaVectorial<T>::vacia() const
{
    return (n_elem == 0);
}

template <typename T>
size_t PilaVectorial<T>::tama() const
{
    return (n_elem);
}

template <typename T>
size_t PilaVectorial<T>::tamaMax() const
{
    return (tam_max);
}

template <typename T>
const T &PilaVectorial<T>::tope() const
{
    assert(n_elem > 0);
    return (elementos[n_elem - 1]);
}

template <typename T>
void PilaVectorial<T>::pop()
{
    n_elem--;
}

template <typename T>
void PilaVectorial<T>::push(const T &x)
{
    elementos[n_elem] = x;
    n_elem++;
}

template <typename T>
PilaVectorial<T>::PilaVectorial(const PilaVectorial &P)
{
    int i;

    elementos = new T[P.tam_max];
    tam_max = P.tam_max;
    n_elem = P.n_elem;

    for (i = 0; i < n_elem; i++)
    {
        elementos[i] = P.elementos[i];
    }
}

template <typename T>
PilaVectorial<T> &PilaVectorial<T>::operator=(const PilaVectorial &P)
{
    size_t i;
    if (this != &P)
    {
        if (tam_max != P.tam_max)
        {
            delete[] elementos;
            elementos = nullptr;
            tam_max = 0;
            elementos = new T[P.tam_max];
            tam_max = P.tam_max;
        }
        n_elem = P.n_elem;

        for (i = 0; i < n_elem; i++)
            elementos[i] = P.elementos[i];
    }

    return *this;
}

template <typename T>
PilaVectorial<T>::~PilaVectorial()
{
    delete[] elementos;
}

#endif