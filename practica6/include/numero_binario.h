#ifndef NUMERO_BINARIO
#define NUMERO_BINARIO

class Binario
{
    public:
        Binario(std::string cad);
        friend Binario operator~(const Binario &A);
        friend Binario operator&(const Binario &A, const Binario &B);
        friend Binario operator|(const Binario &A, const Binario &B);
        friend Binario operator^(const Binario &A, const Binario &B);
        friend Binario operator<<(const Binario &A, unsigned n);
        friend Binario operator>>(const Binario &A, unsigned n);
        void imprimir() const;

    private:
        ListaDinamica<bool> lista;
};

#endif