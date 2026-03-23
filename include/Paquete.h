#ifndef PAQUETE_H
#define PAQUETE_H
#include <string>

class Paquete {
public:
    std::string id;
    std::string destino;
    bool urgente;
    Paquete* siguiente;

    Paquete(std::string id, std::string destino, bool urgente);
};
#endif
