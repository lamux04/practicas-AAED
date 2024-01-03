#include <string>
#include <iostream>
#include "lista_circular.h"
#include "juego_circular.h"

tJugador jugar_juego(tJugadores& jugadores, posicion pos)
{
    short int i, j;
    int cont = 0;

    tJugadores jugadoresCopia = jugadores;
    i = jugadores.elemento(pos).num;
    std::cout << jugadores.elemento(pos).nombre << std::endl;
    while (jugadores.tama() > 1)
    {
        if (i % 2 == 0)
        {
            if (cont != 0)
                for (j = 0; j < i - 1; ++j)
                    pos = jugadores.siguiente(pos);
            else
            {
                cont++;
                for (j = 0; j < i; ++j)
                    pos = jugadores.siguiente(pos);
            }
        }
        else
        {
            for (j = 0; j < i; ++j)
                pos = jugadores.anterior(pos);
            if (cont == 0)
                ++cont;
        }
        i = jugadores.elemento(pos).num;
        std::cout << jugadores.elemento(pos).nombre << std::endl;
        jugadores.eliminar(pos);
    }

    tJugador gandador = jugadores.elemento(jugadores.inipos());
    jugadores = jugadoresCopia;

    return gandador;
}