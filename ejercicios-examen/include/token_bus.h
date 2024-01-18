#ifndef TOKEN_BUS
#define TOKEN_BUS

struct maquina
{
    std::string id, ultima_trama;
    maquina(std::string i = "", std::string tr = "") : id(i), ultima_trama(tr) {}
};
typedef std::string trama;

class TokenBus
{
public:
    TokenBus(std::string primero);                                            // Constructor, inicializa la red con el primer computador y le da el token al computador.
    void nuevo_computador(std::string nueva);                                 // Añade una nueva máquina a la red al final.
    void eliminar_computador();                                               // Pre: Debe haber computadoras en la red. Post: Elimina el computador que entro primero. Si este tenía el token, lo pasa al siguiente.
    void pasar_token();                                                       // Pre: Debe haber computadoras en la red. Post: Pasa el token al siguiente de la lista.
    maquina ver_token();                                                      // Pre: Debe haber computadoras en la red. Post: Devuelve la máquina que tiene el token.
    bool enviar_trama(std::string maquinaA, std::string maquinaB, trama tra); // Post: Devuelve true si A tiene el token y B existe para poder enviarle la trama
    void imprimir();

private:
    ListaSimple<maquina>::posicion token;
    ListaSimple<maquina> lmaquina;
};

void prueba_token_bus();

#endif