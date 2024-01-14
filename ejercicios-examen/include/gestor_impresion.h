#ifndef GESTOR_IMPRESION
#define GESTOR_IMPRESION

typedef std::string trabajo;

typedef std::string nombre_usuario;

class Gestor_impresion
{
public:
    Gestor_impresion(unsigned n);                                        // Pre: n > 0. Post: Crea un gestor de impresion para n usuarios.
    void nuevo_trabajo(trabajo trab, bool urgente, nombre_usuario user); // Post: Si user exite, le añade trab. Sino, crea user y le añade trab.
    void eliminar_trabajo();                                             // Post: Elimina el trabajo que le tocaba imprimirse (si es necesario elimina al usuario tambien) y avanza el turno al siguiente usuario.
    void cancelar_trabajos(nombre_usuario user);                         // Post: Si exite user, lo elimina.
private:
};

#endif