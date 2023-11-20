#ifndef PILA_DINAMICA
#define PILA_DINAMICA
#include <cstddef>

template <typename T> class Pila {
  public:
    Pila();
    bool vacia() const;         // Devuelve true si n_elem == 0
    size_t tama() const;        // Devuelve n_elem
    const T &tope() const;
    void pop();
    void push(const T& x);            // Agrega x a la pila
    Pila(const Pila& P);              // Constructor de copia
    Pila &operator=(const Pila& P);   // Asignacion entre pilas
    ~Pila();                          // Destructor
  private:
    struct nodo {
      T elem;
      nodo *sig;
    }

    nodo *tope;
    size_t n_elem;

    void copiar(const Pila& P);       // Copia P a la pila implicita
};

template <typename T>
Pila<T>::Pila() {
  n_elem = 0;
  tope = nullptr;
}

template <typename T>
bool Pila<T>::vacia() const {
  return (n_elem == 0);
}

template <typename T>
size_t Pila<T>::tama() const {
  return (n_elem);
}

template <typename T>
const T& Pila<T>::tope() const {
  assert(n_elem > 0);
  return (tope->sig.elem);
}

template <typename T>
void Pila<T>::pop() {
  assert(n_elem > 0);
  nodo *p = tope->sig;
  delete tope;
  tope = p;
  n_elem--;
}

template <typename T>
void Pila<T>::push(const T& x) {
  nodo *p = tope;
  tope = new nodo;
  tope->elem = x;
  tope->sig = p;
  n_elem++;
}

template <typename T>
void Pila<T>::copiar(const Pila& P) 
{
  nodo *p = P.tope;
  nodo *q = nullptr;
  n_elem = P.n_elem;
  tope = q;
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
Pila<T>::Pila(const Pila& P) 
{
  copiar(P);
}

template <typename T>
Pila<T>& Pila<T>::operator=(const Pila& P) 
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
  while(tope != nullptr) {
    p = tope->sig;
    delete tope;
    tope = p;
  }
  n_elem = 0;
}

#endif