#ifndef PILAS_OPER
#define PILAS_OPER

// cabecera: bool Y_inverso_X(string cad)
// precondicion: cad inicializado y sólo puede contener un único &
// postcondicion: devuelve true si cad es de la forma X&Y siendo X una cadena y Y su inversa
bool Y_inverso_X(char[]);

// cabecera: bool AsostenidoB(string cad)
// precondicion: cad inicializado
// postcondicion: devuelve true si cad es de la forma A#B#C#D y A,B,C,D... es de la formaX&Y siendo X una cadena y Y su inversa
bool A_sostenido_B(char[]);

// cabecera: void invertir_secuencia(Pila<char> A, int a, int b)
// precondicion: ninguna
// postcondicion: invierteee la secuencia delitada por la primera ocurrencia de a y la de b
void invertir_secuencia(Pila<int>& A, int a, int b);

#endif