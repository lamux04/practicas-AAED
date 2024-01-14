#ifndef HIPERMERCADO
#define HIPERMERCADO

class Hipermercado
{
public:
    Hipermercado();                                      // Crea una línea de 50 cajas cerradas
    void abrir_caja(int n, std::string id_cajero);       // Pre: n entre 1 y 50. Post: Abre la caja n con el cajero determinado
    double cerrar_caja(int n);                           // Pre: n entre 1 y 50. Post: Cierra la caja n, devuelve la facturacion.
    void cobrar_cliente(int n, double cobro);            // Pre: n entre 1 y 50 y la caja abierta. Post: Se añade el cobro a la caja
    void sustituir_cajero(int n, std::string id_cajero); // Pre: ... Post: Cambia el cajero de la caja n por id_cajero.
    double cambiar_turno();                              // Post: Reinicia todas las facturaciones a 0 y devuelve el total.
    double cerrar();                                     // Post: Cerrar todas las cajas y devuelve el total.

private:
    struct tcaja
    {
        std::string id_cajero;
        double facturacion;
        bool abierta;
        tcaja(std::string id = "", double fac = 0, bool ab = false) : id_cajero(id), facturacion(fac), abierta(ab) {}
    };

    tcaja linea_cajas[50];
};

void prueba_hipermercado();

#endif