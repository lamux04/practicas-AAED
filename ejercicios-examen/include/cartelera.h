#ifndef CARTELERA
#define CARTELERA

typedef int id_sala;
typedef std::string espectaculo;

class Cartelera
{
public:
    void nueva_sala(id_sala id);                               // Post: Si id no existe en la cartelera, crea un nueva sala con ese id
    void nuevo_espectaculo(id_sala id, espectaculo espect);    // Post: Si id exite y no tiene este espectaculo lo añade a dicho id.
    void eliminar_sala(id_sala id);                            // Post: Elimina la sala si existe.
    void eliminar_espectaculo(id_sala id, espectaculo espect); // Post: Elimina el espectaculo de una sala.
    void imprimir();

private:
    struct sala
    {
        id_sala id;
        ListaSimple<espectaculo> lespectaculos;
    };
    ListaSimple<sala> lsalas;
    ListaSimple<sala>::posicion buscar_sala(id_sala id);
    ListaSimple<espectaculo>::posicion buscar_espectaculo(ListaSimple<sala>::posicion pos_sala, espectaculo espect);
};

void prueba_cartelera();

#endif