#ifndef COCINA
#define COCINA

struct tmueble
{
    double posicion, anchura;
    tmueble(double distancia = 0, double ancho = 0) : anchura(ancho), posicion(distancia) {}
};
class Cocina
{
public:
    Cocina(double tama);
    bool puede_colocarse(tmueble mueble); // Post: Devuelve si el mueble puede colocarse
    void nuevo_mueble(tmueble mueble);   // Pre: mueble puede colocarse. Post: Coloca el mueble
    tmueble mueble_iesimo(size_t i);        // Post: Devuelve el mueble i-esimo. Si no existe, devuelve un mueble con anchura 0 y pos 0
    void eliminar_mueble(size_t i);      // Post: Si exite, elimina el mueble.
    void mover_mueble(size_t i);         // Post: Elimina el mueble i-esimo.
    void imprimir();

private:
    ListaSimple<tmueble> lmuebles;
    double tam_max;
    ListaSimple<tmueble>::posicion buscar_hueco(double pos); // Devuelve la posicion en la que se colocaria el mueble
    ListaSimple<tmueble>::posicion buscar_iesimo(size_t i);               // Devuelve la posicion del i-esimo mueble o fin si no existe
};

void prueba_cocina();

#endif