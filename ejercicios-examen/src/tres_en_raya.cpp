#include <cassert>
#include <iostream>
#include "tres_en_raya.h"

Tablero::Tablero()
{
    // Inicializamos todo a libre
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m_fichas[i][j] = Libre;
}

void Tablero::colocar_ficha(unsigned id_casilla, ficha fich)
{
    assert(id_casilla >= 1 && id_casilla <= 9);
    assert(fich == X || fich == O);
    // Colocar ficha en id_casilla
    int i = (id_casilla - 1) / 3;
    int j = (id_casilla - 1) % 3;
    m_fichas[i][j] = fich;
}

void Tablero::conjunto_casillas(unsigned v_libres[], int &n)
{
    n = 0;
    v_libres = new unsigned[9];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            if (m_fichas[i][j] == Libre)
            {
                v_libres[n] = i * 3 + j + 1;
                ++n;
            }
        }
}

ficha Tablero::ficha_casilla(unsigned id_casilla)
{
    assert(id_casilla >= 1 && id_casilla <= 9);
    // Colocar ficha en id_casilla
    int i = (id_casilla - 1) / 3;
    int j = (id_casilla - 1) % 3;
    return m_fichas[i][j];
}

bool Tablero::victoria_jugador(ficha fich)
{
    assert(fich == X || fich == O);
    bool victoria = false;
    // Comprobamos filas y columnas
    int i = 0;
    while (i < 3 && !victoria)
    {
        if (m_fichas[i][0] == fich && m_fichas[i][1] == fich && m_fichas[i][2] == fich)
            victoria = true;
        else if (m_fichas[0][i] == fich && m_fichas[1][i] == fich && m_fichas[2][i] == fich)
            victoria = true;
        ++i;
    }

    // Comprobamos los diagonales
    if (!victoria && m_fichas[0][0] == fich && m_fichas[1][1] == fich && m_fichas[2][2] == fich)
        victoria = true;
    else if (m_fichas[0][2] == fich && m_fichas[1][1] == fich && m_fichas[2][0] == fich)
        victoria = true;
    return victoria;
}

bool Tablero::empate()
{
    bool resultado = true;
    // Comprobamos que todas las fichas enten ocupadas
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (m_fichas[i][j] == Libre)
                resultado = false;
    if (resultado)
        resultado = !victoria_jugador(X);
    if (resultado)
        resultado = !victoria_jugador(O);
    return resultado;
}

void Tablero::imprimir()
{
    using namespace std;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (m_fichas[i][j] == 0)
                cout << "X";
            else if (m_fichas[i][j] == 1)
                cout << "O";
            else
                cout << "_";
        }
        cout << endl;
    }
    cout << "Ganador X: " << victoria_jugador(X) << endl;
    cout << "Ganador O: " << victoria_jugador(O) << endl;
    cout << "Empate: " << empate() << endl;
    cout << endl;
}

void prueba_tres_en_raya()
{
    using namespace std;
    Tablero A;
    A.colocar_ficha(5, X);
    A.colocar_ficha(1, O);
    A.colocar_ficha(2, X);
    A.colocar_ficha(8, O);
    A.colocar_ficha(7, X);
    unsigned v[9];
    int n;
    A.conjunto_casillas(v, n);
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    A.colocar_ficha(9, O);
    A.colocar_ficha(4, X);
    A.colocar_ficha(3, O);
    A.colocar_ficha(6, X);
    A.colocar_ficha(5, O);
    A.colocar_ficha(9, X);

    A.imprimir();
}