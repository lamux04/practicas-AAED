#ifndef COCINA
#define COCINA

class Cocina
{
public:
    struct tmueble
    {
        double pos, anchura;
        tmueble(double ancho = 0, double distancia = 0) : anchura(ancho), pos(distancia) {}
    };
    Cocina(double len);
    bool comprobar_mueble(tmueble mueble); // Post: Devuelve si el mueble puede colocarse
    void colocar_mueble(tmueble mueble);   // Pre: mueble puede colocarse. Post: Coloca el mueble
    tmueble ver_mueble(unsigned i);        // Post: Devuelve el mueble i-esimo. Si no existe, devuelve un mueble con anchura 0 y pos 0
    void eliminar_mueble(unsigned i);      // Post: Si exite, elimina el mueble.
    void mover_mueble(unsigned i);         // Post: Elimina el mueble i-esimo.

private:
    Lista<tmueble> muebles;
    double longitud;
    Lista<tmueble>::posicion obtener_posicion(tmueble mueble); // Devuelve la posicion en la que se colocaria el mueble
    Lista<tmueble>::posicion buscar(unsigned i);               // Devuelve la posicion del i-esimo mueble o fin si no existe
};

void prueba_cocina();

#endif