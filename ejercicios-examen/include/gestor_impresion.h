#ifndef GESTOR_IMPRESION
#define GESTOR_IMPRESION

typedef std::string cod_trabajo;

struct trabajo
{
    cod_trabajo cod;
    bool urgente;
    trabajo(cod_trabajo c = "", bool u = false) : cod(c), urgente(u) {}
};

class GestorImpresion
{
public:
    GestorImpresion(size_t n);                                       
    void nuevo_trabajo(int id, trabajo tra); 
    void eliminar_trabajo();
    void cancelar_trabajos(int id);
    GestorImpresion(const GestorImpresion &P);
    GestorImpresion &operator=(const GestorImpresion &P);
    ~GestorImpresion();
    void imprimir();

private:
    struct usuario
    {
        ColaDinamica<cod_trabajo> c_no_urgente;
        ColaDinamica<cod_trabajo> c_urgente;
    };
    usuario *v_usuarios;
    size_t n;
    ColaVec<int> turnos;
};

void prueba_gestor_impresion();

#endif