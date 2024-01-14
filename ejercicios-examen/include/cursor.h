#ifndef CURSOR
#define CURSOR

class Cursor
{
public:
    void avanzar();
    void borrar_cursor();
    void retrasar();
    void borrar_anterior();
    void ir_al_final();
    void insertar_cursor(char c);
    void ir_al_principio();
    void sobreescribir(char c);

private:
    PilaDinamica<char> izquierda;
    PilaDinamica<char> derecha;
};

#endif