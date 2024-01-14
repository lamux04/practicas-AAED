#include <string>
#include <iostream>
#include "cola-dinamica.h"
#include "cola-pseudoestatica.h"
#include "aerodromo.h"

void Aerodromo::estacionar_avioneta(avioneta a)
{
    if (avionetas.tama() < 12)
    {
        avionetas.push(a);
    }
    else
    {
        espera.push(a);
    }
}

void Aerodromo::sacar_avioneta(avioneta a)
{
    avioneta aux;
    if (!avionetas.vacia())
    {
        aux = avionetas.frente();
        if (aux != a)
        {
            avionetas.pop();
            avionetas.push(aux);
            while (avionetas.frente() != aux && avionetas.frente() != a)
            {
                aux = avionetas.frente();
                avionetas.pop();
                avionetas.push(aux);
            }
        }
        if (avionetas.frente() == a)
        {
            avionetas.pop();
            if (!espera.vacia())
            {
                avionetas.push(espera.frente());
                espera.pop();
            }
        }
        else if (!espera.vacia())
        {
            aux = espera.frente();
            if (aux != a)
            {
                espera.pop();
                espera.push(aux);
                while (espera.frente() != aux && espera.frente() != a)
                {
                    aux = espera.frente();
                    espera.pop();
                    espera.push(aux);
                }
            }
            if (espera.frente() == a)
                espera.pop();
        }
    }
}

avioneta Aerodromo::avioneta_espera()
{
    return espera.frente();
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
    if (!espera.vacia())
        cout << "AVIONETAS EN ESPERA: " << endl;
    for (int i = 0; i < espera.tama(); ++i)
    {
        a = espera.frente();
        cout << espera.frente() << endl;
        espera.pop();
        espera.push(a);
    }
}