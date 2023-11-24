#include <iostream>
#include <string>
#include "pila-dinamica.h"
#include "pilas-oper.h"

bool Y_inverso_X(char cad[])
{
    Pila<char> X;
    char caracter = cad[0];
    unsigned int i = 0;
    bool encontrado = false, resultado = true;

    while (caracter != '\0' && resultado)
    {
        if (caracter == '&')
            encontrado = true;
        else
        {
            if (!encontrado)
                X.push(caracter);
            else
            {
                if (X.tope() != cad[i])
                    resultado = false;
                X.pop();
            }
        }
        i++;
        caracter = cad[i];
    }

    if (!X.vacia() || !encontrado)
        resultado = false;
    return resultado;
}

bool A_sostenido_B (char cad[]) {
    bool resultado = true;
    int i = 0, j = 0;
    int elem = 0;

    while (cad[elem] != '\0')
        elem++;
    
    char *A = new char[elem];

    while (cad[i] != '\0' && resultado) 
    {
        if (cad[i] != '#')
        {
            A[j] = cad[i];
            j++;
        } else
        {
            A[j] = '\0';
            resultado = Y_inverso_X(A);
            j = 0;
        }
        i++;
    }

    if (i == j)
        resultado = false;

    return resultado;
}

void invertir_secuencia (Pila<int>& A, int a, int b) {
    Pila<int> B;
    Pila<int> C;
    bool b_encontrado = false;
    while (!A.vacia() && A.tope() != a)
    {
        B.push(A.tope());
        A.pop();
    }
    while (!A.vacia() && A.tope() != b)
    {
        C.push(A.tope());
        A.pop();
    }
    if (!A.vacia()) 
    {
        C.push(A.tope());
        A.pop();
        b_encontrado = true;
    }
    if (b_encontrado)
        while (!C.vacia())
        {
            B.push(C.tope());
            C.pop();
        }
    else
        while (!C.vacia())
        {
            A.push(C.tope());
            C.pop();
        }
    while (!B.vacia())
    {
        A.push(B.tope());
        B.pop();
    }
}