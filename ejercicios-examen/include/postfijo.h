#ifndef POSTFIJO
#define POSTFIJO

struct variable
{
    char nombre;
    int valor;
    variable(char n = '\0', int v = 0) : nombre(n), valor(v) {}
};

void prueba_postfijo();
int evaluar_expresion(std::string expresion, const std::vector<variable> &v_variables);

#endif