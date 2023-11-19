#ifndef _RACIONAL_
#define _RACIONAL_
#include <cassert>
class racional
{
public:
    typedef long long entero;
    racional(entero nu = 0, entero de = 1);
    entero num() const { return n; }
    entero den() const { return d; }
    // Declaración de operadores aritméticos no miembros
    friend racional operator+(const racional &r, const racional &s);
    friend racional operator*(const racional &r, const racional &s);
    friend racional operator-(const racional &r);
    friend racional inv(const racional &r);

private:
    entero n, d;
    static entero mcd(entero, entero);
    static entero mcm(entero, entero);
};

//========================================
// Implementación de operaciones en línea
// Operadores aritméticos no miembros
inline racional operator-(const racional &r)
{
    return racional(-r.n, r.d);
}
inline racional inv(const racional &r)
{
    assert(r.n != 0); // Vericar precondición
    return racional(r.d, r.n);
}
// Operadores de comparación no miembros
inline bool operator==(const racional &r, const racional &s)
{
    return (r.num() == s.num()) && (r.den() == s.den());
}
inline bool operator<(const racional &r, const racional &s)
{
    return (r + -s).num() < 0;
}

// Método privado
inline racional::entero racional::mcm(entero x, entero y)
// Devuelve mcm(|x|, |y|). Devuelve 0 si x o y valen 0.
{
    return (x && y) ? (x < 0 ? -x : x) / mcd(x, y) * (y < 0 ? -y : y) : 0;
}
#endif // _RACIONAL