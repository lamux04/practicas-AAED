#include <string>
#include <iostream>
#include "cola-dinamica.h"
#include "aerodromo.h"

void Aerodromo::estacionar_avioneta(avioneta a)
{
    if (avionetas.tama() < 12)
    {
        avionetas.push(a);
    }
    else if (espera == "")
    {
        espera = a;
    }
}

void Aerodromo::sacar_avioneta(avioneta a)
{
    if (a == espera)
    {
        espera = "";
    }
    if (!avionetas.vacia())
    {
        int iteracion = 1, n = avionetas.tama();
        bool eliminacion = false;
        for (iteracion = 1; iteracion <= n; ++iteracion)
        {
            if (avionetas.frente() != a)
                avionetas.push(avionetas.frente());
            else
                eliminacion = true;
            avionetas.pop();
        }
        if (eliminacion && espera != "")
        {
            avionetas.push(espera);
            espera = "";
        }
    }
}

avioneta Aerodromo::avioneta_espera()
{
    return espera;
}

void Aerodromo::imprimir()
{
    using namespace std;
    avioneta a;
    cout << "AVIONETAS DEL AERODROMO: " << endl;
    for (int i = 0; i < avionetas.tama(); ++i)
    {
        a = avionetas.frente();
        cout << avionetas.frente() << endl;
        avionetas.pop();
        avionetas.push(a);
    }
    cout << endl
         << "AVIONETA EN ESPERA: " << espera << endl;
}