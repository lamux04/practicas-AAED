#ifndef HOSPITAL
#define HOSPITAL

struct paciente
{
    std::string cod;
    unsigned short gravedad;
    paciente(std::string c = "", unsigned short g = 0) : cod(c), gravedad(g) {}
};

class Hospital
{
public:
    Hospital(size_t tam_uci, size_t tam_planta);
    void ingreso(paciente pac);
    void alta(std::string cod_pac);
    void muerte(std::string cod_pac);
    ListaSimple<paciente> pacientes_UCI();
    ListaSimple<paciente> pacientes_planta();
    ListaSimple<paciente> pacientes_gravedad(unsigned short gravedad);
    void imprimir();

private:
    ListaSimple<paciente> luci, lplanta;
    size_t max_uci, max_planta;
    void ingresar_planta(paciente pac);
};

ListaSimple<paciente>::posicion buscar_menos_grave(const ListaSimple<paciente> &lis);
ListaSimple<paciente>::posicion buscar_mas_grave(const ListaSimple<paciente> &lis);
ListaSimple<paciente>::posicion buscar_paciente(const ListaSimple<paciente> &lis, std::string cod);
void prueba_hospital();

#endif