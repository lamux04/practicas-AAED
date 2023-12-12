#ifndef AERODROMO
#define AERODROMO

typedef char avioneta[7];

class Aerodromo
{
public:
    bool estacionar_avioneta(avioneta a); // Devuelve si se ha estacionado correctamente
    void sacar_avioneta(avioneta a);
    Cola<avioneta> avionetas;
    Cola<avioneta> espera;
};

#endif