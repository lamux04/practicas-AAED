#include <string>
#include <cassert>
#include <iostream>
#include "lista_simplemente_enlazada.h"
#include "token_bus.h"

TokenBus::TokenBus(std::string primera)
{

    lmaquina.insertar(maquina(primera), lmaquina.fin());
    token = lmaquina.primera();
}

void TokenBus::nuevo_computador(std::string nuevo)
{
    if (lmaquina.tama() < 25)
        lmaquina.insertar(maquina(nuevo), lmaquina.fin());
}

void TokenBus::eliminar_computador()
{
    if (!lmaquina.vacia())
    {
        lmaquina.eliminar(lmaquina.primera());
    }
}

void TokenBus::pasar_token()
{
    assert(!lmaquina.vacia());
    token = lmaquina.siguiente(token);
    if (token == lmaquina.fin())
        token = lmaquina.primera();
}

maquina TokenBus::ver_token()
{
    assert(!lmaquina.vacia());
    return lmaquina.elemento(token);
}

bool TokenBus::enviar_trama(std::string maquinaA, std::string maquinaB, trama tra)
{
    if (lmaquina.elemento(token).id != maquinaA)
        return false;
    // Buscamos la maquinaB desde la maquina A
    ListaSimple<maquina>::posicion pos = token;
    bool resultado = false;
    do
    {
        pos = lmaquina.siguiente(pos);
        if (pos == lmaquina.fin())
            pos = lmaquina.primera();
        if (lmaquina.elemento(pos).id == maquinaB)
        {
            lmaquina.elemento(pos).ultima_trama = tra;
            resultado = true;
        }
    } while (pos != token && !resultado);
    return resultado;
}

void TokenBus::imprimir()
{
    using namespace std;
    ListaSimple<maquina>::posicion pos;
    for (pos = lmaquina.primera(); pos != lmaquina.fin(); pos = lmaquina.siguiente(pos))
    {
        cout << lmaquina.elemento(pos).id;
        if (pos == token)
            cout << "<-";
        if (lmaquina.elemento(pos).ultima_trama != "")
            cout << "   " << lmaquina.elemento(pos).ultima_trama;
        cout << endl;
    }
}

void prueba_token_bus()
{
    TokenBus A("maquina1");
    A.nuevo_computador("maquina2");
    A.nuevo_computador("maquina3");
    A.pasar_token();
    A.pasar_token();
    A.nuevo_computador("maquina4");
    A.eliminar_computador();
    A.pasar_token();
    A.pasar_token();
    A.enviar_trama("maquina2", "maquina4", "Hola mundo");
    A.enviar_trama("maquina3", "maquina4", "Hola mundo");
    A.enviar_trama("maquina2", "maquina5", "Hola mundo");
    A.pasar_token();
    A.enviar_trama("maquina3", "maquina2", "Hey mundo");
    A.enviar_trama("maquina3", "maquina3", "Adios");
    A.imprimir();
}