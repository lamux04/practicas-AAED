#ifndef CUBILETE
#define CUBILETE

struct tCubo
{
    int tamano;
    bool boca_abajo;
    tCubo(int tam = 0, bool boca_aba = true) : tamano(tam), boca_abajo(boca_aba) {}
};

typedef PilaVectorial<tCubo> PilaCubiletes;

// pre: ninguna
// post: ordena cubiletes segun su tamaño y boca abajo
PilaCubiletes ordenar_cubiletes(PilaCubiletes &cubiletes);

void prueba_cubiletes();

#endif