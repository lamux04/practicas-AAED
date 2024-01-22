#include <string>
#include <iostream>
#include <vector>
#include "pila_dinamica.h"
#include "postfijo.h"

int buscar_variable(char var, const std::vector<variable> &v_variables);

int evaluar_expresion(std::string expresion, const std::vector<variable>& v_variables)
{
    PilaDinamica<int> A;
    int i, operando1, operando2;

    for (i = 0; expresion[i] != '\0'; ++i)
    {
        if (expresion[i] == '+' || expresion[i] == '*' || expresion[i] == '-' || expresion[i] == '*')
        {
            operando2 = A.tope();
            A.pop();
            operando1 = A.tope();
            A.pop();
        }
        switch (expresion[i])
        {
            case '+':
                A.push(operando1 + operando2);
                break;
            case '-':
                A.push(operando1 - operando2);
                break;
            case '*':
                A.push(operando1 * operando2);
                break;
            case '/':
                A.push(operando1 / operando2);
                break;
            default:
                A.push(buscar_variable(expresion[i], v_variables));
                break;
        }
    }
    return A.tope();
}

int buscar_variable(char var, const std::vector<variable>& v_variables)
{
    int i = 0;

    while (i < v_variables.size() && var != v_variables[i].nombre)
    {
        ++i;
    }

    if (i < v_variables.size())
        return v_variables[i].valor;
    return 0;
}

void prueba_postfijo()
{
    using namespace std;
    vector<variable> v_variables({variable('A', 2), variable('B', 3), variable('C', 1), variable('D', 2)});
    cout << evaluar_expresion("AB+CD+*", v_variables);
}