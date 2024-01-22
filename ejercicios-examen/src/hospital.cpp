#include <string>
#include <cassert>
#include <iostream>
#include <stddef.h>
#include "lista_simplemente_enlazada.h"
#include "hospital.h"

Hospital::Hospital(size_t tam_uci, size_t tam_planta) : max_uci(tam_uci), max_planta(tam_planta) {}

ListaSimple<paciente>::posicion buscar_mas_grave(ListaSimple<paciente> &lis)
{
    ListaSimple<paciente>::posicion pos, pos_menor = lis.primera();
    for (pos = lis.primera(); pos != lis.fin(); pos = lis.siguiente(pos))
    {
        if (lis.elemento(pos).gravedad < lis.elemento(pos_menor).gravedad)
            pos_menor = pos;
    }
    return pos_menor;
}

ListaSimple<paciente>::posicion buscar_menos_grave(ListaSimple<paciente> &lis)
{
    ListaSimple<paciente>::posicion pos, pos_mayor = lis.primera();
    for (pos = lis.primera(); pos != lis.fin(); pos = lis.siguiente(pos))
    {
        if (lis.elemento(pos).gravedad > lis.elemento(pos_mayor).gravedad)
            pos_mayor = pos;
    }
    return pos_mayor;
}

ListaSimple<paciente>::posicion buscar_paciente(const ListaSimple<paciente>& lis, std::string cod)
{
    ListaSimple<paciente>::posicion pos = lis.primera();
    while (pos != lis.fin() && lis.elemento(pos).cod != cod)
        pos = lis.siguiente(pos);
    return pos;
}

void Hospital::ingresar_planta(paciente pac)
{
    ListaSimple<paciente>::posicion pos;
    lplanta.insertar(pac, lplanta.fin());
    if (lplanta.tama() == max_planta + 1)
    {
        pos = buscar_menos_grave(lplanta);
        lplanta.eliminar(pos);
    }
}

void Hospital::ingreso(paciente pac)
{
    paciente pac_aux;
    ListaSimple<paciente>::posicion pos_menos_grave;
    assert(pac.gravedad >= 1 && pac.gravedad <= 9);
    if (pac.gravedad < 6)
    {
        if (luci.tama() < max_uci)
            luci.insertar(pac, luci.fin());
        else
        {
            luci.insertar(pac, luci.fin());
            pos_menos_grave = buscar_menos_grave(luci);
            pac_aux = luci.elemento(pos_menos_grave);
            luci.eliminar(pos_menos_grave);
            ingresar_planta(pac_aux);
        }
    }
    else
    {
        ingresar_planta(pac);
    }
}

void Hospital::alta(std::string cod_pac)
{
    ListaSimple<paciente>::posicion pos;
    pos = buscar_paciente(luci, cod_pac);
    if (pos != luci.fin())
    {
        luci.eliminar(pos);
        if (luci.tama() == max_uci - 1)
        {
            pos = buscar_mas_grave(lplanta);
            if (lplanta.elemento(pos).gravedad < 6)
            {
                luci.insertar(lplanta.elemento(pos), luci.fin());
                lplanta.eliminar(pos);
            }
        }
    }
    else
    {
        pos = buscar_paciente(lplanta, cod_pac);
        if (pos != lplanta.fin())
            lplanta.eliminar(pos);
    }
}

void Hospital::muerte(std::string cod_pac)
{
    alta(cod_pac);
}

ListaSimple<paciente> Hospital::pacientes_UCI()
{
    return luci;
}

ListaSimple<paciente> Hospital::pacientes_planta()
{
    return lplanta;
}

ListaSimple<paciente> Hospital::pacientes_gravedad(unsigned short gravedad)
{
    assert(gravedad >= 1 && gravedad <= 9);
    ListaSimple<paciente>::posicion pos;
    ListaSimple<paciente> resultado;
    if (gravedad < 6)
    {
        for (pos = luci.primera(); pos != luci.fin(); pos = luci.siguiente(pos))
            if (luci.elemento(pos).gravedad == gravedad)
                resultado.insertar(luci.elemento(pos), resultado.fin());
    }
    if (luci.tama() == max_uci || gravedad >= 6)
    {
        for (pos = lplanta.primera(); pos != lplanta.fin(); pos = lplanta.siguiente(pos))
            if (lplanta.elemento(pos).gravedad == gravedad)
                resultado.insertar(lplanta.elemento(pos), resultado.fin());
    }
    return resultado;
}

void imprimir_lista(const ListaSimple<paciente>& lis)
{
    using namespace std;
    ListaSimple<paciente>::posicion pos;
    for (pos = lis.primera(); pos != lis.fin(); pos = lis.siguiente(pos))
    {
        cout << "   - " << lis.elemento(pos).cod << " / " << lis.elemento(pos).gravedad << endl;
    }
}

void Hospital::imprimir()
{
    using namespace std;
    cout << "UCI" << endl;
    imprimir_lista(pacientes_UCI());
    cout << "PLANTA" << endl;
    imprimir_lista(pacientes_planta());
}

void prueba_hospital()
{
    using namespace std;
    Hospital A(5, 5);
    A.ingreso(paciente("Javier", 6));
    A.ingreso(paciente("Lucia", 8));
    A.ingreso(paciente("Carlos", 3));
    A.ingreso(paciente("Ana", 5));
    A.ingreso(paciente("Alejandra", 5));
    A.ingreso(paciente("Marina", 1));
    A.ingreso(paciente("Rosana", 3));
    A.ingreso(paciente("Papi", 4));
    A.ingreso(paciente("Daniel", 2));
    A.ingreso(paciente("Mami", 3));
    A.alta("Marina");
    A.alta("Mami");
    A.imprimir();
    cout << "GRAVEDAD 5" << endl;
    imprimir_lista(A.pacientes_gravedad(5));
}