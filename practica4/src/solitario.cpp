#include "pila-dinamica.h"
#include "solitario.h"

bool jugar_solitario(tCarta baraja[], tBase& base) {
    bool victoria = true, terminado = false;
    int i;
    tMazo mazo;
    tMonton monton;

    // Introducimos las cartas en la baraja
    for (i = 0; i < 40; i++)
        mazo.push(baraja[i]);

    while (!terminado && monton.tama() + mazo.tama() > 0)
    {
        terminado = true;

        // Pasamos las cartas del monton al mazo
        while (!monton.vacia()) 
        {
            mazo.push(monton.tope());
            monton.pop();
        }

        // Vamos cogiendo cartas
        while (!mazo.vacia())
        {
            // Cogemos dos cartas
            monton.push(mazo.tope());
            mazo.pop();
            if (!mazo.vacia())
            {
                monton.push(mazo.tope());
                mazo.pop();
            }

            // Colocamos la carta en la base
            while(!monton.vacia() && monton.tope().num == base[monton.tope().palo] + 1)
            {
                base[monton.tope().palo]++;
                monton.pop();
                terminado = false;
            }
        }
    }

    if (terminado)
        victoria = false;

    return victoria;
}