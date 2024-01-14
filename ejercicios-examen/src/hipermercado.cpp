#include <string>
#include <cassert>
#include <iostream>
#include "lista_simplemente_enlazada.h"
#include "hipermercado.h"

Hipermercado::Hipermercado()
{
}

void Hipermercado::abrir_caja(int n, std::string id_cajero)
{
    assert(n <= 50 && n >= 1);
    linea_cajas[n - 1].abierta = true;
    linea_cajas[n - 1].id_cajero = id_cajero;
}

double Hipermercado::cerrar_caja(int n)
{
    assert(n <= 50 && n >= 1);
    double recaudacion = linea_cajas[n - 1].facturacion;
    linea_cajas[n - 1].abierta = false;
    linea_cajas[n - 1].id_cajero = "";
    linea_cajas[n - 1].facturacion = 0;
    return recaudacion;
}

void Hipermercado::cobrar_cliente(int n, double cobro)
{
    assert(n <= 50 && n >= 1 && linea_cajas[n - 1].abierta);
    linea_cajas[n - 1].facturacion += cobro;
}

void Hipermercado::sustituir_cajero(int n, std::string id_cajero)
{
    assert(n <= 50 && n >= 1 && linea_cajas[n - 1].abierta);
    linea_cajas[n - 1].id_cajero = id_cajero;
}

double Hipermercado::cambiar_turno()
{
    double recaudacion = 0;
    for (int i = 0; i < 50; ++i)
    {
        recaudacion += linea_cajas[i].facturacion;
        linea_cajas[i].facturacion = 0;
    }
    return recaudacion;
}

double Hipermercado::cerrar()
{
    double recaudacion = 0;
    for (int i = 0; i < 50; ++i)
    {
        recaudacion += linea_cajas[i].facturacion;
        linea_cajas[i] = tcaja();
    }
    return recaudacion;
}

void prueba_hipermercado()
{
    using namespace std;
    Hipermercado A;
    A.abrir_caja(10, "Javier");
    A.abrir_caja(15, "Lucia");

    A.cobrar_cliente(10, 50);
    A.cobrar_cliente(10, 100);
    A.cobrar_cliente(15, 70);

    cout << A.cerrar();
}