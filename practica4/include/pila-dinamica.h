#ifndef PILA_DINAMICA
#define PILA_DINAMICA
#include <cstddef>
#include <cassert>

template <typename T>
class Pila
{
public:
  explicit Pila();
  bool vacia() const;  // Devuelve true si n_elem == 0
  size_t tama() const; // Devuelve n_elem
  const T &tope() const;
  void pop();
  void push(const T &x);          // Agrega x a la pila
  Pila(const Pila &P);            // Constructor de copia
  Pila &operator=(const Pila &P); // Asignacion entre pilas
  ~Pila();                        // Destructor
private:
  struct nodo
  {
    T elem;
    nodo *sig;
  };

  nodo *tope_;
  size_t n_elem;

  void copiar(const Pila &P); // Copia P a la pila implicita
};

template <typename T>
Pila<T>::Pila()
{
  n_elem = 0;
  tope_ = nullptr;
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
const T &Pila<T>::tope() const
{
  assert(n_elem > 0);
  return (tope_->elem);
}

template <typename T>
void Pila<T>::pop()
{
  assert(n_elem > 0);
  nodo *p = tope_->sig;
  delete tope_;
  tope_ = p;
  n_elem--;
}

template <typename T>
void Pila<T>::push(const T &x)
{
  nodo *p = tope_;
  tope_ = new nodo;
  tope_->elem = x;
  tope_->sig = p;
  n_elem++;
}

template <typename T>
void Pila<T>::copiar(const Pila &P)
{
  nodo *p = P.tope_;
  nodo *q = nullptr;
  n_elem = P.n_elem;
  tope_ = q;
  while (p != nullptr)
  {
    q = new nodo;
    q->elem = p->elem;
    q->sig = nullptr;
    q = q->sig;
    p = p->sig;
  }
}

template <typename T>
Pila<T>::Pila(const Pila &P)
{
  copiar(P);
}

template <typename T>
Pila<T> &Pila<T>::operator=(const Pila &P)
{
  if (this != &P)
  {
    this->~Pila();
    copiar(P);
  }

  return *this;
}

template <typename T>
Pila<T>::~Pila()
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