#include <cstring>
#include "cola-dinamica.h"
#include "aerodromo.h"

bool Aerodromo::estacionar_avioneta(avioneta a)
{
    if (avionetas.tama() < 12)
    {
        avionetas.push(a);
        return false;
    }
    else
    {
        espera.push(a);
        return false;
    }
}

void Aerodromo::sacar_avioneta(avioneta a)
{
    if (!avionetas.vacia())
    {

        avioneta primera = avionetas.frente();
        int iteracion = 1;
        bool eliminacion = false;
        while (strcmp(avionetas.frente(), a) != 0 && iteracion <= avionetas.tama())
        {
            avionetas.push(avionetas.frente());
            avionetas.pop();
            iteracion++;
        }

        if (strcmp(avionetas.frente(), a) == 0)
        {
            avionetas.pop();
            eliminacion = true;
        }

        while (iteracion <= avionetas.tama())
        {
            avionetas.push(avionetas.frente());
            avionetas.pop();
            iteracion++;
        }

        if (eliminacion && !espera.vacia())
        {
            avionetas.push(espera.frente());
            espera.pop();
        }
    }
}