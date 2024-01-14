#ifndef DICCIONARIO
#define DICCIONARIO

class Diccionario
{
public:
    void insertar_traduccion(std::string pal_ingles, std::string pal_es);
    void eliminar_traduccion(std::string pal_ingles, std::string pal_es);
    bool consultar_traduccion(std::string pal_ingles, std::string pal_es) const;
    ListaSimple<std::string> consultar_todos(std::string pal_ingles) const;
    void imprimir();

private:
    struct traduccion
    {
        std::string ingles;
        ListaSimple<std::string> lespanol;
    };
    ListaSimple<traduccion> lista;

    ListaSimple<traduccion>::posicion buscar_ingles(std::string pal_ingles) const;
    ListaSimple<std::string>::posicion buscar_es(const traduccion &trad, std::string pal_es) const;
};

void prueba_diccionario();

#endif