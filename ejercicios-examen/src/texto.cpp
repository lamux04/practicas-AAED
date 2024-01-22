#include <iostream>
#include <string>
#include "lista_doblmente_enlazada.h"
#include "texto.h"

void introducir_linea(tTexto& texto, std::string linea)
{
    tLinea nueva_linea;
    for (int i = 0; linea[i] != '\0'; ++i)
    {
        nueva_linea.insertar(linea[i], nueva_linea.fin());
    }
    texto.insertar(nueva_linea, texto.fin());
}

void prueba_texto()
{
    using namespace std;
    tTexto texto;
    std::string linea1 = "hola mundo";
    introducir_linea(texto, "Hol@a mundo@");
    introducir_linea(texto, "Adios#");
    introducir_linea(texto, "hey, esta@@@@@@ es la l#inea 3");
    mostrar_texto(texto);
}

void mostrar_texto(tTexto texto)
{
    using namespace std;
    tTexto::posicion posLista;
    tLinea linea;
    tLinea::posicion posCaracter;
    for (posLista = texto.primera(); posLista != texto.fin(); posLista = texto.siguiente(posLista))
    {
        // Obtenemos una linea
        linea = texto.elemento(posLista);
        if (!linea.vacia() && linea.elemento(linea.anterior(linea.fin())) != '#') // Solo recorremos la linea si el ultimo caracter no es # y si no esta vacia.
        {
            for (posCaracter = linea.primera(); posCaracter != linea.fin(); posCaracter = linea.siguiente(posCaracter))
            {
                // Solo debemos imprimir el caracter si no es ni #, ni @
                if (linea.elemento(posCaracter) != '#' && linea.elemento(posCaracter) != '@')
                {
                    // Ademas, el siguiente no puede ser @
                    if (linea.siguiente(posCaracter) == linea.fin()) // Si es el ultimo, imprimimos
                    {
                        cout << linea.elemento(posCaracter);
                    } else if (linea.elemento(linea.siguiente(posCaracter)) != '@') // Si el siguiente no es @, imprimimos
                    {
                        cout << linea.elemento(posCaracter);
                    }
                }
            }
        }
        cout << endl; // Imprimimos el caracter de nueva linea
    }
}