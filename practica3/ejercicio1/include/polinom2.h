#ifndef POLINOM_2
#define POLINOM_2

class polinomio {
  public:
    explicit polinomio(unsigned tamMax);
    unsigned grado();
    double coeficiente(unsigned n);
    void coeficiente(unsigned n, double c);
    // polinomio(const polinomio &P);
    // polinomio &operator=(const polinomio &P);
    // ~polinomio();
  private:
    unsigned gradoMax;
    unsigned grado_pol;
    double v[21];
};

#endif