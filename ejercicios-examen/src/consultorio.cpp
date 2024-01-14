#include <string>
#include <cassert>
#include <iostream>
#include "cola_dinamica.h"
#include "lista_simplemente_enlazada.h"
#include "consultorio.h"

void Consultorio::alta(std::string cod_med)
{
    medico med(cod_med);
    lista_medicos.insertar(med, lista_medicos.fin());
}

void Consultorio::baja(std::string cod_med)
{
    ListaSimple<medico>::posicion pos = buscar(cod_med);
    if (pos != lista_medicos.fin())
        lista_medicos.eliminar(pos);
}

void Consultorio::paciente_en_espera(std::string cod_med, paciente pac)
{
    ListaSimple<medico>::posicion pos = buscar(cod_med);
    assert(pos != lista_medicos.fin());
    lista_medicos.elemento(pos).espera.push(pac);
}

paciente Consultorio::turno_paciente(std::string cod_med) const
{
    ListaSimple<medico>::posicion pos = buscar(cod_med);
    assert(pos != lista_medicos.fin());
    return lista_medicos.elemento(pos).espera.frente();
}

void Consultorio::atender_paciente(std::string cod_med)
{
    ListaSimple<medico>::posicion pos = buscar(cod_med);
    assert(pos != lista_medicos.fin());
    if (!lista_medicos.elemento(pos).espera.vacia())
        lista_medicos.elemento(pos).espera.pop();
}

bool Consultorio::pacientes_espera(std::string cod_med) const
{
    ListaSimple<medico>::posicion pos = buscar(cod_med);
    assert(pos != lista_medicos.fin());
    return (!lista_medicos.elemento(pos).espera.vacia());
}

ListaSimple<medico>::posicion Consultorio::buscar(std::string cod_med) const
{
    ListaSimple<medico>::posicion pos = lista_medicos.primera();
    medico med;
    while (pos != lista_medicos.fin() && lista_medicos.elemento(pos).cod != cod_med)
    {
        pos = lista_medicos.siguiente(pos);
    }
    return pos;
}

void Consultorio::imprimir()
{
    using namespace std;
    cout << "CONSULTORIO" << endl;
    ColaDinamica<paciente> cola;
    medico med;
    for (ListaSimple<medico>::posicion pos = lista_medicos.primera(); pos != lista_medicos.fin(); pos = lista_medicos.siguiente(pos))
    {
        med = lista_medicos.elemento(pos);
        cout << "Medico: " << med.cod << endl;
        cola = med.espera;
        while (!cola.vacia())
        {
            cout << "   - " << cola.frente() << endl;
            cola.pop();
        }
    }
    cout << endl;
}

void prueba_consultorio()
{
    Consultorio A;
    A.alta("Roberto");
    A.alta("Cabeza");
    A.paciente_en_espera("Roberto", "Lucia");
    A.imprimir();
}