#ifndef RUTA_H
#define RUTA_H
#include "Ciudad.h"
#include <string>

class Ruta {
private:
    Ciudad* cabeza;
public:
    Ruta();
    ~Ruta();
    void agregarCiudad(std::string nombre);
    void eliminarCiudad(std::string nombre);
    void mostrarRuta();
};
#endif
