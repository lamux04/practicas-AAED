#ifndef SOLITARIO
#define SOLITARIO

enum num_carta
{
    VACIA,
    AS,
    DOS,
    TRES,
    CUATRO,
    CINCO,
    SEIS,
    SIETE,
    SOTA,
    CABALLO,
    REY
};

enum num_palo
{
    OROS,
    COPAS,
    ESPADAS,
    BASTOS
};

typedef struct {
    num_carta num;
    num_palo palo;
} tCarta;

typedef int tBase[4];

typedef Pila<tCarta> tMazo;

typedef Pila<tCarta> tMonton;

// devuelve true o false si hemos ganado o perdido
bool jugar_solitario(tCarta[], tBase &);

#endif