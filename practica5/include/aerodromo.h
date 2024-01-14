#ifndef AERODROMO
#define AERODROMO

typedef std::string avioneta;

class Aerodromo
{
public:
    void estacionar_avioneta(avioneta a); // Devuelve si se ha estacionado correctamente
    void sacar_avioneta(avioneta a);
    avioneta avioneta_espera(); // Devuelve la matricula de la avioneta en espera, si no hay ninguna devuelve ""
    void imprimir();

private:
    ColaVec<avioneta> avionetas(12);
    ColaDinamica<avioneta> espera;
};

#endif