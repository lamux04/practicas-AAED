#ifndef ESCALONADA
#define ESCALONADA

class Escalonada
{
public:
    Escalonada(double x, double y);
    void nuevo_salto(double x, double y);
    void eliminar_salto(double x);
    double calcular_valor(double x);
    double minimo();
    double maximo();
    void translacion(double w, double z);

private:
    struct escalon
    {
        double x, y;
        escalon(double xi = 0, double yi = 0) : x(xi), y(yi) {}
    };
    ListaSimple<escalon> lescalonada;
    ListaSimple<escalon>::posicion buscar_escalon(double x);
};

void prueba_escalonada();

#endif