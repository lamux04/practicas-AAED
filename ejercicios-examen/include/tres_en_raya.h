#ifndef TRES_EN_RAYA
#define TRES_EN_RAYA

enum ficha
{
    X,
    O,
    Libre
};

class Tablero
{
public:
    Tablero();                                             // Crea un tablero vacío
    void colocar_ficha(unsigned id_casilla, ficha fich);   // Pre: id_casilla entre 1 y 9, fich es X o O. Post: Coloca la ficha en la casilla indicada
    void conjunto_casillas(unsigned v_casillas[], int &n); // Post: Almacena en v_casillas el id de las casillas libres y en n el numero de casillas libres
    ficha ficha_casilla(unsigned id_casilla);              // Pre: id_casilla entre 1 y 9. Post: Devuelve la ficha de la casilla
    bool victoria_jugador(ficha fich);                     // Pre: fich es X o O. Post: Devuelve si el jugador ha ganado
    bool empate();                                         // Post: Devuelve si hay o no empate.
    void imprimir();

private:
    ficha m_fichas[3][3];
};

void prueba_tres_en_raya();

#endif