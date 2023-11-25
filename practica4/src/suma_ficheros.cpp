#include <fstream>
#include <string>
#include "pila-dinamica.h"
#include "suma_ficheros.h"
#include "in_out_pila.h"

// Apila en P los valores númericos de los dígitos
// extraídos del flujo de entrada fe
std::fstream& operator >>(std::fstream& fe, Pila<int>& P)
{
    char cifra ;
    while (fe.get( cifra ) && cifra != '\n') // leer caracteres hasta fin de línea
    P.push(cifra -= '0'); // convierte un dígito en su valor numérico
    return fe;
}

// Inserta en el flujo de salida fs la pila P
std::fstream& operator <<(std::fstream& fs, Pila<int> P)
{
    using namespace std;
    while (!P.vacia())
    {
        fs << P.tope();
        P.pop();
    }
    fs << endl;
    return fs;
}

void suma(std::string path) {
    using namespace std;
    fstream f(path);
    Pila<int> P, Q, R;
    int acarreo = 0;

    f >> P >> Q; // Extraer de f los numeros P y Q

    // Calculamos el resultado
    while (!P.vacia() || !Q.vacia())
    {
        if (P.vacia())
        {
            R.push((Q.tope() + acarreo) % 10);
            acarreo = (Q.tope() + acarreo) / 10;
            Q.pop();
        } else if (Q.vacia())
        {
            R.push((P.tope() + acarreo) % 10);
            acarreo = (P.tope() + acarreo) / 10;
            P.pop();
        } else
        {
            R.push((P.tope() + Q.tope() + acarreo) % 10);
            acarreo = (P.tope() + Q.tope() + acarreo) / 10;
            P.pop();
            Q.pop();
        }
    }
    if (acarreo > 0)
        R.push(acarreo);
    imprimir_pila_tope_izquierda(R);

    f << R;
    f.close();
}