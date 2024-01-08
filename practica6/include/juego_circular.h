#ifndef JUEGO_CIRCULAR
#define JUEGO_CIRCULAR

typedef struct
{
    std::string nombre;
    short int num;
} tJugador;

typedef ListaCircular<tJugador> tJugadores;
typedef ListaCircular<tJugador>::posicion pos_jugador;

tJugador jugar_juego(tJugadores &jugadores, pos_jugador pos);

#endif