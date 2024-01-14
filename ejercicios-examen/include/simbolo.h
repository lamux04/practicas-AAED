#ifndef SIMBOLO
#define SIMBOLO
#include "lista_simplemente_enlazada.h"

typedef enum
{
    Arriba,
    Abajo,
    Izquierda,
    Derecha
} trazado;

class Simbolo
{
public:
    void push_trazo(trazado trazo); // post: Agrega un nuevo trazo al final
    void retroceder(unsigned n);    // post: Elimina los últimos n trazos. Si n > trazos.tama() deja el Simbolo vacío.
    friend Simbolo simetriaX(const Simbolo &original);
    friend Simbolo simetriaY(const Simbolo &original);
    friend Simbolo simetriaXY(const Simbolo &original);
    void imprimir();

private:
    ListaSimple<trazado> trazos;
};

void prueba_simbolo();
#endif