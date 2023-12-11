# ESPECIFICACION BICOLA

## Definicion
Una bicola es una cola en la que se pueden hacer inserciones y borrados en ambos extremos.

## Operaciones
```c++
Bicola();
    bool vacia() const;
    T frente() const;                   // Pre: No vacia
    T final() const;                    // Pre: No vacia
    size_t tama() const;
    void push_frente(const T &x);
    void push_final(const T &x);
    void pop_frente();                  // Pre: No vacia
    void pop_final();                   // Pre: No vacia
    Cola(const Cola& P);
    Cola &operator=(const Cola &P);
    ~Cola();
```