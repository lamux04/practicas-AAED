#include <string>
#include <stddef.h>
#include <cassert>
#include <iostream>
#include "cola_dinamica.h"
#include "cola_vectorial.h"
#include "gestor_impresion.h"

GestorImpresion::GestorImpresion(size_t elem) : turnos(n), n(elem), v_usuarios(new usuario[elem]) {}

void GestorImpresion::nuevo_trabajo(int id, trabajo tra)
{
    assert(id >= 1 && id <= n);
    if (tra.urgente)
        v_usuarios[id - 1].c_urgente.push(tra.cod);
    else
        v_usuarios[id - 1].c_no_urgente.push(tra.cod);
    if (v_usuarios[id - 1].c_no_urgente.tama() + v_usuarios[id - 1].c_urgente.tama() == 1)
        turnos.push(id);
}

void GestorImpresion::eliminar_trabajo()
{
    int i;
    if (!turnos.vacia())
    {
        i = turnos.frente();
        turnos.pop();
        --i;
        if(v_usuarios[i].c_urgente.vacia())
            v_usuarios[i].c_no_urgente.pop();
        else
            v_usuarios[i].c_urgente.pop();
        if (!v_usuarios[i].c_urgente.vacia() || !v_usuarios[i].c_no_urgente.vacia())
            turnos.push(i+1);
    }
}

void GestorImpresion::cancelar_trabajos(int id)
{
    assert(id >= 1 && id <= n);
    int i, j;
    if (!v_usuarios[id-1].c_urgente.vacia() || !v_usuarios[id-1].c_no_urgente.vacia())
    {
        while(!v_usuarios[id-1].c_urgente.vacia())
            v_usuarios[id-1].c_urgente.pop();
        while(!v_usuarios[id-1].c_no_urgente.vacia())
            v_usuarios[id-1].c_no_urgente.pop();
        // Quitamos el turno
        i = turnos.frente();
        if (i != id)
            do
            {
                if (turnos.frente() == id)
                    turnos.pop();
                else
                {
                    j = turnos.frente();
                    turnos.pop();
                    turnos.push(j);
                }
            } while (i != turnos.frente());
        else
            turnos.pop();
    }
}

GestorImpresion::GestorImpresion(const GestorImpresion &P) : turnos(P.turnos)
{
    v_usuarios = new usuario[P.n];
    n = P.n;
    for (int i = 0; i < n; ++i)
        v_usuarios[i] = P.v_usuarios[i];
}

GestorImpresion& GestorImpresion::operator=(const GestorImpresion& P)
{
    int i;
    if (this != &P)
    {
        delete[] v_usuarios;
        v_usuarios = new usuario[P.n];
        n = P.n;
        for (i = 0; i < n; ++i)
            v_usuarios[i] = P.v_usuarios[i];
        turnos = P.turnos;
    }

    return *this;
}

GestorImpresion::~GestorImpresion()
{
    delete[] v_usuarios;
    n = 0;
}

void GestorImpresion::imprimir()
{
    using namespace std;
    int j, k;
    cod_trabajo cod, cod_aux;
    for (int i = 0; i < n; ++i)
    {
        cout << "PACIENTE " << i+1 << endl;
        cout << "NO URGENTES:" << endl;
        if (!v_usuarios[i].c_no_urgente.vacia())
        {
            cod = v_usuarios[i].c_no_urgente.frente();
            do
            {
                cout << v_usuarios[i].c_no_urgente.frente();
                cout << endl;
                cod_aux = v_usuarios[i].c_no_urgente.frente();
                v_usuarios[i].c_no_urgente.pop();
                v_usuarios[i].c_no_urgente.push(cod_aux);
            } while (cod != v_usuarios[i].c_no_urgente.frente());
        }

        cout << "URGENTES:" << endl;
        if (!v_usuarios[i].c_urgente.vacia())
        {
            cod = v_usuarios[i].c_urgente.frente();
            do
            {
                cout << v_usuarios[i].c_urgente.frente();
                cout << endl;
                cod_aux = v_usuarios[i].c_urgente.frente();
                v_usuarios[i].c_urgente.pop();
                v_usuarios[i].c_urgente.push(cod_aux);
            } while (cod != v_usuarios[i].c_urgente.frente());
        }
        cout << endl;
    }

    cout << "TURNOS: ";
    if (!turnos.vacia())
    {
        k = turnos.frente();
        do
        {
            cout << turnos.frente() << " ";
            j = turnos.frente();
            turnos.pop();
            turnos.push(j);
        } while (k != turnos.frente());
    }
}

void prueba_gestor_impresion()
{
    GestorImpresion A(5);
    A.nuevo_trabajo(4, trabajo("Hola mundo", false));
    A.nuevo_trabajo(4, trabajo("Adios mundo", false));
    A.nuevo_trabajo(4, trabajo("Hey", true));
    A.nuevo_trabajo(3, trabajo("Trabajo", false));
    A.nuevo_trabajo(1, trabajo("Trabajazo", false));
    A.cancelar_trabajos(4);

    A.imprimir();
}