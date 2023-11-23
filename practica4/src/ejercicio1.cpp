#include <iostream>
#include <string>
#include "pila-dinamica.h"
#include "ejercicio1.h"

bool Y_inverso_X(std::string cad)
{
    Pila<char> X;
    char caracter = cad[0];
    unsigned int i = 0;
    bool encontrado = false, resultado = true;

    while (caracter != '\0' && resultado)
    {
        if (caracter == '&')
            encontrado = true;
        else
        {
            if (!encontrado)
                X.push(caracter);
            else
            {
                if (X.tope() != cad[i])
                    resultado = false;
                X.pop();
            }
        }
        i++;
        caracter = cad[i];
    }

    if (!X.vacia() || !encontrado)
        resultado = false;
    return resultado;
}