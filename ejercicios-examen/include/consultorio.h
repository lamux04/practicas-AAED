#ifndef CONSULTORIO
#define CONSULTORIO

typedef std::string paciente;

struct medico
{
    std::string cod;
    ColaDinamica<paciente> espera;
    medico(std::string codigo = "") : cod(codigo) {}
};

class Consultorio
{
public:
    void alta(std::string cod_med);                             // Da de alta a un medico
    void baja(std::string cod_med);                             // Da de baja a un medico, si no existe, no hace nada
    void paciente_en_espera(std::string cod_med, paciente pac); // Pre: El medico debe existir. Post: Añade un paciente a la cola de espera de un medico.
    paciente turno_paciente(std::string cod_med) const;         // Pre: El medico debe existir. Post: Devuelve el paciente al que le toca el turno de un medico.
    void atender_paciente(std::string cod_med);                 // Pre: El medico debe existir. Post: Atiende al paciente al que le toque del medico indicado. Si el medico no tiene pacientes no hace nada
    bool pacientes_espera(std::string cod_med) const;           // Devuelve true si el medico tiene pacientes en espera y false si no lo tiene o el medico no existe.
    void imprimir();

private:
    ListaSimple<medico> lista_medicos;
    ListaSimple<medico>::posicion buscar(std::string cod_med) const; // Post: Devuelve la posicion del medico o fin si no existe
};

void prueba_consultorio();

#endif