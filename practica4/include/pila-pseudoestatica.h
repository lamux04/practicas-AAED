#ifndef PILA_PSEUDOESTATICA
#define PILA_PSEUDOESTATICA
#include <cstddef> // size_t
#include <cassert>

template <typename T>
class Pila
{
public:
  explicit Pila(size_t lmax);
  bool vacia() const;  // Devuelve true si n_elem == 0
  size_t tama() const; // Devuelve n_elem
  size_t tamaMax() const;
  const T &tope() const;
  void pop();
  void push(const T &x);          // Agrega x a la pila
  Pila(const Pila &P);            // Constructor de copia
  Pila &operator=(const Pila &P); // Asignacion entre pilas
  ~Pila();                        // Destructor
private:
  T *elementos;   // Puntero al vector de los elementos de la pila
  size_t n_elem;  // Numero de elementos
  size_t tam_max; // Tamano maximo del vector
};

template <typename T>
Pila<T>::Pila(size_t lmax)
{
  n_elem = 0;
  tam_max = lmax;
  elementos = new T[lmax];
}

template <typename T>
bool Pila<T>::vacia() const
{
  return (n_elem == 0);
}

template <typename T>
size_t Pila<T>::tama() const
{
  return (n_elem);
}

template <typename T>
size_t Pila<T>::tamaMax() const
{
  return (tam_max);
}

template <typename T>
const T &Pila<T>::tope() const
{
  assert(n_elem > 0);
  return (elementos[n_elem - 1]);
}

template <typename T>
void Pila<T>::pop()
{
  n_elem--;
}

template <typename T>
void Pila<T>::push(const T &x)
{
  elementos[n_elem] = x;
  n_elem++;
}

template <typename T>
Pila<T>::Pila(const Pila &P)
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
Pila<T> &Pila<T>::operator=(const Pila &P)
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
Pila<T>::~Pila()
{
  delete[] elementos;
}

#endif